#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function65527_schedule_0");

    constant c0("c0", 4096), c1("c1", 16384);

    var i0("i0", 0, c0), i1("i1", 0, c1);

    computation comp0("comp0", {i0, i1}, 1 + 5 * 6);
    
    comp0.unroll(i1, 4);
    comp0.parallelize(i0);
    
    buffer buf0("buf0", {4096, 16384}, p_int32, a_output);
    
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf0}, "../data/programs/function65527/function65527_schedule_0/function65527_schedule_0.o");

    return 0;
}