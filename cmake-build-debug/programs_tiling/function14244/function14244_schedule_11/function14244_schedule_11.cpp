#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function14244_schedule_11");

    constant c0("c0", 64), c1("c1", 512), c2("c2", 2048);

    var i0("i0", 0, c0), i1("i1", 0, c1), i2("i2", 0, c2), i100("i100", 1, c0 - 1), i101("i101", 1, c1 - 1), i102("i102", 1, c2 - 1), i01("i01"), i02("i02"), i03("i03"), i04("i04");

    input input0("input0", {i0, i1, i2}, p_int32);

    computation comp0("comp0", {i100, i101, i102}, (input0(i100, i101, i102) + input0(i100 + 1, i101, i102) - input0(i100 - 1, i101, i102)));
    
    comp0.tile(i101, i102, 128, 128, i01, i02, i03, i04);
    comp0.parallelize(i100);
    
    buffer buf00("buf00", {64, 512, 2048}, p_int32, a_input);
    buffer buf0("buf0", {64, 512, 2048}, p_int32, a_output);
    
    input0.store_in(&buf00);
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf00, &buf0}, "../data/programs/function14244/function14244_schedule_11/function14244_schedule_11.o");

    return 0;
}