#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function68009_schedule_1");

    constant c0("c0", 128), c1("c1", 1024), c2("c2", 512);

    var i0("i0", 0, c0), i1("i1", 0, c1), i2("i2", 0, c2);

    computation comp0("comp0", {i0, i1, i2}, 1 - 8);
    
    comp0.unroll(i2, 8);
    comp0.parallelize(i0);
    
    buffer buf0("buf0", {128, 1024, 512}, p_int32, a_output);
    
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf0}, "../data/programs/function68009/function68009_schedule_1/function68009_schedule_1.o");

    return 0;
}