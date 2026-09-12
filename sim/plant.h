#pragma once
#include <algorithm>
#include <cmath>
#include <stdexcept>

// First-order equivalent driveline, SI units. The two friction paths represent
// the current and requested ratios; they are not a full planetary gearset model.
namespace Nag52Plant {
constexpr double pi = 3.14159265358979323846;
inline double rpm(double w) { return w * 30 / pi; }
inline double rad_s(double n) { return n * pi / 30; }
inline double clamp(double x, double lo, double hi) { return std::max(lo, std::min(x, hi)); }
struct Parameters {
    double mass_kg = 1800, wheel_radius_m = 1.975 / (2*pi), final_drive = 3.07;
    double engine_inertia = .25, turbine_inertia = .16, output_inertia = .5;
    double converter_damping = 8, engine_lag_s = .12;
    double pressure_tau_s = .04, fill_s = .12, fill_reference_mbar = 1500;
    double capacity_scale = 1, rolling_coefficient = .012, cda_m2 = .62;
    double grade_percent = 0, brake_force_n = 0;
    // Optional drive-cycle converter law; zero preserves the original shift model.
    double converter_stall_coefficient = 0;
    void validate() const {
        const double positive[] = {mass_kg,wheel_radius_m,final_drive,engine_inertia,
            turbine_inertia,output_inertia,converter_damping,engine_lag_s,
            pressure_tau_s,fill_s,fill_reference_mbar,capacity_scale};
        for (double v : positive) if (!std::isfinite(v) || v <= 0) throw std::invalid_argument("plant parameters must be finite and positive");
        for (double v : {rolling_coefficient,cda_m2,brake_force_n,converter_stall_coefficient})
            if (!std::isfinite(v) || v < 0) throw std::invalid_argument("road resistance must be finite and nonnegative");
        if (!std::isfinite(grade_percent)) throw std::invalid_argument("grade must be finite");
    }
};
struct Clutch {
    double pressure = 0, fill = 0, spring_mbar = 1000, nm_per_mbar = .08;
    double update(double command, double dt, const Parameters& p) {
        command = std::max(0.0, command);
        if (fill < 1 && command > 0) {
            fill = std::min(1.0, fill + dt * command / (p.fill_s * p.fill_reference_mbar));
            // Piston travel consumes flow before torque capacity appears.
            pressure += (std::min(command, spring_mbar) - pressure) * (-std::expm1(-dt/p.pressure_tau_s));
        } else {
            pressure += (command - pressure) * (-std::expm1(-dt/p.pressure_tau_s));
        }
        if (command == 0 && pressure < spring_mbar * .25) fill = std::max(0.0, fill - dt/p.fill_s);
        return fill < 1 ? 0 : std::max(0.0, pressure-spring_mbar) * nm_per_mbar * p.capacity_scale;
    }
};
struct State {
    double engine = 0, turbine = 0, output = 0, engine_torque = 0;
    double acceleration = 0, jerk = 0, converter_torque = 0;
    double off_torque = 0, on_torque = 0, off_capacity = 0, on_capacity = 0;
    double friction_energy_j = 0;
};
class Model {
public:
    Parameters p;
    State s;
    Clutch off, on;
    double old_ratio, new_ratio;
    bool park_locked = false;
    double holding_brake_force_n = 0;
    Model(Parameters params, double old_r, double new_r):p(params),old_ratio(old_r),new_ratio(new_r) {
        p.validate();
        if (old_r<=0 || new_r<=0) throw std::invalid_argument("forward ratios required");
    }
    double output_J() const { return p.output_inertia + p.mass_kg * std::pow(p.wheel_radius_m/p.final_drive,2); }
    double speed() const { return s.output*p.wheel_radius_m/p.final_drive; }
    double kinetic_energy() const {
        return .5*(p.engine_inertia*s.engine*s.engine + p.turbine_inertia*s.turbine*s.turbine + output_J()*s.output*s.output);
    }
    void initialize(double speed_m_s, double torque, double holding_pressure) {
        s.output = speed_m_s * p.final_drive / p.wheel_radius_m;
        s.turbine = s.output*old_ratio;
        s.engine = s.turbine + torque/p.converter_damping;
        s.engine_torque = torque;
        off.fill = 1; off.pressure = holding_pressure;
    }
    void step(double dt, double engine_command, double off_command, double on_command) {
        if (!(dt>0 && dt<=.005)) throw std::invalid_argument("plant step must be in (0, 5ms]");
        s.off_capacity=off.update(off_command,dt,p); s.on_capacity=on.update(on_command,dt,p);
        s.engine_torque += (engine_command-s.engine_torque)*(-std::expm1(-dt/p.engine_lag_s));
        const double previous_output=s.output, previous_accel=s.acceleration;
        const double angle=std::atan(p.grade_percent/100);
        const double v=speed();
        const double resistance=(p.mass_kg*9.81*p.rolling_coefficient*std::cos(angle) +
            .5*1.225*p.cda_m2*v*v + p.brake_force_n)*std::tanh(v/.1) + p.mass_kg*9.81*std::sin(angle);
        s.engine += dt*s.engine_torque/p.engine_inertia;
        s.output -= dt*resistance*p.wheel_radius_m/p.final_drive/output_J();
        const double energy_before=kinetic_energy();
        // Implicit viscous converter and bounded clutch impulses. Static friction
        // transfers only the torque required to stick, up to the pressure capacity.
        // No gear or shaft speed is snapped to the requested ratio on completion.
        double qc=0, qo=0, qn=0, qb=0;
        for (int i=0;i<80;++i) {
            const double old_qc=qc, old_qo=qo, old_qn=qn, old_qb=qb;
            const double damping=p.converter_stall_coefficient>0 ?
                std::min(p.converter_damping,p.converter_stall_coefficient*std::abs(s.engine)) : p.converter_damping;
            const double kdt=damping*dt;
            const double inv=p.engine_inertia>0 ? 1/p.engine_inertia+1/p.turbine_inertia : 0;
            const double next=(kdt*(s.engine-s.turbine)+kdt*inv*qc)/(1+kdt*inv);
            s.engine-=(next-qc)/p.engine_inertia; s.turbine+=(next-qc)/p.turbine_inertia; qc=next;
            auto project=[&](double ratio, double cap, double& impulse) {
                const double next_q=clamp(impulse+(s.turbine-ratio*s.output)/
                    (1/p.turbine_inertia+ratio*ratio/output_J()),-cap*dt,cap*dt);
                s.turbine-=(next_q-impulse)/p.turbine_inertia;
                s.output+=ratio*(next_q-impulse)/output_J(); impulse=next_q;
            };
            project(old_ratio,s.off_capacity,qo); project(new_ratio,s.on_capacity,qn);
            // A bounded static brake can hold at zero speed; tanh road drag cannot.
            const double brake_limit=holding_brake_force_n*p.wheel_radius_m/p.final_drive*dt;
            const double requested=qb+s.output*output_J();
            const double next_brake=park_locked ? requested : clamp(requested,-brake_limit,brake_limit);
            s.output-=(next_brake-qb)/output_J(); qb=next_brake;
            if (std::max({std::abs(qc-old_qc),std::abs(qo-old_qo),std::abs(qn-old_qn),std::abs(qb-old_qb)})<1e-11) break;
        }
        // Includes converter dissipation and integration loss; not a clutch-wear estimate.
        s.friction_energy_j+=std::max(0.0,energy_before-kinetic_energy());
        s.converter_torque=qc/dt; s.off_torque=qo/dt; s.on_torque=qn/dt;
        s.acceleration=(s.output-previous_output)*p.wheel_radius_m/p.final_drive/dt;
        s.jerk=(s.acceleration-previous_accel)/dt;
    }
};
}
