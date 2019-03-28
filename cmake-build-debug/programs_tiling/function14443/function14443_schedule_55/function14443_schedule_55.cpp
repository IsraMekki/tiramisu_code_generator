#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function14443_schedule_55");

    constant c0("c0", 64), c1("c1", 128), c2("c2", 128), c3("c3", 64);

    var i0("i0", 0, c0), i1("i1", 0, c1), i2("i2", 0, c2), i3("i3", 0, c3), i01("i01"), i02("i02"), i03("i03"), i04("i04"), i05("i05"), i06("i06");

    computation comp0("comp0", {i0, i1, i2, i3}, 8 * 3 * 8);
    
    comp0.tile(i1, i2, i3, 128, 128, 32, i01, i02, i03, i04, i05, i06);
    comp0.parallelize(i0);
    
    buffer buf0("buf0", {64, 128, 128, 64}, p_int32, a_output);
    
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf0}, "../data/programs/function14443/function14443_schedule_55/function14443_schedule_55.o");

    return 0;
}