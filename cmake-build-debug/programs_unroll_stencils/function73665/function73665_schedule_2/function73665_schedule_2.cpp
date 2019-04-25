#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function73665_schedule_2");

    constant c0("c0", 128), c1("c1", 512), c2("c2", 512);

    var i0("i0", 0, c0), i1("i1", 0, c1), i2("i2", 0, c2);

    input input00("input00", {i1, i2}, p_int32);

    computation comp0("comp0", {i0, i1, i2}, input00(i1, i2));
    
    comp0.unroll(i2, 16);
    comp0.parallelize(i0);
    
    buffer buf00("buf00", {512, 512}, p_int32, a_input);
    buffer buf0("buf0", {128, 512, 512}, p_int32, a_output);
    
    input00.store_in(&buf00);
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf00, &buf0}, "../data/programs/function73665/function73665_schedule_2/function73665_schedule_2.o");

    return 0;
}