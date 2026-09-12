#include "../cycle_plant.cpp"
#include <cassert>
#include <iostream>
int main() {
    Cycle c;
    double command[]={3.932,3.932,0,0,1200,.08,1200,.08,5000,1};
    cycle_command(&c,0,0,command);
    for(int i=0;i<3000;i++) cycle_step(&c,.001,0,1e9);
    assert(std::abs(c.model.speed())<1e-8);
    assert(rpm(c.model.s.engine)>650 && rpm(c.model.s.engine)<850);
    for(const auto& path:c.paths) assert(path.fill==0);
    command[3]=4000;command[9]=0;
    cycle_command(&c,0,1,command);
    for(int i=0;i<4000;i++) cycle_step(&c,.001,0,1e9);
    assert(c.paths[1].fill==1);
    assert(std::abs(c.model.speed())<1e-8);
    assert(std::abs(rpm(c.model.s.turbine))<1);
    assert(c.model.s.engine_torque>0);
    command[8]=0;
    const auto engine=c.model.s.engine,turbine=c.model.s.turbine;
    cycle_command(&c,0,1,command);
    assert(c.model.on.fill==1 && c.model.s.engine==engine && c.model.s.turbine==turbine);
    for(int i=0;i<5000;i++) cycle_step(&c,.001,.2,1e9);
    assert(c.model.speed()>1);
    command[8]=5000;cycle_command(&c,0,1,command);
    for(int i=0;i<5000;i++) cycle_step(&c,.001,0,1e9);
    assert(std::abs(c.model.speed())<1e-5);
    std::cout<<"Park, idle, finite brake holding, fill continuity, launch and stop pass\n";
}
