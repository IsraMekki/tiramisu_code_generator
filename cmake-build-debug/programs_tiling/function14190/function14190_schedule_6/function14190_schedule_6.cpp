#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function14190_schedule_6");

    constant c0("c0", 8192), c1("c1", 8192);

    var i0("i0", 0, c0), i1("i1", 0, c1), i100("i100", 2, c0 - 2), i101("i101", 2, c1 - 2), i01("i01"), i02("i02"), i03("i03"), i04("i04");

    input input0("input0", {i0, i1}, p_int32);

    computation comp0("comp0", {i100, i101}, (input0(i100, i101) - input0(i100 + 1, i101) + input0(i100 + 2, i101) - input0(i100 - 1, i101) - input0(i100 - 2, i101)));
    
    comp0.tile(i100, i101, 128, 32, i01, i02, i03, i04);
    comp0.parallelize(i01);
    
    buffer buf00("buf00", {8192, 8192}, p_int32, a_input);
    buffer buf0("buf0", {8192, 8192}, p_int32, a_output);
    
    input0.store_in(&buf00);
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf00, &buf0}, "../data/programs/function14190/function14190_schedule_6/function14190_schedule_6.o");

    return 0;
}