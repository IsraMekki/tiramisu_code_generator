#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function66304_no_schedule");

    constant c0("c0", 1024), c1("c1", 256), c2("c2", 256);

    var i0("i0", 0, c0), i1("i1", 0, c1), i2("i2", 0, c2);

    computation comp0("comp0", {i0, i1, i2}, 9 - 7);
    
    comp0.parallelize(i0);
    
    buffer buf0("buf0", {1024, 256, 256}, p_int32, a_output);
    
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf0}, "../data/programs/function66304/function66304_no_schedule/function66304_no_schedule.o");

    return 0;
}