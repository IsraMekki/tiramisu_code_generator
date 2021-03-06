#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function13970_no_schedule");

    constant c0("c0", 2097152), c1("c1", 64);

    var i0("i0", 0, c0), i1("i1", 0, c1), i100("i100", 1, c0 - 1), i101("i101", 1, c1 - 1);

    input input0("input0", {i0, i1}, p_int32);

    computation comp0("comp0", {i100, i101}, (input0(i100, i101) + input0(i100 + 1, i101) - input0(i100 - 1, i101)));
    
    comp0.parallelize(i100);
    
    buffer buf00("buf00", {2097152, 64}, p_int32, a_input);
    buffer buf0("buf0", {2097152, 64}, p_int32, a_output);
    
    input0.store_in(&buf00);
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf00, &buf0}, "../data/programs/function13970/function13970_no_schedule/function13970_no_schedule.o");

    return 0;
}