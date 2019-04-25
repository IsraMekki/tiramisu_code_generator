#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function74309_schedule_2");

    constant c0("c0", 1024), c1("c1", 65536);

    var i0("i0", 0, c0), i1("i1", 0, c1);

    input input00("input00", {i0}, p_int32);

    input input01("input01", {i0}, p_int32);

    computation comp0("comp0", {i0, i1}, input00(i0) * input01(i0));
    
    comp0.unroll(i1, 16);
    comp0.parallelize(i0);
    
    buffer buf00("buf00", {1024}, p_int32, a_input);
    buffer buf01("buf01", {1024}, p_int32, a_input);
    buffer buf0("buf0", {1024, 65536}, p_int32, a_output);
    
    input00.store_in(&buf00);
    input01.store_in(&buf01);
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf00, &buf01, &buf0}, "../data/programs/function74309/function74309_schedule_2/function74309_schedule_2.o");

    return 0;
}