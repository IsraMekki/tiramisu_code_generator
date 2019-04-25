#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function74696_schedule_2");

    constant c0("c0", 32768), c1("c1", 2048);

    var i0("i0", 0, c0), i1("i1", 0, c1);

    computation comp0("comp0", {i0, i1}, 0 * 0 * 8);
    
    comp0.unroll(i1, 16);
    comp0.parallelize(i0);
    
    buffer buf0("buf0", {32768, 2048}, p_int32, a_output);
    
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf0}, "../data/programs/function74696/function74696_schedule_2/function74696_schedule_2.o");

    return 0;
}