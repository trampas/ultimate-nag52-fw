#pragma once
#include "plant.h"
#include <chrono>
#include <deque>
#include <map>
#include <stdexcept>

// Included by the replay harness after its firmware globals and host services.
// This adapter models one adjacent forward shift; it does not run gearbox.cpp's
// scheduler, garage shifts, or the production TCC controller.
static int run_closed_loop_shift(int argc, char** argv) {
    using namespace Nag52Plant;
    try {
        if (argc<3) throw std::invalid_argument("usage: sim_new --plant output.csv key=value ...");
        std::map<std::string,double> cfg={
            {"change",2},{"speed_kph",35},{"torque_nm",120},{"pedal",100},{"atf_c",60},
            {"time_ms",700},{"feedback_guard",1},{"dt_ms",1},{"seconds",8},{"shift_at_s",1},
            {"tipin_s",1000},{"torque_after_nm",120},{"pedal_after",100},
            {"mass_kg",1800},{"grade_percent",0},{"brake_force_n",0},{"capacity_scale",1},
            {"pressure_tau_s",.04},{"fill_s",.12},{"converter_damping",8},{"engine_lag_s",.12},
            {"engine_inertia",.25},{"turbine_inertia",.16},{"output_inertia",.5},
            {"wheel_radius_m",1.975/(2*pi)},{"final_drive",3.07},{"rolling_coefficient",.012},{"cda_m2",.62}};
        for(int i=3;i<argc;++i) {
            std::string arg=argv[i]; auto pos=arg.find('=');
            if(pos==std::string::npos || !cfg.count(arg.substr(0,pos))) throw std::invalid_argument("unknown scenario parameter: "+arg);
            size_t consumed=0; std::string val=arg.substr(pos+1); double v=std::stod(val,&consumed);
            if(consumed!=val.size() || !std::isfinite(v)) throw std::invalid_argument("invalid scenario value: "+arg);
            cfg[arg.substr(0,pos)]=v;
        }
        const int change=(int)cfg["change"];
        const int dt_us=(int)std::llround(cfg["dt_ms"]*1000);
        if(change<1 || change>8 || cfg["change"]!=change || dt_us<100 || dt_us>5000 || 20000%dt_us ||
            std::abs(dt_us-cfg["dt_ms"]*1000)>1e-7 || cfg["seconds"]<=cfg["shift_at_s"] || cfg["seconds"]>60 ||
            cfg["shift_at_s"]<.1 || std::abs(cfg["shift_at_s"]*50-std::round(cfg["shift_at_s"]*50))>1e-7 ||
            cfg["speed_kph"]<=0 || cfg["speed_kph"]>200 || cfg["time_ms"]<100 || cfg["time_ms"]>2500 ||
            cfg["pedal"]<0 || cfg["pedal"]>250 || cfg["pedal_after"]<0 || cfg["pedal_after"]>250 ||
            cfg["atf_c"]<-40 || cfg["atf_c"]>130 || std::abs(cfg["torque_nm"])>500 ||
            std::abs(cfg["torque_after_nm"])>500 || cfg["tipin_s"]<0 ||
            (cfg["feedback_guard"]!=0 && cfg["feedback_guard"]!=1)) throw std::invalid_argument("scenario outside supported range");
        Parameters par;
        par.mass_kg=cfg["mass_kg"];par.grade_percent=cfg["grade_percent"];par.brake_force_n=cfg["brake_force_n"];
        par.capacity_scale=cfg["capacity_scale"];par.pressure_tau_s=cfg["pressure_tau_s"];par.fill_s=cfg["fill_s"];
        par.converter_damping=cfg["converter_damping"];par.engine_lag_s=cfg["engine_lag_s"];
        par.engine_inertia=cfg["engine_inertia"];par.turbine_inertia=cfg["turbine_inertia"];par.output_inertia=cfg["output_inertia"];
        par.wheel_radius_m=cfg["wheel_radius_m"];par.final_drive=cfg["final_drive"];
        par.rolling_coefficient=cfg["rolling_coefficient"];par.cda_m2=cfg["cda_m2"];par.validate();
        memset(&VEHICLE_CONFIG,0,sizeof(VEHICLE_CONFIG));
        VEHICLE_CONFIG.diff_ratio=(uint16_t)(par.final_drive*1000);
        VEHICLE_CONFIG.wheel_circumference=(uint16_t)(par.wheel_radius_m*2*pi*1000);
        VEHICLE_CONFIG.red_line_rpm_diesel=4500;VEHICLE_CONFIG.engine_drag_torque=540;
        SBS_CURRENT_SETTINGS.feedback_guard=cfg["feedback_guard"]!=0;
        // Freeze learning for paired runs; feedforward offsets are seeded defaults.
        ADP_CURRENT_SETTINGS.quality_adapt=true;
        const bool up=change<=4;
        const int from=up?change:change-3, to=up?from+1:from-1;
        GearChange req=(GearChange)change;
        GearboxGear actual=gear_from_idx(from),target=gear_from_idx(to);
        SensorData sd={};sd.atf_temp=(int16_t)cfg["atf_c"];
        standard=new AbstractProfile(0,S_UPSHIFT_TIME_MAP,S_DOWNSHIFT_TIME_MAP);
        manual=new AbstractProfile(4,nullptr,nullptr);race=new AbstractProfile(5,nullptr,nullptr);
        auto pm=new PressureManager(&sd,330);pressure_manager=pm;
        auto adapter=new ShiftAdaptationSystem();auto tcc=new TorqueConverter();
        CircuitInfo info=pm->get_basic_shift_data(req);info.map_idx=change-1;
        const ::Clutch applying=get_clutch_to_apply(req),releasing=get_clutch_to_release(req);
        GearRatioInfo ratios[7];
        for(int i=0;i<7;++i) {double r=MECH_PTR->ratio_table[i+1]/1000.;ratios[i]={(float)(r*1.1),(float)r,(float)(r*.9)};}
        Model plant(par,ratios[from-1].ratio,ratios[to-1].ratio);
        plant.off.spring_mbar=pm->get_spring_pressure(releasing);plant.on.spring_mbar=pm->get_spring_pressure(applying);
        // Calibration seeds only. capacity_scale lets the independent plant differ
        // from the controller's nominal clutch capacity estimate.
        plant.off.nm_per_mbar=pm->sliding_coefficient()/MECH_PTR->friction_map[from*6+(int)releasing];
        plant.on.nm_per_mbar=pm->sliding_coefficient()/MECH_PTR->friction_map[to*6+(int)applying];
        if(!std::isfinite(plant.off.nm_per_mbar) || !std::isfinite(plant.on.nm_per_mbar) ||
           plant.off.nm_per_mbar<=0 || plant.on.nm_per_mbar<=0) throw std::invalid_argument("missing clutch calibration");
        auto holding=[&](const Nag52Plant::Clutch& c,double torque){return c.spring_mbar+std::max(80.,std::abs(torque)*1.8)/c.nm_per_mbar;};
        plant.initialize(cfg["speed_kph"]/3.6,cfg["torque_nm"],holding(plant.off,cfg["torque_nm"]));
        ShiftPressures pressure={};pm->register_shift_pressure_data(&pressure);
        ShiftClutchData cs={};TorqueRequstData trd={TorqueRequestControlType::None,TorqueRequestBounds::LessThan,0};
        const bool trq_enabled[]={SBS_CURRENT_SETTINGS.en_trq_req_1_2,SBS_CURRENT_SETTINGS.en_trq_req_2_3,
            SBS_CURRENT_SETTINGS.en_trq_req_3_4,SBS_CURRENT_SETTINGS.en_trq_req_4_5,SBS_CURRENT_SETTINGS.en_trq_req_2_1,
            SBS_CURRENT_SETTINGS.en_trq_req_3_2,SBS_CURRENT_SETTINGS.en_trq_req_4_3,SBS_CURRENT_SETTINGS.en_trq_req_5_4};
        ShiftInterfaceData sid={.profile=standard,.MOD_MAX=pm->get_max_solenoid_pressure(),
            .SPC_MAX=pm->get_max_shift_pressure(change-1),.shift_flags=0,.change=req,
            .applying=applying,.releasing=releasing,.curr_g=actual,.targ_g=target,.inf=info,
            .release_spring_on_clutch=(uint16_t)plant.on.spring_mbar,.release_spring_off_clutch=(uint16_t)plant.off.spring_mbar,
            .prefill_info=pm->make_fill_data(applying),.chars={(uint16_t)cfg["time_ms"]},
            .ptr_r_clutch_speeds=&cs,.ptr_w_pressures=&pressure,.ptr_w_trq_req=&trd,
            .tcc=tcc,.adaptation_mgr=adapter,.manual_shift=false,.trq_req_en=trq_enabled[change-1],.diff_ratio=(float)par.final_drive};
        auto sensed=[&]() {
            sd.engine_rpm=(uint16_t)rpm(plant.s.engine);sd.input_rpm=(uint16_t)rpm(plant.s.turbine);sd.output_rpm=(uint16_t)rpm(plant.s.output);
            sd.converted_torque=sd.indicated_torque=(int16_t)plant.s.engine_torque;
            // Firmware sees its own converter estimate, not the plant's hidden torque.
            sd.input_torque=InputTorqueModel::get_input_torque(sd.engine_rpm,sd.input_rpm,sd.converted_torque);
            sd.pump_torque=InputTorqueModel::get_pump_torque(sd.engine_rpm,sd.input_rpm);
            sd.tcc_trq_multiplier=InputTorqueModel::get_input_torque_factor(sd.engine_rpm,sd.input_rpm);
            sd.gear_ratio=sd.output_rpm?(float)sd.input_rpm/sd.output_rpm:0;sd.targ_gear_ratio=plant.new_ratio;
            double n2=sd.input_rpm,n3=sd.input_rpm;
            if(change==1 || change==5) {n2=sd.output_rpm*ratios[1].ratio;n3=(sd.output_rpm*ratios[0].ratio-sd.input_rpm)/(ratios[0].ratio/ratios[1].ratio-1);}
            if(change==4 || change==8) {n2=sd.output_rpm;n3=(sd.input_rpm-sd.output_rpm*ratios[4].ratio)/(1-ratios[4].ratio);}
            SpeedSensors speeds={(uint16_t)clamp(n2,0,60000),(uint16_t)clamp(n3,0,60000),sd.input_rpm,sd.output_rpm};
            cs=ClutchSpeedModel::get_shifting_clutch_speeds(speeds,req,ratios);
        };
        FILE* out=fopen(argv[2],"w");if(!out) throw std::runtime_error("cannot create output CSV");
        fprintf(out,"t_s,controller_active,phase,engine_rpm,input_rpm,output_rpm,speed_m_s,accel_m_s2,jerk_m_s3,jerk_20ms_m_s3,engine_torque_nm,converter_torque_nm,off_pressure_mbar,on_pressure_mbar,off_capacity_nm,on_capacity_nm,off_torque_nm,on_torque_nm,off_slip_rpm,on_slip_rpm,request_active,request_nm\n");
        ShiftingAlgorithm* algo=nullptr;int phase=0,phase_ms=0,elapsed_ms=0;
        bool done=false,failed=false,opened=false,domain_exit=false;double finish=-1,first_sync=-1,sync_since=-1;
        double cmd_on=0,cmd_off=holding(plant.off,cfg["torque_nm"]),peak_jerk=0,peak_jerk20=0,min_accel=1e9,max_engine=0;
        std::deque<double> ahist;const int window=20000/dt_us;
        const auto wall_start=std::chrono::steady_clock::now();int samples=0;
        for(int64_t us=0;us<(int64_t)std::llround(cfg["seconds"]*1e6);us+=dt_us) {
            double t=us/1e6,dt=dt_us/1e6;
            const bool tip=t>=cfg["tipin_s"];
            const double driver=cfg[tip?"torque_after_nm":"torque_nm"];
            if(plant.s.engine<0 || plant.s.turbine<0 || plant.s.output<0 ||
               rpm(plant.s.engine)>6000 || rpm(plant.s.turbine)>6000 || !std::isfinite(plant.kinetic_energy())) {domain_exit=true;break;}
            if(us%20000==0) {
                sim_clock_ms=(uint32_t)(us/1000);
                sd.pedal_pos=(uint8_t)cfg[tip?"pedal_after":"pedal"];sd.pedal_pos_smoothed=sd.pedal_pos;
                sd.converted_driver_torque=(int16_t)driver;sd.min_torque=-54;sd.max_torque=330;sensed();
                if(t>=cfg["shift_at_s"] && !algo) {
                    ShiftHelpers::calc_shift_flags(&sid,&sd,true);
                    const bool release=up?sd.converted_driver_torque<=-27:
                        ((sd.converted_driver_torque>54 || (sid.shift_flags&SHIFT_FLAG_COAST)==1) &&
                         (sid.shift_flags&SHIFT_FLAG_COAST_54_43)==0);
                    algo=release?(ShiftingAlgorithm*)new ReleasingShift(&sid):(ShiftingAlgorithm*)new CrossoverShift(&sid);
                }
                if(algo && !done && !failed) {
                    uint8_t res=algo->step(phase,std::abs(sd.input_torque),false,up,phase_ms,elapsed_ms,pm,&sd);
                    const auto fb=algo->get_diag_feedback(phase);
                    pm->set_target_shift_pressure(pressure.shift_sol_req);pm->set_target_modulating_pressure(pressure.mod_sol_req);
                    pm->update_pressures(target,req);
                    const bool circuit=pm->get_active_shift_circuits()!=0;opened|=circuit;
                    if(circuit) {
                        // p_off diagnostics are MPC, not off-clutch pressure. Invert
                        // the overlap mixer before modeling its hydraulic response.
                        cmd_on=fb.p_on;
                        cmd_off=std::max(0.,(pressure.mod_sol_req-info.mpc_pressure_spring_reduction-
                            cmd_on*info.pressure_multi_spc_int/1000.)*1000./info.pressure_multi_mpc_int);
                    } else if(opened) {cmd_on=holding(plant.on,driver);cmd_off=0;}
                    if(res==STEP_RES_END_SHIFT) {done=true;finish=t;trd.ty=TorqueRequestControlType::None;}
                    else if(res==STEP_RES_FAILURE) {failed=true;finish=t;trd.ty=TorqueRequestControlType::None;}
                    else if(res==STEP_RES_CONTINUE) phase_ms+=20;
                    else {phase_ms=0;phase=res==STEP_RES_NEXT?phase+1:res;}
                    elapsed_ms+=20;
                } else if(done) {cmd_on=holding(plant.on,driver);cmd_off=0;}
                else if(!algo) cmd_off=holding(plant.off,driver);
            }
            double engine_command=driver;
            if(trd.ty!=TorqueRequestControlType::None) {
                if(trd.bounds==TorqueRequestBounds::LessThan) engine_command=std::min(engine_command,(double)trd.amount);
                else if(trd.bounds==TorqueRequestBounds::MoreThan) engine_command=std::max(engine_command,(double)trd.amount);
                else engine_command=trd.amount;
            }
            plant.step(dt,engine_command,cmd_off,cmd_on);
            double j20=ahist.size()==(size_t)window?(plant.s.acceleration-ahist.front())/.02:0;
            ahist.push_back(plant.s.acceleration);if(ahist.size()>(size_t)window)ahist.pop_front();
            const double on_slip=rpm(plant.s.turbine-plant.new_ratio*plant.s.output);
            if(algo) {
                peak_jerk=std::max(peak_jerk,std::abs(plant.s.jerk));peak_jerk20=std::max(peak_jerk20,std::abs(j20));
                min_accel=std::min(min_accel,plant.s.acceleration);max_engine=std::max(max_engine,rpm(plant.s.engine));
                if(std::abs(on_slip)<40) {if(sync_since<0)sync_since=t+dt;if(first_sync<0 && t+dt-sync_since>=.1)first_sync=sync_since;}
                else sync_since=-1;
            }
            fprintf(out,"%.6f,%d,%d,%.6f,%.6f,%.6f,%.9f,%.9f,%.9f,%.9f,%.6f,%.6f,%.6f,%.6f,%.6f,%.6f,%.6f,%.6f,%.6f,%.6f,%d,%.6f\n",
                t+dt,algo&&!done&&!failed,phase,rpm(plant.s.engine),rpm(plant.s.turbine),rpm(plant.s.output),plant.speed(),
                plant.s.acceleration,plant.s.jerk,j20,plant.s.engine_torque,plant.s.converter_torque,plant.off.pressure,plant.on.pressure,
                plant.s.off_capacity,plant.s.on_capacity,plant.s.off_torque,plant.s.on_torque,
                rpm(plant.s.turbine-plant.old_ratio*plant.s.output),on_slip,trd.ty!=TorqueRequestControlType::None,trd.amount);
            ++samples;
        }
        fclose(out);
        const double wall=std::chrono::duration<double>(std::chrono::steady_clock::now()-wall_start).count();
        printf("{\"parameters\":{");
        bool first_parameter=true;
        for(const auto& item:cfg) {
            printf("%s\"%s\":%.12g",first_parameter?"":",",item.first.c_str(),item.second);
            first_parameter=false;
        }
        printf("},\"result\":");
        printf("{\"model\":\"equivalent-two-path-v1\",\"controller_completed\":%s,\"controller_failed\":%s,\"controller_timed_out\":%s,\"domain_exit\":%s,\"controller_end_s\":%.6f,\"first_sync_s\":%.6f,\"final_sync\":%s,\"final_slip_rpm\":%.6f,\"peak_abs_jerk_m_s3\":%.6f,\"peak_abs_jerk_20ms_m_s3\":%.6f,\"min_accel_m_s2\":%.6f,\"max_engine_rpm\":%.6f,\"samples\":%d,\"simulated_s\":%.6f,\"wall_s\":%.6f}\n",
            done?"true":"false",failed?"true":"false",algo&&algo->did_time_out()?"true":"false",domain_exit?"true":"false",finish,first_sync,
            sync_since>=0 && samples*dt_us/1e6-sync_since>=.1?"true":"false",rpm(plant.s.turbine-plant.new_ratio*plant.s.output),
            peak_jerk,peak_jerk20,min_accel==1e9?0:min_accel,max_engine,samples,samples*dt_us/1e6,wall);
        printf("}\n");
        return 0;
    } catch(const std::exception& e) {fprintf(stderr,"plant: %s\n",e.what());return 2;}
}
