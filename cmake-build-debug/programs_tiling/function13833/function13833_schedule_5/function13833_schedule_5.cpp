#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function13833_schedule_5");

    constant c0("c0", 512), c1("c1", 128), c2("c2", 1024);

    var i0("i0", 0, c0), i1("i1", 0, c1), i2("i2", 0, c2), i01("i01"), i02("i02"), i03("i03"), i04("i04");

    computation comp0("comp0", {i0, i1, i2}, 9 + 3);
    
    comp0.tile(i1, i2, 32, 128, i01, i02, i03, i04);
    comp0.parallelize(i0);
    
    buffer buf0("buf0", {512, 128, 1024}, p_int32, a_output);
    
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf0}, "../data/programs/function13833/function13833_schedule_5/function13833_schedule_5.o");

    return 0;
}