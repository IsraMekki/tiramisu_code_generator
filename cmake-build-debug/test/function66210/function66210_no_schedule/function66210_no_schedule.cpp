#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function66210_no_schedule");

    constant c0("c0", 1024), c1("c1", 64), c2("c2", 512);

    var i0("i0", 0, c0), i1("i1", 0, c1), i2("i2", 0, c2);

    input input00("input00", {i0, i1}, p_int32);

    computation comp0("comp0", {i0, i1, i2}, input00(i0, i1));
    
    comp0.parallelize(i0);
    
    buffer buf00("buf00", {1024, 64}, p_int32, a_input);
    buffer buf0("buf0", {1024, 64, 512}, p_int32, a_output);
    
    input00.store_in(&buf00);
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf00, &buf0}, "../data/programs/function66210/function66210_no_schedule/function66210_no_schedule.o");

    return 0;
}