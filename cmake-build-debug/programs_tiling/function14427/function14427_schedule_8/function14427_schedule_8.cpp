#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function14427_schedule_8");

    constant c0("c0", 64), c1("c1", 64), c2("c2", 128), c3("c3", 64);

    var i0("i0", 0, c0), i1("i1", 0, c1), i2("i2", 0, c2), i3("i3", 0, c3), i100("i100", 2, c0 - 2), i101("i101", 2, c1 - 2), i102("i102", 2, c2 - 2), i103("i103", 2, c3 - 2), i01("i01"), i02("i02"), i03("i03"), i04("i04"), i05("i05"), i06("i06");

    input input0("input0", {i0, i1, i2, i3}, p_int32);

    computation comp0("comp0", {i100, i101, i102, i103}, (input0(i100, i101, i102, i103) + input0(i100 + 1, i101, i102, i103) - input0(i100 + 2, i101, i102, i103) + input0(i100 - 1, i101, i102, i103) - input0(i100 - 2, i101, i102, i103)));
    
    comp0.tile(i101, i102, i103, 32, 64, 32, i01, i02, i03, i04, i05, i06);
    comp0.parallelize(i100);
    
    buffer buf00("buf00", {64, 64, 128, 64}, p_int32, a_input);
    buffer buf0("buf0", {64, 64, 128, 64}, p_int32, a_output);
    
    input0.store_in(&buf00);
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf00, &buf0}, "../data/programs/function14427/function14427_schedule_8/function14427_schedule_8.o");

    return 0;
}