#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function14145_schedule_3");

    constant c0("c0", 4096), c1("c1", 16384);

    var i0("i0", 0, c0), i1("i1", 0, c1), i100("i100", 1, c0 - 1), i101("i101", 1, c1 - 1), i01("i01"), i02("i02"), i03("i03"), i04("i04");

    input input0("input0", {i0, i1}, p_int32);

    computation comp0("comp0", {i100, i101}, (input0(i100, i101) + input0(i100 + 1, i101) - input0(i100 - 1, i101)));
    
    comp0.tile(i100, i101, 64, 32, i01, i02, i03, i04);
    comp0.parallelize(i01);
    
    buffer buf00("buf00", {4096, 16384}, p_int32, a_input);
    buffer buf0("buf0", {4096, 16384}, p_int32, a_output);
    
    input0.store_in(&buf00);
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf00, &buf0}, "../data/programs/function14145/function14145_schedule_3/function14145_schedule_3.o");

    return 0;
}