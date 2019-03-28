#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function14564_schedule_4");

    constant c0("c0", 4096), c1("c1", 16384);

    var i0("i0", 0, c0), i1("i1", 0, c1), i01("i01"), i02("i02"), i03("i03"), i04("i04");

    computation comp0("comp0", {i0, i1}, 3 + 2 - 6);
    
    comp0.tile(i0, i1, 64, 64, i01, i02, i03, i04);
    comp0.parallelize(i01);
    
    buffer buf0("buf0", {4096, 16384}, p_int32, a_output);
    
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf0}, "../data/programs/function14564/function14564_schedule_4/function14564_schedule_4.o");

    return 0;
}