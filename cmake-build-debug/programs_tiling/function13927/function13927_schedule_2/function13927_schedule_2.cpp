#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function13927_schedule_2");

    constant c0("c0", 32768), c1("c1", 2048);

    var i0("i0", 0, c0), i1("i1", 0, c1), i01("i01"), i02("i02"), i03("i03"), i04("i04");

    input input00("input00", {i1}, p_int32);

    input input01("input01", {i0}, p_int32);

    input input02("input02", {i1}, p_int32);

    input input03("input03", {i1}, p_int32);

    input input04("input04", {i0}, p_int32);

    input input05("input05", {i0}, p_int32);

    computation comp0("comp0", {i0, i1}, input00(i1) * input01(i0) * input02(i1) - input03(i1) + input04(i0) - input05(i0));
    
    comp0.tile(i0, i1, 32, 128, i01, i02, i03, i04);
    comp0.parallelize(i01);
    
    buffer buf00("buf00", {2048}, p_int32, a_input);
    buffer buf01("buf01", {32768}, p_int32, a_input);
    buffer buf02("buf02", {2048}, p_int32, a_input);
    buffer buf03("buf03", {2048}, p_int32, a_input);
    buffer buf04("buf04", {32768}, p_int32, a_input);
    buffer buf05("buf05", {32768}, p_int32, a_input);
    buffer buf0("buf0", {32768, 2048}, p_int32, a_output);
    
    input00.store_in(&buf00);
    input01.store_in(&buf01);
    input02.store_in(&buf02);
    input03.store_in(&buf03);
    input04.store_in(&buf04);
    input05.store_in(&buf05);
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf00, &buf01, &buf02, &buf03, &buf04, &buf05, &buf0}, "../data/programs/function13927/function13927_schedule_2/function13927_schedule_2.o");

    return 0;
}