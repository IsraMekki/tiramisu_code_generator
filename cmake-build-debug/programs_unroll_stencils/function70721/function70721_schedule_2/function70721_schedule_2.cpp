#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function70721_schedule_2");

    constant c0("c0", 64), c1("c1", 128), c2("c2", 64), c3("c3", 64);

    var i0("i0", 0, c0), i1("i1", 0, c1), i2("i2", 0, c2), i3("i3", 0, c3);

    input input00("input00", {i1, i3}, p_int32);

    input input01("input01", {i0, i1}, p_int32);

    input input02("input02", {i3, i1, i2}, p_int32);

    input input03("input03", {i1}, p_int32);

    computation comp0("comp0", {i0, i1, i2, i3}, input00(i1, i3) - input01(i0, i1) - input02(i3, i1, i2) - input03(i1));
    
    comp0.unroll(i3, 16);
    comp0.parallelize(i0);
    
    buffer buf00("buf00", {128, 64}, p_int32, a_input);
    buffer buf01("buf01", {64, 128}, p_int32, a_input);
    buffer buf02("buf02", {64, 128, 64}, p_int32, a_input);
    buffer buf03("buf03", {128}, p_int32, a_input);
    buffer buf0("buf0", {64, 128, 64, 64}, p_int32, a_output);
    
    input00.store_in(&buf00);
    input01.store_in(&buf01);
    input02.store_in(&buf02);
    input03.store_in(&buf03);
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf00, &buf01, &buf02, &buf03, &buf0}, "../data/programs/function70721/function70721_schedule_2/function70721_schedule_2.o");

    return 0;
}