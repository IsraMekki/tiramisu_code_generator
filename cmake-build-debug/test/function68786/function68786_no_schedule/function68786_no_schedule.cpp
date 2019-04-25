#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function68786_no_schedule");

    constant c0("c0", 64), c1("c1", 64), c2("c2", 64), c3("c3", 64);

    var i0("i0", 0, c0), i1("i1", 0, c1), i2("i2", 0, c2), i3("i3", 0, c3);

    computation comp0("comp0", {i0, i1, i2, i3}, 5 + 0 * 5);
    
    comp0.parallelize(i0);
    
    buffer buf0("buf0", {64, 64, 64, 64}, p_int32, a_output);
    
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf0}, "../data/programs/function68786/function68786_no_schedule/function68786_no_schedule.o");

    return 0;
}