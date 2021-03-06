#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function13776_no_schedule");

    constant c0("c0", 2048), c1("c1", 32768);

    var i0("i0", 0, c0), i1("i1", 0, c1);

    computation comp0("comp0", {i0, i1}, 8 * 3 - 4);
    
    comp0.parallelize(i0);
    
    buffer buf0("buf0", {2048, 32768}, p_int32, a_output);
    
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf0}, "../data/programs/function13776/function13776_no_schedule/function13776_no_schedule.o");

    return 0;
}