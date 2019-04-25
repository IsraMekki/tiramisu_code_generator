#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function71605_schedule_1");

    constant c0("c0", 512), c1("c1", 1024), c2("c2", 64);

    var i0("i0", 0, c0), i1("i1", 0, c1), i2("i2", 0, c2);

    input input00("input00", {i2}, p_int32);

    input input01("input01", {i1, i2}, p_int32);

    input input02("input02", {i0, i2}, p_int32);

    input input03("input03", {i0}, p_int32);

    input input04("input04", {i1}, p_int32);

    input input05("input05", {i0, i2}, p_int32);

    input input06("input06", {i0, i2}, p_int32);

    computation comp0("comp0", {i0, i1, i2}, input00(i2) * input01(i1, i2) - input02(i0, i2) + input03(i0) * input04(i1) * input05(i0, i2) * input06(i0, i2));
    
    comp0.unroll(i2, 8);
    comp0.parallelize(i0);
    
    buffer buf00("buf00", {64}, p_int32, a_input);
    buffer buf01("buf01", {1024, 64}, p_int32, a_input);
    buffer buf02("buf02", {512, 64}, p_int32, a_input);
    buffer buf03("buf03", {512}, p_int32, a_input);
    buffer buf04("buf04", {1024}, p_int32, a_input);
    buffer buf05("buf05", {512, 64}, p_int32, a_input);
    buffer buf06("buf06", {512, 64}, p_int32, a_input);
    buffer buf0("buf0", {512, 1024, 64}, p_int32, a_output);
    
    input00.store_in(&buf00);
    input01.store_in(&buf01);
    input02.store_in(&buf02);
    input03.store_in(&buf03);
    input04.store_in(&buf04);
    input05.store_in(&buf05);
    input06.store_in(&buf06);
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf00, &buf01, &buf02, &buf03, &buf04, &buf05, &buf06, &buf0}, "../data/programs/function71605/function71605_schedule_1/function71605_schedule_1.o");

    return 0;
}