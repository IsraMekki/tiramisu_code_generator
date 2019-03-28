#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function14445_schedule_39");

    constant c0("c0", 128), c1("c1", 256), c2("c2", 1024);

    var i0("i0", 0, c0), i1("i1", 0, c1), i2("i2", 0, c2), i01("i01"), i02("i02"), i03("i03"), i04("i04"), i05("i05"), i06("i06");

    input input00("input00", {i0, i2}, p_int32);

    computation comp0("comp0", {i0, i1, i2}, input00(i0, i2));
    
    comp0.tile(i0, i1, i2, 128, 64, 32, i01, i02, i03, i04, i05, i06);
    comp0.parallelize(i01);
    
    buffer buf00("buf00", {128, 1024}, p_int32, a_input);
    buffer buf0("buf0", {128, 256, 1024}, p_int32, a_output);
    
    input00.store_in(&buf00);
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf00, &buf0}, "../data/programs/function14445/function14445_schedule_39/function14445_schedule_39.o");

    return 0;
}