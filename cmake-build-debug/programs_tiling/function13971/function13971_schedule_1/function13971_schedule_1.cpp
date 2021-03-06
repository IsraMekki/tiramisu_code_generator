#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function13971_schedule_1");

    constant c0("c0", 128), c1("c1", 524288);

    var i0("i0", 0, c0), i1("i1", 0, c1), i01("i01"), i02("i02"), i03("i03"), i04("i04");

    input input00("input00", {i0}, p_int32);

    input input01("input01", {i0}, p_int32);

    input input02("input02", {i0}, p_int32);

    computation comp0("comp0", {i0, i1}, input00(i0) - input01(i0) + input02(i0));
    
    comp0.tile(i0, i1, 32, 64, i01, i02, i03, i04);
    comp0.parallelize(i01);
    
    buffer buf00("buf00", {128}, p_int32, a_input);
    buffer buf01("buf01", {128}, p_int32, a_input);
    buffer buf02("buf02", {128}, p_int32, a_input);
    buffer buf0("buf0", {128, 524288}, p_int32, a_output);
    
    input00.store_in(&buf00);
    input01.store_in(&buf01);
    input02.store_in(&buf02);
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf00, &buf01, &buf02, &buf0}, "../data/programs/function13971/function13971_schedule_1/function13971_schedule_1.o");

    return 0;
}