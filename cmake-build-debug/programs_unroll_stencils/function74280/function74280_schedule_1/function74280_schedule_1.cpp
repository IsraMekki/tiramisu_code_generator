#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function74280_schedule_1");

    constant c0("c0", 131072), c1("c1", 512);

    var i0("i0", 0, c0), i1("i1", 0, c1);

    computation comp0("comp0", {i0, i1}, 1 + 5);
    
    comp0.unroll(i1, 8);
    comp0.parallelize(i0);
    
    buffer buf0("buf0", {131072, 512}, p_int32, a_output);
    
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf0}, "../data/programs/function74280/function74280_schedule_1/function74280_schedule_1.o");

    return 0;
}