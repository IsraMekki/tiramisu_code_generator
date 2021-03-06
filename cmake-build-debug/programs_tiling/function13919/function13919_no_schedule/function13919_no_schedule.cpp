#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function13919_no_schedule");

    constant c0("c0", 4096), c1("c1", 16384);

    var i0("i0", 0, c0), i1("i1", 0, c1);

    input input00("input00", {i0}, p_int32);

    input input01("input01", {i1}, p_int32);

    input input02("input02", {i0}, p_int32);

    input input03("input03", {i0}, p_int32);

    computation comp0("comp0", {i0, i1}, input00(i0) + input01(i1) - input02(i0) + input03(i0));
    
    comp0.parallelize(i0);
    
    buffer buf00("buf00", {4096}, p_int32, a_input);
    buffer buf01("buf01", {16384}, p_int32, a_input);
    buffer buf02("buf02", {4096}, p_int32, a_input);
    buffer buf03("buf03", {4096}, p_int32, a_input);
    buffer buf0("buf0", {4096, 16384}, p_int32, a_output);
    
    input00.store_in(&buf00);
    input01.store_in(&buf01);
    input02.store_in(&buf02);
    input03.store_in(&buf03);
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf00, &buf01, &buf02, &buf03, &buf0}, "../data/programs/function13919/function13919_no_schedule/function13919_no_schedule.o");

    return 0;
}