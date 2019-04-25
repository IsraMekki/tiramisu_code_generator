#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function66346_schedule_0");

    constant c0("c0", 512), c1("c1", 128), c2("c2", 1024);

    var i0("i0", 0, c0), i1("i1", 0, c1), i2("i2", 0, c2);

    input input00("input00", {i0}, p_int32);

    input input01("input01", {i0, i1}, p_int32);

    computation comp0("comp0", {i0, i1, i2}, input00(i0) + input01(i0, i1));
    
    comp0.unroll(i2, 4);
    comp0.parallelize(i0);
    
    buffer buf00("buf00", {512}, p_int32, a_input);
    buffer buf01("buf01", {512, 128}, p_int32, a_input);
    buffer buf0("buf0", {512, 128, 1024}, p_int32, a_output);
    
    input00.store_in(&buf00);
    input01.store_in(&buf01);
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf00, &buf01, &buf0}, "../data/programs/function66346/function66346_schedule_0/function66346_schedule_0.o");

    return 0;
}