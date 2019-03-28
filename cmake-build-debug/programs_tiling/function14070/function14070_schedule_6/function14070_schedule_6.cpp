#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function14070_schedule_6");

    constant c0("c0", 64), c1("c1", 64), c2("c2", 64), c3("c3", 64);

    var i0("i0", 0, c0), i1("i1", 0, c1), i2("i2", 0, c2), i3("i3", 0, c3), i01("i01"), i02("i02"), i03("i03"), i04("i04");

    computation comp0("comp0", {i0, i1, i2, i3}, 7 - 1);
    
    comp0.tile(i0, i1, 64, 32, i01, i02, i03, i04);
    comp0.parallelize(i01);
    
    buffer buf0("buf0", {64, 64, 64, 64}, p_int32, a_output);
    
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf0}, "../data/programs/function14070/function14070_schedule_6/function14070_schedule_6.o");

    return 0;
}