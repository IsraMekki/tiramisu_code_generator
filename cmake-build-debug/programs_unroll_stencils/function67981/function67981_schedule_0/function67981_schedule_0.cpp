#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function67981_schedule_0");

    constant c0("c0", 64), c1("c1", 64), c2("c2", 64), c3("c3", 64);

    var i0("i0", 0, c0), i1("i1", 0, c1), i2("i2", 0, c2), i3("i3", 0, c3);

    input input00("input00", {i1, i2, i3}, p_int32);

    input input01("input01", {i0, i2, i3}, p_int32);

    input input02("input02", {i3}, p_int32);

    input input03("input03", {i0}, p_int32);

    input input04("input04", {i0, i2}, p_int32);

    input input05("input05", {i1, i2}, p_int32);

    input input06("input06", {i1}, p_int32);

    input input07("input07", {i0, i2, i3}, p_int32);

    input input08("input08", {i2, i3}, p_int32);

    input input09("input09", {i0, i1, i3}, p_int32);

    computation comp0("comp0", {i0, i1, i2, i3}, input00(i1, i2, i3) * input01(i0, i2, i3) + input02(i3) - input03(i0) * input04(i0, i2) + input05(i1, i2) - input06(i1) + input07(i0, i2, i3) - input08(i2, i3) + input09(i0, i1, i3));
    
    comp0.unroll(i3, 4);
    comp0.parallelize(i0);
    
    buffer buf00("buf00", {64, 64, 64}, p_int32, a_input);
    buffer buf01("buf01", {64, 64, 64}, p_int32, a_input);
    buffer buf02("buf02", {64}, p_int32, a_input);
    buffer buf03("buf03", {64}, p_int32, a_input);
    buffer buf04("buf04", {64, 64}, p_int32, a_input);
    buffer buf05("buf05", {64, 64}, p_int32, a_input);
    buffer buf06("buf06", {64}, p_int32, a_input);
    buffer buf07("buf07", {64, 64, 64}, p_int32, a_input);
    buffer buf08("buf08", {64, 64}, p_int32, a_input);
    buffer buf09("buf09", {64, 64, 64}, p_int32, a_input);
    buffer buf0("buf0", {64, 64, 64, 64}, p_int32, a_output);
    
    input00.store_in(&buf00);
    input01.store_in(&buf01);
    input02.store_in(&buf02);
    input03.store_in(&buf03);
    input04.store_in(&buf04);
    input05.store_in(&buf05);
    input06.store_in(&buf06);
    input07.store_in(&buf07);
    input08.store_in(&buf08);
    input09.store_in(&buf09);
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf00, &buf01, &buf02, &buf03, &buf04, &buf05, &buf06, &buf07, &buf08, &buf09, &buf0}, "../data/programs/function67981/function67981_schedule_0/function67981_schedule_0.o");

    return 0;
}