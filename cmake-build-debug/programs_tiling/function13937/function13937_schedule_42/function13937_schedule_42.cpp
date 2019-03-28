#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function13937_schedule_42");

    constant c0("c0", 128), c1("c1", 512), c2("c2", 512);

    var i0("i0", 0, c0), i1("i1", 0, c1), i2("i2", 0, c2), i01("i01"), i02("i02"), i03("i03"), i04("i04"), i05("i05"), i06("i06");

    computation comp0("comp0", {i0, i1, i2}, 1 - 4 * 6);
    
    comp0.tile(i0, i1, i2, 128, 128, 32, i01, i02, i03, i04, i05, i06);
    comp0.parallelize(i01);
    
    buffer buf0("buf0", {128, 512, 512}, p_int32, a_output);
    
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf0}, "../data/programs/function13937/function13937_schedule_42/function13937_schedule_42.o");

    return 0;
}