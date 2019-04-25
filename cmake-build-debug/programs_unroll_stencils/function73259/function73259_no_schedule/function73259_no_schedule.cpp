#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function73259_no_schedule");

    constant c0("c0", 16384), c1("c1", 4096);

    var i0("i0", 0, c0), i1("i1", 0, c1);

    input input00("input00", {i0}, p_int32);

    input input01("input01", {i0}, p_int32);

    input input02("input02", {i1}, p_int32);

    computation comp0("comp0", {i0, i1}, input00(i0) * input01(i0) + input02(i1));
    
    comp0.parallelize(i0);
    
    buffer buf00("buf00", {16384}, p_int32, a_input);
    buffer buf01("buf01", {16384}, p_int32, a_input);
    buffer buf02("buf02", {4096}, p_int32, a_input);
    buffer buf0("buf0", {16384, 4096}, p_int32, a_output);
    
    input00.store_in(&buf00);
    input01.store_in(&buf01);
    input02.store_in(&buf02);
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf00, &buf01, &buf02, &buf0}, "../data/programs/function73259/function73259_no_schedule/function73259_no_schedule.o");

    return 0;
}