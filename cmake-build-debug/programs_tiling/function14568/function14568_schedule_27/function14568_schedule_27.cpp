#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function14568_schedule_27");

    constant c0("c0", 64), c1("c1", 128), c2("c2", 64), c3("c3", 128);

    var i0("i0", 0, c0), i1("i1", 0, c1), i2("i2", 0, c2), i3("i3", 0, c3), i01("i01"), i02("i02"), i03("i03"), i04("i04"), i05("i05"), i06("i06");

    input input00("input00", {i3}, p_int32);

    computation comp0("comp0", {i0, i1, i2, i3}, input00(i3));
    
    comp0.tile(i1, i2, i3, 32, 64, 128, i01, i02, i03, i04, i05, i06);
    comp0.parallelize(i0);
    
    buffer buf00("buf00", {128}, p_int32, a_input);
    buffer buf0("buf0", {64, 128, 64, 128}, p_int32, a_output);
    
    input00.store_in(&buf00);
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf00, &buf0}, "../data/programs/function14568/function14568_schedule_27/function14568_schedule_27.o");

    return 0;
}