#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function73944_schedule_2");

    constant c0("c0", 128), c1("c1", 512), c2("c2", 1024);

    var i0("i0", 0, c0), i1("i1", 0, c1), i2("i2", 0, c2);

    computation comp0("comp0", {i0, i1, i2}, 5 * 3 - 4);
    
    comp0.unroll(i2, 16);
    comp0.parallelize(i0);
    
    buffer buf0("buf0", {128, 512, 1024}, p_int32, a_output);
    
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf0}, "../data/programs/function73944/function73944_schedule_2/function73944_schedule_2.o");

    return 0;
}