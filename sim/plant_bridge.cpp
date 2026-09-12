// Minimal C ABI for the EGS51 Python schedule harness. Same plant as NAG52.
#include "plant.h"
using namespace Nag52Plant;
extern "C" {
void* plant_create(const double* a) {
    try {
        Parameters p;
        p.mass_kg=a[0]; p.grade_percent=a[1]; p.capacity_scale=a[2];
        p.pressure_tau_s=a[3]; p.fill_s=a[4];
        auto* m=new Model(p,a[5],a[6]);
        m->off.spring_mbar=a[7]; m->on.spring_mbar=a[8];
        m->off.nm_per_mbar=a[9]; m->on.nm_per_mbar=a[10];
        m->initialize(a[11],a[12],a[13]);
        return m;
    } catch (...) { return nullptr; }
}
void plant_destroy(void* p) { delete static_cast<Model*>(p); }
void plant_step(void* p,double dt,double torque,double off,double on) {
    static_cast<Model*>(p)->step(dt,torque,off,on);
}
void plant_read(void* p,double* a) {
    auto& m=*static_cast<Model*>(p); auto& s=m.s;
    double values[]={rpm(s.engine),rpm(s.turbine),rpm(s.output),m.speed(),
        s.acceleration,s.jerk,s.engine_torque,s.converter_torque,
        m.off.pressure,m.on.pressure,s.off_capacity,s.on_capacity,
        s.off_torque,s.on_torque};
    std::copy(values,values+14,a);
}
}
