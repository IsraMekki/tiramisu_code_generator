#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function14348_schedule_17");

    constant c0("c0", 256), c1("c1", 512), c2("c2", 256);

    var i0("i0", 0, c0), i1("i1", 0, c1), i2("i2", 0, c2), i100("i100", 2, c0 - 2), i101("i101", 2, c1 - 2), i102("i102", 2, c2 - 2), i01("i01"), i02("i02"), i03("i03"), i04("i04");

    input input0("input0", {i0, i1, i2}, p_int32);

    computation comp0("comp0", {i100, i101, i102}, (input0(i100, i101, i102) + input0(i100 + 1, i101, i102) - input0(i100 + 2, i101, i102) + input0(i100 - 1, i101, i102) - input0(i100 - 2, i101, i102)));
    
    comp0.tile(i101, i102, 128, 128, i01, i02, i03, i04);
    comp0.parallelize(i100);
    
    buffer buf00("buf00", {256, 512, 256}, p_int32, a_input);
    buffer buf0("buf0", {256, 512, 256}, p_int32, a_output);
    
    input0.store_in(&buf00);
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf00, &buf0}, "../data/programs/function14348/function14348_schedule_17/function14348_schedule_17.o");

    return 0;
}