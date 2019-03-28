#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function14345_no_schedule");

    constant c0("c0", 8192), c1("c1", 8192);

    var i0("i0", 0, c0), i1("i1", 0, c1);

    computation comp0("comp0", {i0, i1}, 6 + 4 * 9);
    
    comp0.parallelize(i0);
    
    buffer buf0("buf0", {8192, 8192}, p_int32, a_output);
    
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf0}, "../data/programs/function14345/function14345_no_schedule/function14345_no_schedule.o");

    return 0;
}