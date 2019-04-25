#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function73742_no_schedule");

    constant c0("c0", 64), c1("c1", 64), c2("c2", 128), c3("c3", 64);

    var i0("i0", 0, c0), i1("i1", 0, c1), i2("i2", 0, c2), i3("i3", 0, c3);

    input input00("input00", {i0, i1, i3}, p_int32);

    input input01("input01", {i2}, p_int32);

    input input02("input02", {i1, i2, i3}, p_int32);

    computation comp0("comp0", {i0, i1, i2, i3}, input00(i0, i1, i3) * input01(i2) + input02(i1, i2, i3));
    
    comp0.parallelize(i0);
    
    buffer buf00("buf00", {64, 64, 64}, p_int32, a_input);
    buffer buf01("buf01", {128}, p_int32, a_input);
    buffer buf02("buf02", {64, 128, 64}, p_int32, a_input);
    buffer buf0("buf0", {64, 64, 128, 64}, p_int32, a_output);
    
    input00.store_in(&buf00);
    input01.store_in(&buf01);
    input02.store_in(&buf02);
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf00, &buf01, &buf02, &buf0}, "../data/programs/function73742/function73742_no_schedule/function73742_no_schedule.o");

    return 0;
}