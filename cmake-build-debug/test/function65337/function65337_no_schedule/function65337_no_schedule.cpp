#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function65337_no_schedule");

    constant c0("c0", 2048), c1("c1", 256), c2("c2", 128);

    var i0("i0", 0, c0), i1("i1", 0, c1), i2("i2", 0, c2);

    input input00("input00", {i0, i1}, p_int32);

    input input01("input01", {i1, i2}, p_int32);

    input input02("input02", {i1}, p_int32);

    computation comp0("comp0", {i0, i1, i2}, input00(i0, i1) - input01(i1, i2) - input02(i1));
    
    comp0.parallelize(i0);
    
    buffer buf00("buf00", {2048, 256}, p_int32, a_input);
    buffer buf01("buf01", {256, 128}, p_int32, a_input);
    buffer buf02("buf02", {256}, p_int32, a_input);
    buffer buf0("buf0", {2048, 256, 128}, p_int32, a_output);
    
    input00.store_in(&buf00);
    input01.store_in(&buf01);
    input02.store_in(&buf02);
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf00, &buf01, &buf02, &buf0}, "../data/programs/function65337/function65337_no_schedule/function65337_no_schedule.o");

    return 0;
}