#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function73410_schedule_0");

    constant c0("c0", 524288), c1("c1", 128);

    var i0("i0", 0, c0), i1("i1", 0, c1);

    computation comp0("comp0", {i0, i1}, 7 * 0 - 9);
    
    comp0.unroll(i1, 4);
    comp0.parallelize(i0);
    
    buffer buf0("buf0", {524288, 128}, p_int32, a_output);
    
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf0}, "../data/programs/function73410/function73410_schedule_0/function73410_schedule_0.o");

    return 0;
}