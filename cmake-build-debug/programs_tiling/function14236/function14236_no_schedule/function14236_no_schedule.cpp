#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function14236_no_schedule");

    constant c0("c0", 2048), c1("c1", 32768);

    var i0("i0", 0, c0), i1("i1", 0, c1);

    input input00("input00", {i1}, p_int32);

    computation comp0("comp0", {i0, i1}, input00(i1));
    
    comp0.parallelize(i0);
    
    buffer buf00("buf00", {32768}, p_int32, a_input);
    buffer buf0("buf0", {2048, 32768}, p_int32, a_output);
    
    input00.store_in(&buf00);
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf00, &buf0}, "../data/programs/function14236/function14236_no_schedule/function14236_no_schedule.o");

    return 0;
}