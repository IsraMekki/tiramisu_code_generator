#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function13973_schedule_1");

    constant c0("c0", 131072), c1("c1", 512);

    var i0("i0", 0, c0), i1("i1", 0, c1), i01("i01"), i02("i02"), i03("i03"), i04("i04");

    computation comp0("comp0", {i0, i1}, 0 + 6 + 6);
    
    comp0.tile(i0, i1, 32, 64, i01, i02, i03, i04);
    comp0.parallelize(i01);
    
    buffer buf0("buf0", {131072, 512}, p_int32, a_output);
    
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf0}, "../data/programs/function13973/function13973_schedule_1/function13973_schedule_1.o");

    return 0;
}