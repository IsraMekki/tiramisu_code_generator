#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function14656_schedule_36");

    constant c0("c0", 256), c1("c1", 1024), c2("c2", 128);

    var i0("i0", 0, c0), i1("i1", 0, c1), i2("i2", 0, c2), i01("i01"), i02("i02"), i03("i03"), i04("i04"), i05("i05"), i06("i06");

    input input00("input00", {i0}, p_int32);

    input input01("input01", {i0, i2}, p_int32);

    input input02("input02", {i0, i2}, p_int32);

    input input03("input03", {i1}, p_int32);

    input input04("input04", {i0, i1}, p_int32);

    computation comp0("comp0", {i0, i1, i2}, input00(i0) + input01(i0, i2) + input02(i0, i2) - input03(i1) * input04(i0, i1));
    
    comp0.tile(i0, i1, i2, 128, 32, 32, i01, i02, i03, i04, i05, i06);
    comp0.parallelize(i01);
    
    buffer buf00("buf00", {256}, p_int32, a_input);
    buffer buf01("buf01", {256, 128}, p_int32, a_input);
    buffer buf02("buf02", {256, 128}, p_int32, a_input);
    buffer buf03("buf03", {1024}, p_int32, a_input);
    buffer buf04("buf04", {256, 1024}, p_int32, a_input);
    buffer buf0("buf0", {256, 1024, 128}, p_int32, a_output);
    
    input00.store_in(&buf00);
    input01.store_in(&buf01);
    input02.store_in(&buf02);
    input03.store_in(&buf03);
    input04.store_in(&buf04);
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf00, &buf01, &buf02, &buf03, &buf04, &buf0}, "../data/programs/function14656/function14656_schedule_36/function14656_schedule_36.o");

    return 0;
}