#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function13860_schedule_0");

    constant c0("c0", 524288), c1("c1", 128);

    var i0("i0", 0, c0), i1("i1", 0, c1), i01("i01"), i02("i02"), i03("i03"), i04("i04");

    computation comp0("comp0", {i0, i1}, 5 * 4);
    
    comp0.tile(i0, i1, 32, 32, i01, i02, i03, i04);
    comp0.parallelize(i01);
    
    buffer buf0("buf0", {524288, 128}, p_int32, a_output);
    
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf0}, "../data/programs/function13860/function13860_schedule_0/function13860_schedule_0.o");

    return 0;
}