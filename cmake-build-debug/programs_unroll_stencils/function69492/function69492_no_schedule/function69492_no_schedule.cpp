#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function69492_no_schedule");

    constant c0("c0", 8192), c1("c1", 8192);

    var i0("i0", 0, c0), i1("i1", 0, c1);

    computation comp0("comp0", {i0, i1}, 7 * 7);
    
    comp0.parallelize(i0);
    
    buffer buf0("buf0", {8192, 8192}, p_int32, a_output);
    
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf0}, "../data/programs/function69492/function69492_no_schedule/function69492_no_schedule.o");

    return 0;
}