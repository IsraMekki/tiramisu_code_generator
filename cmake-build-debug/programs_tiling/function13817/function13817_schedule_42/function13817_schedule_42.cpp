#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function13817_schedule_42");

    constant c0("c0", 256), c1("c1", 128), c2("c2", 2048);

    var i0("i0", 0, c0), i1("i1", 0, c1), i2("i2", 0, c2), i01("i01"), i02("i02"), i03("i03"), i04("i04"), i05("i05"), i06("i06");

    input input00("input00", {i0}, p_int32);

    computation comp0("comp0", {i0, i1, i2}, input00(i0));
    
    comp0.tile(i0, i1, i2, 128, 128, 32, i01, i02, i03, i04, i05, i06);
    comp0.parallelize(i01);
    
    buffer buf00("buf00", {256}, p_int32, a_input);
    buffer buf0("buf0", {256, 128, 2048}, p_int32, a_output);
    
    input00.store_in(&buf00);
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf00, &buf0}, "../data/programs/function13817/function13817_schedule_42/function13817_schedule_42.o");

    return 0;
}