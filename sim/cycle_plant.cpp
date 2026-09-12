// Persistent equivalent gear paths for the whole-drive host experiment.
// Gear-path clutches are not a planetary 722.6 clutch/freewheel reconstruction.
#include "plant.h"
#include <array>
using namespace Nag52Plant;
struct Cycle {
    Model model;
    std::array<Clutch,6> paths{};
    int old_gear=0,new_gear=0;
    double off_command=0,on_command=0;
    double idle_integral=0;
    static Parameters parameters() {
        Parameters p; p.converter_stall_coefficient=.007; return p;
    }
    Cycle():model(parameters(),1,1) {
        model.s.engine=rad_s(750); model.s.turbine=rad_s(750);
        model.park_locked=true;
    }
};
extern "C" {
void* cycle_create() { return new Cycle; }
void cycle_destroy(void* p) { delete static_cast<Cycle*>(p); }
// ratios, commands, springs and capacities come from the controller adapter.
void cycle_command(void* p,int old_g,int new_g,const double* a) {
    auto& c=*static_cast<Cycle*>(p); auto& m=c.model;
    c.old_gear=old_g;c.new_gear=new_g;
    m.old_ratio=a[0];m.new_ratio=a[1];c.off_command=a[2];c.on_command=a[3];
    m.off=old_g?c.paths[old_g]:Clutch{};m.on=new_g?c.paths[new_g]:Clutch{};
    m.off.spring_mbar=a[4];m.off.nm_per_mbar=a[5];
    m.on.spring_mbar=a[6];m.on.nm_per_mbar=a[7];
    m.holding_brake_force_n=a[8];m.park_locked=a[9]!=0;
}
void cycle_step(void* p,double dt,double pedal,double torque_limit) {
    auto& c=*static_cast<Cycle*>(p);auto& m=c.model;
    double error=750-rpm(m.s.engine);
    c.idle_integral=clamp(c.idle_integral+error*dt*.3,0,90);
    double idle=clamp(error*.4+c.idle_integral,0,130);
    double drag=12+.006*rpm(m.s.engine);
    // Deliberately simple engine; governor and torque limits are host assumptions.
    double drive=pedal*300;
    double net=std::max(idle,drive)-drag;
    // The adapter uses a large bound when inactive, so negative requests
    // remain meaningful rather than being mistaken for a sentinel.
    net=std::min(net,torque_limit);
    if(rpm(m.s.engine)>4500) net=std::min(net,0.0);
    m.step(dt,net,c.off_command,c.on_command);
    if(c.old_gear)c.paths[c.old_gear]=m.off;
    if(c.new_gear)c.paths[c.new_gear]=m.on;
    for(int k=1;k<=5;k++) if(k!=c.old_gear && k!=c.new_gear)c.paths[k].update(0,dt,m.p);
}
void cycle_read(void* p,double* a) {
    auto& c=*static_cast<Cycle*>(p);auto& m=c.model;auto& s=m.s;
    double v[]={rpm(s.engine),rpm(s.turbine),rpm(s.output),m.speed(),s.acceleration,s.jerk,
        s.engine_torque,s.converter_torque,m.off.pressure,m.on.pressure,s.off_capacity,s.on_capacity,
        s.off_torque,s.on_torque,m.off.fill,m.on.fill,s.friction_energy_j};
    std::copy(v,v+17,a);
}
}
