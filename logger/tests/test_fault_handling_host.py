"""Exercise firmware fault transitions with hardware replaced by host fakes.

Methods and controller blocks are extracted from the working firmware at build
time, so these tests execute its decisions rather than a parallel Python model.
The target build separately checks their real types and call sites.
"""
from pathlib import Path
import subprocess
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[2]


def block(source, marker):
    start = source.index(marker)
    opening = source.index("{", start)
    depth = 1
    end = opening + 1
    while depth:
        depth += (source[end] == "{") - (source[end] == "}")
        end += 1
    return source[start:end]


class FaultHandlingTests(unittest.TestCase):
    def test_kickdown_launch_and_landing_selection(self):
        source = (ROOT / "src/gearbox.cpp").read_text()
        method = block(source, "GearboxGear Gearbox::kickdown_target(")
        self.compile_and_run(r'''
#include <cmath>
#include <cassert>
#include <cstdint>
enum class GearboxGear { First=1, Second, Third, Fourth, Fifth };
struct AbstractProfile {};
GearboxGear prev_gear(GearboxGear g) { return static_cast<GearboxGear>(static_cast<int>(g)-1); }
bool is_fwd_gear(GearboxGear g) { return g>=GearboxGear::First && g<=GearboxGear::Fifth; }
float ratio_absolute(GearboxGear g, int*) {
 const float ratios[] = {0, 3.932f, 2.408f, 1.486f, 1, .83f};
 return ratios[static_cast<int>(g)];
}
struct Gearbox {
 GearboxGear actual_gear=GearboxGear::Second;
 int redline_rpm=4500, gearboxConfig=0;
 struct { int input_rpm=241, output_rpm=100; } sensor_data;
 bool reserve=true;
 bool downshift_has_reserve(AbstractProfile*, GearboxGear) { return reserve; }
 GearboxGear kickdown_target(AbstractProfile*);
};
''' + method + r'''
int main() {
 Gearbox g; AbstractProfile p;
 assert(g.kickdown_target(&p)==GearboxGear::First);
 g.sensor_data.output_rpm=0;
 assert(g.kickdown_target(&p)==GearboxGear::First);
 g.actual_gear=GearboxGear::First;
 assert(g.kickdown_target(&p)==GearboxGear::First);
 g.actual_gear=GearboxGear::Third;
 assert(g.kickdown_target(&p)==GearboxGear::Second); // Adjacent request only.
 assert(g.kickdown_target(nullptr)==GearboxGear::Third);
 g.sensor_data.output_rpm=1000; g.sensor_data.input_rpm=1486;
 assert(g.kickdown_target(&p)==GearboxGear::First);
 g.reserve=false;
 assert(g.kickdown_target(&p)==GearboxGear::Third); // Moving RPM reserve retained.
}
''')

    def test_shift_time_adaptation_reports_applied_delta(self):
        source = (ROOT / "src/adaptation/shift_adaptation.cpp").read_text()
        methods = "\n".join(block(source, marker) for marker in (
            "static int16_t clamp_i16(",
            "int16_t ShiftAdaptationSystem::offset_shift_time("))
        self.compile_and_run(r'''
#include <algorithm>
#include <cassert>
#include <cstdint>
#define MAX(a,b) std::max(a,b)
#define MIN(a,b) std::min(a,b)
#define ESP_LOGI(...) ((void)0)
struct { uint16_t quality_time_max_offset_ms=250; } ADP_CURRENT_SETTINGS;
struct StoredMap { int16_t data[8]={}; int16_t* get_current_data() { return data; } } map;
struct ShiftAdaptationSystem {
 StoredMap* shift_time_offset_map=&map;
 int16_t offset_shift_time(uint8_t, int16_t);
};
''' + methods + r'''
int main() {
 ShiftAdaptationSystem adapter;
 assert(adapter.offset_shift_time(0,25)==25 && map.data[0]==25);
 map.data[0]=240;
 assert(adapter.offset_shift_time(0,25)==10 && map.data[0]==250);
 assert(adapter.offset_shift_time(0,25)==0 && map.data[0]==250);
 assert(adapter.offset_shift_time(0,-25)==-25 && map.data[0]==225);
 map.data[0]=-240;
 assert(adapter.offset_shift_time(0,-25)==-10 && map.data[0]==-250);
 assert(adapter.offset_shift_time(0,-25)==0 && map.data[0]==-250);
 assert(adapter.offset_shift_time(0,25)==25 && map.data[0]==-225);
 adapter.shift_time_offset_map=nullptr;
 assert(adapter.offset_shift_time(0,25)==0);
}
''')

    def compile_and_run(self, source):
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp)
            (path / "test.cpp").write_text(source)
            result = subprocess.run(
                ["g++", "-std=c++17", "-Wall", "-Wextra", "-Werror",
                 str(path / "test.cpp"), "-o", str(path / "test")],
                capture_output=True, text=True)
            self.assertEqual(result.returncode, 0, result.stderr)
            result = subprocess.run([str(path / "test")], capture_output=True, text=True)
            self.assertEqual(result.returncode, 0, result.stderr)

    def test_gear_engine_and_driver_intent_recovery(self):
        source = (ROOT / "src/gearbox.cpp").read_text()
        methods = "\n".join(block(source, marker) for marker in (
            "void Gearbox::cancel_garage_shift()",
            "void Gearbox::update_engine_state(",
            "bool Gearbox::process_speed_sensors()",
            "bool Gearbox::calcGearFromRatio(",
            "uint8_t Gearbox::agility_demand(",
            "void Gearbox::update_agility_score(",
            "void Gearbox::set_torque_request("))
        completion = block(source, "if (result) { // Only set gear")
        verification = block(source, "if (!shifting && sensor_data.output_rpm > 100)")
        fallback = source[source.index("        else {\n            // Loss of engine RPM"):]
        fallback = block(fallback, "else {").removeprefix("else ")
        self.compile_and_run(r'''
#include <algorithm>
#include <atomic>
#include <cassert>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#define MAX(a,b) std::max(a,b)
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ESP_LOGW(...) ((void)0)
#define DEMAND_PEDAL_RISE 62u
#define AGILITY_DECEL_RPM_S 900
#define AGILITY_DECAY_PER_S 4
uint32_t now = 100;
#define GET_CLOCK_TIME() ::now
// Only hardware and storage are faked; decisions below are the firmware's code.
enum class GearboxGear { Park, First, Second, Third, Fourth, Fifth, Neutral, SignalNotAvailable };
enum class ShifterPosition { P, N, D, R };
enum class GearChange { _IDLE, _1_2 };
enum class TorqueRequestControlType { None, Active };
enum class TorqueRequestBounds { LessThan };
enum class TccClutchStatus { Open };
enum class ShiftCircuit { sc_1_2, sc_2_3, sc_3_4 };
bool is_fwd_gear(GearboxGear g) { return g >= GearboxGear::First && g <= GearboxGear::Fifth; }
GearboxGear gear_from_idx(uint8_t i) { return static_cast<GearboxGear>(i); }
struct Solenoid {
 int current=100, duty=100;
 void set_current_target(int x) { current=x; }
 void set_duty(int x) { duty=x; }
} mpc, spc, tcc_sol;
auto sol_mpc=&mpc; auto sol_spc=&spc; auto sol_tcc=&tcc_sol;
struct PM {
 int tcc_pressure=100;
 void set_target_tcc_pressure(int p) { tcc_pressure=p; }
 void set_shift_circuit(ShiftCircuit, bool) {}
};
struct TCC { void reset() {} };
struct CAN {
 TorqueRequestControlType request=TorqueRequestControlType::None;
 void set_torque_request(TorqueRequestControlType t, TorqueRequestBounds, float) { request=t; }
 void set_clutch_status(TccClutchStatus) {}
} can;
auto egs_can_hal = &can;
namespace TCUIO {
 uint16_t n2=2408, n3=0, out=1000;
 uint16_t n2_rpm() { return n2; }
 uint16_t n3_rpm() { return n3; }
 uint16_t output_rpm() { return out; }
 uint16_t calc_turbine_rpm(uint16_t a,uint16_t b) { return std::max(0.0f,a*(3932.0f/2408)+(b-(3932.0f/2408)*b)); }
}
struct Algo { bool timeout; bool did_time_out() { return timeout; } };
struct Gearbox {
 GearboxGear actual_gear=GearboxGear::First, target_gear=GearboxGear::Second;
 GearboxGear last_motion_gear=actual_gear, last_fwd_gear=actual_gear;
 ShifterPosition shifter_pos=ShifterPosition::D;
 bool shifting=false, engine_rpm_valid=false, agility_inputs_valid=false;
 bool ask_upshift=false, ask_downshift=false, manual_shift=false;
 std::atomic<bool> engine_running{false};
 int gear_disagree_count=0;
 uint8_t est_gear_idx=0, engine_rpm_missing_cycles=0, agility_score=0;
 uint8_t pedal_history[5]={0};
 uint32_t last_score_ms=0;
 uint16_t last_out_rpm=0, agility_decay_ms=0;
 int16_t decel_rpm_s=0;
 struct { GearChange change=GearChange::_1_2; } shift_ctx;
 struct { uint16_t input_rpm=0, output_rpm=0, engine_rpm=0;
          uint8_t pedal_pos=0; bool kickdown_pressed=false; } sensor_data;
 struct { uint16_t n2=0,n3=0,turbine=0,output=1000; } speed_sensors;
 struct GearRatioInfo { float ratio_min_drift,ratio_max_drift; };
 struct { GearRatioInfo bounds[7]={{3.5,4.3},{2.2,2.6},{1.3,1.6},{.91,1.1},{.75,.9},{-3.4,-2.8},{-2.1,-1.7}}; } gearboxConfig;
 struct { float torque_req_amount=0; TorqueRequestControlType ctrl_type=TorqueRequestControlType::None;
          TorqueRequestBounds bounds=TorqueRequestBounds::LessThan; } output_data;
 PM pm; TCC converter; PM* pressure_mgr=&pm; TCC* tcc=&converter;
 void cancel_garage_shift(); void update_engine_state(uint16_t);
 bool process_speed_sensors(); bool calcGearFromRatio(bool);
 uint8_t agility_demand(); void update_agility_score();
 void set_torque_request(TorqueRequestControlType,TorqueRequestBounds,float);
 void complete(bool timeout) {
  Algo algorithm{timeout}; auto algo=&algorithm;
  struct { uint8_t curr_g=1,targ_g=2; } sd;
  bool result=true;
''' + completion + r'''
 }
 void poll() {
  if (process_speed_sensors()) {
   sensor_data.input_rpm=speed_sensors.turbine; sensor_data.output_rpm=speed_sensors.output;
''' + verification + r'''
  }
 }
 void engine_fallback(bool speeds_valid)
''' + fallback + r'''
};
''' + methods + r'''
int main() {
 // Failed D/R engagements do not leave a request that respawns the task.
 for (auto selector : {ShifterPosition::D,ShifterPosition::R,ShifterPosition::N,ShifterPosition::P}) {
  Gearbox g; g.shifter_pos=selector; g.cancel_garage_shift();
  assert(g.target_gear==g.actual_gear);
  assert(g.target_gear==(selector==ShifterPosition::P ? GearboxGear::Park : GearboxGear::Neutral));
 }
 // Timed-out 1-2, physically still in first: sane raw data can recover the gear.
 Gearbox g; g.complete(true);
 assert(g.gear_disagree_count!=0 && g.shift_ctx.change==GearChange::_IDLE);
 for (int i=0;i<51;++i) g.poll();
 assert(g.actual_gear==GearboxGear::First && g.target_gear==g.actual_gear && g.gear_disagree_count==0);
 // Successful 1-2 retains the N2/N3 sanity check; missing readings never pass.
 g.target_gear=GearboxGear::Second; g.complete(false); assert(!g.process_speed_sensors());
 g.gear_disagree_count=1;
 TCUIO::n2=UINT16_MAX; assert(!g.process_speed_sensors());
 TCUIO::n2=2408; TCUIO::n3=UINT16_MAX; assert(!g.process_speed_sensors());
 TCUIO::n3=0; TCUIO::out=UINT16_MAX; assert(!g.process_speed_sensors()); TCUIO::out=1000;
 // Timed-out shift that DID engage verifies immediately from matching raw RPM.
 TCUIO::n2=TCUIO::n3=2408; g.complete(true); g.poll();
 assert(g.actual_gear==GearboxGear::Second && g.gear_disagree_count==0);
 // CAN expiry with a turning turbine must clear running, without inventing N.
 g.sensor_data.input_rpm=200; g.update_engine_state(800);
 for(int i=0;i<10;++i) { g.update_engine_state(UINT16_MAX); assert(g.engine_running); }
 g.update_engine_state(UINT16_MAX); assert(!g.engine_running && !g.engine_rpm_valid);
 assert(g.actual_gear==GearboxGear::Second);
 g.set_torque_request(TorqueRequestControlType::Active,TorqueRequestBounds::LessThan,120);
 assert(can.request==TorqueRequestControlType::None);
 g.engine_fallback(true);
 assert(mpc.current==100 && spc.current==100 && tcc_sol.duty==0);
 // Even zero turbine/output on a missing signal does not establish engine stop.
 g.sensor_data.input_rpm=g.sensor_data.output_rpm=0; g.engine_fallback(true);
 assert(mpc.current==100 && spc.current==100);
 g.update_engine_state(900); assert(g.engine_running && g.engine_rpm_missing_cycles==0);
 g.set_torque_request(TorqueRequestControlType::Active,TorqueRequestBounds::LessThan,120);
 assert(can.request==TorqueRequestControlType::Active);
 // Fresh zero clears the latch; shut off only with valid stationary speed data.
 g.update_engine_state(0); assert(!g.engine_running && g.engine_rpm_valid);
 g.engine_fallback(false); assert(mpc.current==100);
 g.sensor_data.output_rpm=1000; g.engine_fallback(true); assert(mpc.current==100);
 g.sensor_data.output_rpm=0; g.engine_fallback(true); assert(mpc.current==0 && spc.current==0);
 // Invalid readings cannot raise the score; recovery cannot synthesize a stab.
 g.agility_score=20; g.sensor_data.pedal_pos=250; g.sensor_data.kickdown_pressed=true;
 g.update_agility_score(); assert(g.agility_score==20 && g.agility_demand()==0);
 g.agility_inputs_valid=true; g.sensor_data.kickdown_pressed=false; g.sensor_data.pedal_pos=100;
 g.sensor_data.output_rpm=1000; g.update_agility_score();
 now+=100; g.update_agility_score(); assert(g.agility_score<=20 && g.decel_rpm_s==0);
 // A real pedal rise still requests agility immediately; gentle driving decays.
 g.sensor_data.pedal_pos=200; now+=100; g.update_agility_score(); assert(g.agility_score==100);
 g.sensor_data.pedal_pos=0;
 for(int i=0;i<10;++i) { now+=100; g.update_agility_score(); }
 assert(g.agility_score==96);
 g.agility_inputs_valid=false; g.update_agility_score();
 now+=10000; g.sensor_data.output_rpm=200; g.agility_inputs_valid=true; g.update_agility_score();
 assert(g.decel_rpm_s==0 && g.agility_score==96);
}
''')

    def test_sensor_initialization_error_propagation(self):
        source = (ROOT / "src/tcu_io/tcu_io.cpp").read_text()
        # Compile the real IO setup and its initializer helpers with fault injection.
        setup = block(source, "esp_err_t TCUIO::setup_io_layer()")
        helpers = block(source, "void init_smoothed_sensor(") + "\n" + block(source, "template <typename T>\nvoid init_onepoll(")
        self.compile_and_run(r'''
#include <cassert>
#include <cstdint>
using esp_err_t=int;
constexpr int ESP_OK=0,ESP_ERR_INVALID_STATE=1;
namespace TCUIO {
 struct SmoothedSensor { uint8_t e_counter=99,sample_count=0; int last_value=0; };
 template<class T> struct OnePollSensor { uint8_t e_counter=0; T current_value=0; };
 esp_err_t setup_io_layer();
}
namespace Sensors { int result=0,calls=0; int init_sensors() { ++calls; return result; } }
int dummy; int* egs_can_hal=&dummy;
struct { int diff_ratio=3000; } VEHICLE_CONFIG;
float DIFF_RATIO_F=1;
TCUIO::SmoothedSensor smoothed_sensor_n2_rpm,smoothed_sensor_n3_rpm,smoothed_sensor_out_rpm,
 smoothed_sensor_atf_temp,smoothed_sensor_vbatt;
TCUIO::OnePollSensor<uint16_t> onepoll_fl_speed,onepoll_fr_speed,onepoll_rl_speed,onepoll_rr_speed;
TCUIO::OnePollSensor<uint8_t> onepoll_parking_lock;
TCUIO::OnePollSensor<int16_t> onepoll_motor_temperature,onepoll_motor_oil_temperature;
''' + helpers + setup + r'''
int main() {
 egs_can_hal=nullptr;
 assert(TCUIO::setup_io_layer()==ESP_ERR_INVALID_STATE && Sensors::calls==0);
 egs_can_hal=&dummy;
 for(int failure=2;failure<=5;++failure) {
  Sensors::result=failure;
  assert(TCUIO::setup_io_layer()==failure);
  assert(smoothed_sensor_n2_rpm.e_counter==99);
 }
 Sensors::result=ESP_OK;
 assert(TCUIO::setup_io_layer()==ESP_OK);
 assert(smoothed_sensor_n2_rpm.e_counter==0 && DIFF_RATIO_F==3);
}
''')
