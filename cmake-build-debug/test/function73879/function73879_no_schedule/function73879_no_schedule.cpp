#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function73879_no_schedule");

    constant c0("c0", 1024), c1("c1", 65536);

    var i0("i0", 0, c0), i1("i1", 0, c1);

    input input00("input00", {i0}, p_int32);

    input input01("input01", {i0}, p_int32);

    input input02("input02", {i1}, p_int32);

    input input03("input03", {i0}, p_int32);

    input input04("input04", {i1}, p_int32);

    computation comp0("comp0", {i0, i1}, input00(i0) * input01(i0) - input02(i1) * input03(i0) * input04(i1));
    
    comp0.parallelize(i0);
    
    buffer buf00("buf00", {1024}, p_int32, a_input);
    buffer buf01("buf01", {1024}, p_int32, a_input);
    buffer buf02("buf02", {65536}, p_int32, a_input);
    buffer buf03("buf03", {1024}, p_int32, a_input);
    buffer buf04("buf04", {65536}, p_int32, a_input);
    buffer buf0("buf0", {1024, 65536}, p_int32, a_output);
    
    input00.store_in(&buf00);
    input01.store_in(&buf01);
    input02.store_in(&buf02);
    input03.store_in(&buf03);
    input04.store_in(&buf04);
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf00, &buf01, &buf02, &buf03, &buf04, &buf0}, "../data/programs/function73879/function73879_no_schedule/function73879_no_schedule.o");

    return 0;
}