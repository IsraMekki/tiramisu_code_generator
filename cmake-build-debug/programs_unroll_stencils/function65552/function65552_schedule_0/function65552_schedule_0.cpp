#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function65552_schedule_0");

    constant c0("c0", 128), c1("c1", 512), c2("c2", 512);

    var i0("i0", 0, c0), i1("i1", 0, c1), i2("i2", 0, c2);

    input input00("input00", {i1}, p_int32);

    input input01("input01", {i1, i2}, p_int32);

    input input02("input02", {i0, i1}, p_int32);

    input input03("input03", {i0, i2}, p_int32);

    input input04("input04", {i0, i2}, p_int32);

    computation comp0("comp0", {i0, i1, i2}, input00(i1) + input01(i1, i2) * input02(i0, i1) - input03(i0, i2) * input04(i0, i2));
    
    comp0.unroll(i2, 4);
    comp0.parallelize(i0);
    
    buffer buf00("buf00", {512}, p_int32, a_input);
    buffer buf01("buf01", {512, 512}, p_int32, a_input);
    buffer buf02("buf02", {128, 512}, p_int32, a_input);
    buffer buf03("buf03", {128, 512}, p_int32, a_input);
    buffer buf04("buf04", {128, 512}, p_int32, a_input);
    buffer buf0("buf0", {128, 512, 512}, p_int32, a_output);
    
    input00.store_in(&buf00);
    input01.store_in(&buf01);
    input02.store_in(&buf02);
    input03.store_in(&buf03);
    input04.store_in(&buf04);
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf00, &buf01, &buf02, &buf03, &buf04, &buf0}, "../data/programs/function65552/function65552_schedule_0/function65552_schedule_0.o");

    return 0;
}