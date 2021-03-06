#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function14463_schedule_15");

    constant c0("c0", 1024), c1("c1", 256), c2("c2", 128);

    var i0("i0", 0, c0), i1("i1", 0, c1), i2("i2", 0, c2), i01("i01"), i02("i02"), i03("i03"), i04("i04");

    input input00("input00", {i0, i1}, p_int32);

    input input01("input01", {i2}, p_int32);

    computation comp0("comp0", {i0, i1, i2}, input00(i0, i1) * input01(i2));
    
    comp0.tile(i1, i2, 128, 64, i01, i02, i03, i04);
    comp0.parallelize(i0);
    
    buffer buf00("buf00", {1024, 256}, p_int32, a_input);
    buffer buf01("buf01", {128}, p_int32, a_input);
    buffer buf0("buf0", {1024, 256, 128}, p_int32, a_output);
    
    input00.store_in(&buf00);
    input01.store_in(&buf01);
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf00, &buf01, &buf0}, "../data/programs/function14463/function14463_schedule_15/function14463_schedule_15.o");

    return 0;
}