#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function67826_schedule_0");

    constant c0("c0", 2048), c1("c1", 256), c2("c2", 64);

    var i0("i0", 0, c0), i1("i1", 0, c1), i2("i2", 0, c2);

    computation comp0("comp0", {i0, i1, i2}, 5 - 2);
    
    comp0.unroll(i2, 4);
    comp0.parallelize(i0);
    
    buffer buf0("buf0", {2048, 256, 64}, p_int32, a_output);
    
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf0}, "../data/programs/function67826/function67826_schedule_0/function67826_schedule_0.o");

    return 0;
}