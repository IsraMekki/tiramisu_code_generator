#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function73208_no_schedule");

    constant c0("c0", 64), c1("c1", 1024), c2("c2", 512);

    var i0("i0", 0, c0), i1("i1", 0, c1), i2("i2", 0, c2);

    computation comp0("comp0", {i0, i1, i2}, 7 + 1);
    
    comp0.parallelize(i0);
    
    buffer buf0("buf0", {64, 1024, 512}, p_int32, a_output);
    
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf0}, "../data/programs/function73208/function73208_no_schedule/function73208_no_schedule.o");

    return 0;
}