#include "../plant.h"
#include <cassert>
#include <iostream>
using namespace Nag52Plant;
Parameters ideal() { Parameters p; p.rolling_coefficient=0;p.cda_m2=0;return p; }
Model make(double mass=1800) {
    auto p=ideal();p.mass_kg=mass;Model m(p,2.408,1.486);
    m.off.nm_per_mbar=m.on.nm_per_mbar=.1;
    m.initialize(10,100,6000);return m;
}
double accelerate(double mass) {
    auto m=make(mass);
    for(int i=0;i<3000;++i)m.step(.001,100,6000,0);
    const double c=m.p.wheel_radius_m/m.p.final_drive;
    const double effective_J=m.output_J()+(m.p.engine_inertia+m.p.turbine_inertia)*m.old_ratio*m.old_ratio;
    const double expected=100*m.old_ratio/effective_J*c;
    assert(std::abs(m.s.acceleration-expected)<.002);
    assert(std::abs(m.s.turbine-m.old_ratio*m.s.output)<1e-5);
    return m.s.acceleration;
}
Model shift(double dt) {
    auto m=make();
    for(int i=0;i<std::lround(2/dt);++i) {
        double t=i*dt;
        double off=6000*(1-clamp((t-.2)/.3,0,1));
        double on=5000*clamp((t-.1)/.5,0,1);
        m.step(dt,100,off,on);
        assert(std::abs(m.s.off_torque)<=m.s.off_capacity+1e-8);
        assert(std::abs(m.s.on_torque)<=m.s.on_capacity+1e-8);
    }
    assert(std::abs(rpm(m.s.turbine-m.new_ratio*m.s.output))<1);
    return m;
}
int main() {
    assert(accelerate(2500)<accelerate(1500));
    // Dissipative coupling may move kinetic energy between shafts, never create it.
    for(int direction:{-1,1}) {
        auto m=make();m.s.engine_torque=0;m.s.engine=m.s.turbine+direction*30;
        for(int i=0;i<1000;++i) {
            double before=m.kinetic_energy();m.step(.001,0,3000,3500);
            assert(m.kinetic_energy()<=before+1e-6);
        }
    }
    auto a=shift(.001),b=shift(.0005),c=shift(.00025);
    assert(std::abs(a.speed()-b.speed())<.005);
    assert(std::abs(b.speed()-c.speed())<.003);
    // With both paths open, engine torque cannot accelerate the vehicle.
    auto open=make();open.off.fill=0;open.off.pressure=0;
    double speed=open.speed();for(int i=0;i<1000;++i)open.step(.001,100,0,0);
    assert(std::abs(open.speed()-speed)<1e-10);
    // Higher pressure and a completed fill produce more available torque.
    Clutch low,high;Parameters p;
    double lc=0,hc=0;for(int i=0;i<1000;++i){lc=low.update(1500,.001,p);hc=high.update(3000,.001,p);}
    assert(hc>lc && lc>0);
    Clutch filling;assert(filling.update(3000,.001,p)==0);
    std::cout<<"plant physics and timestep checks passed\n";
}
