#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function14283_schedule_8");

    constant c0("c0", 524288), c1("c1", 128);

    var i0("i0", 0, c0), i1("i1", 0, c1), i01("i01"), i02("i02"), i03("i03"), i04("i04");

    input input00("input00", {i0}, p_int32);

    input input01("input01", {i1}, p_int32);

    input input02("input02", {i0}, p_int32);

    input input03("input03", {i0}, p_int32);

    input input04("input04", {i1}, p_int32);

    input input05("input05", {i0}, p_int32);

    computation comp0("comp0", {i0, i1}, input00(i0) + input01(i1) * input02(i0) * input03(i0) + input04(i1) + input05(i0));
    
    comp0.tile(i0, i1, 128, 128, i01, i02, i03, i04);
    comp0.parallelize(i01);
    
    buffer buf00("buf00", {524288}, p_int32, a_input);
    buffer buf01("buf01", {128}, p_int32, a_input);
    buffer buf02("buf02", {524288}, p_int32, a_input);
    buffer buf03("buf03", {524288}, p_int32, a_input);
    buffer buf04("buf04", {128}, p_int32, a_input);
    buffer buf05("buf05", {524288}, p_int32, a_input);
    buffer buf0("buf0", {524288, 128}, p_int32, a_output);
    
    input00.store_in(&buf00);
    input01.store_in(&buf01);
    input02.store_in(&buf02);
    input03.store_in(&buf03);
    input04.store_in(&buf04);
    input05.store_in(&buf05);
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf00, &buf01, &buf02, &buf03, &buf04, &buf05, &buf0}, "../data/programs/function14283/function14283_schedule_8/function14283_schedule_8.o");

    return 0;
}