#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function73344_no_schedule");

    constant c0("c0", 524288), c1("c1", 128);

    var i0("i0", 0, c0), i1("i1", 0, c1), i100("i100", 1, c0 - 1), i101("i101", 1, c1 - 1);

    input input0("input0", {i0, i1}, p_int32);

    computation comp0("comp0", {i100, i101}, (input0(i100, i101) - input0(i100 + 1, i101) + input0(i100 - 1, i101)));
    
    comp0.parallelize(i100);
    
    buffer buf00("buf00", {524288, 128}, p_int32, a_input);
    buffer buf0("buf0", {524288, 128}, p_int32, a_output);
    
    input0.store_in(&buf00);
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf00, &buf0}, "../data/programs/function73344/function73344_no_schedule/function73344_no_schedule.o");

    return 0;
}