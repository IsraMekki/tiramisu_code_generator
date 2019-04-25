#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function71668_schedule_1");

    constant c0("c0", 128), c1("c1", 1048576);

    var i0("i0", 0, c0), i1("i1", 0, c1);

    input input00("input00", {i1}, p_int32);

    computation comp0("comp0", {i0, i1}, input00(i1));
    
    comp0.unroll(i1, 8);
    comp0.parallelize(i0);
    
    buffer buf00("buf00", {1048576}, p_int32, a_input);
    buffer buf0("buf0", {128, 1048576}, p_int32, a_output);
    
    input00.store_in(&buf00);
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf00, &buf0}, "../data/programs/function71668/function71668_schedule_1/function71668_schedule_1.o");

    return 0;
}