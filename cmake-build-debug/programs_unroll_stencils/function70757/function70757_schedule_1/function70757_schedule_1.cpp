#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function70757_schedule_1");

    constant c0("c0", 2048), c1("c1", 256), c2("c2", 128);

    var i0("i0", 0, c0), i1("i1", 0, c1), i2("i2", 0, c2);

    input input00("input00", {i1}, p_int32);

    input input01("input01", {i1, i2}, p_int32);

    input input02("input02", {i0, i1}, p_int32);

    input input03("input03", {i1}, p_int32);

    input input04("input04", {i0, i1}, p_int32);

    input input05("input05", {i1, i2}, p_int32);

    input input06("input06", {i2}, p_int32);

    input input07("input07", {i2}, p_int32);

    computation comp0("comp0", {i0, i1, i2}, input00(i1) + input01(i1, i2) + input02(i0, i1) - input03(i1) * input04(i0, i1) - input05(i1, i2) - input06(i2) * input07(i2));
    
    comp0.unroll(i2, 8);
    comp0.parallelize(i0);
    
    buffer buf00("buf00", {256}, p_int32, a_input);
    buffer buf01("buf01", {256, 128}, p_int32, a_input);
    buffer buf02("buf02", {2048, 256}, p_int32, a_input);
    buffer buf03("buf03", {256}, p_int32, a_input);
    buffer buf04("buf04", {2048, 256}, p_int32, a_input);
    buffer buf05("buf05", {256, 128}, p_int32, a_input);
    buffer buf06("buf06", {128}, p_int32, a_input);
    buffer buf07("buf07", {128}, p_int32, a_input);
    buffer buf0("buf0", {2048, 256, 128}, p_int32, a_output);
    
    input00.store_in(&buf00);
    input01.store_in(&buf01);
    input02.store_in(&buf02);
    input03.store_in(&buf03);
    input04.store_in(&buf04);
    input05.store_in(&buf05);
    input06.store_in(&buf06);
    input07.store_in(&buf07);
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf00, &buf01, &buf02, &buf03, &buf04, &buf05, &buf06, &buf07, &buf0}, "../data/programs/function70757/function70757_schedule_1/function70757_schedule_1.o");

    return 0;
}