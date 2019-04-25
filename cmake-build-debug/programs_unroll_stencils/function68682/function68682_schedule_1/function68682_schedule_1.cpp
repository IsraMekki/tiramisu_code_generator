#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function68682_schedule_1");

    constant c0("c0", 512), c1("c1", 128), c2("c2", 512);

    var i0("i0", 0, c0), i1("i1", 0, c1), i2("i2", 0, c2);

    input input00("input00", {i1}, p_int32);

    input input01("input01", {i2}, p_int32);

    computation comp0("comp0", {i0, i1, i2}, input00(i1) + input01(i2));
    
    comp0.unroll(i2, 8);
    comp0.parallelize(i0);
    
    buffer buf00("buf00", {128}, p_int32, a_input);
    buffer buf01("buf01", {512}, p_int32, a_input);
    buffer buf0("buf0", {512, 128, 512}, p_int32, a_output);
    
    input00.store_in(&buf00);
    input01.store_in(&buf01);
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf00, &buf01, &buf0}, "../data/programs/function68682/function68682_schedule_1/function68682_schedule_1.o");

    return 0;
}