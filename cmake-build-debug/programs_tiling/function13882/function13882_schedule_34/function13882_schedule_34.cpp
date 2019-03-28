#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function13882_schedule_34");

    constant c0("c0", 128), c1("c1", 2048), c2("c2", 256);

    var i0("i0", 0, c0), i1("i1", 0, c1), i2("i2", 0, c2), i01("i01"), i02("i02"), i03("i03"), i04("i04"), i05("i05"), i06("i06");

    input input00("input00", {i2}, p_int32);

    input input01("input01", {i1, i2}, p_int32);

    input input02("input02", {i0, i2}, p_int32);

    input input03("input03", {i1}, p_int32);

    computation comp0("comp0", {i0, i1, i2}, input00(i2) - input01(i1, i2) * input02(i0, i2) * input03(i1));
    
    comp0.tile(i0, i1, i2, 64, 128, 64, i01, i02, i03, i04, i05, i06);
    comp0.parallelize(i01);
    
    buffer buf00("buf00", {256}, p_int32, a_input);
    buffer buf01("buf01", {2048, 256}, p_int32, a_input);
    buffer buf02("buf02", {128, 256}, p_int32, a_input);
    buffer buf03("buf03", {2048}, p_int32, a_input);
    buffer buf0("buf0", {128, 2048, 256}, p_int32, a_output);
    
    input00.store_in(&buf00);
    input01.store_in(&buf01);
    input02.store_in(&buf02);
    input03.store_in(&buf03);
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf00, &buf01, &buf02, &buf03, &buf0}, "../data/programs/function13882/function13882_schedule_34/function13882_schedule_34.o");

    return 0;
}