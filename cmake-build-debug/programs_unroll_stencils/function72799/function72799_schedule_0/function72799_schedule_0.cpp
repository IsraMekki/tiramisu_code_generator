#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function72799_schedule_0");

    constant c0("c0", 512), c1("c1", 128), c2("c2", 512);

    var i0("i0", 0, c0), i1("i1", 0, c1), i2("i2", 0, c2);

    input input00("input00", {i2}, p_int32);

    input input01("input01", {i2}, p_int32);

    input input02("input02", {i0, i2}, p_int32);

    input input03("input03", {i0, i2}, p_int32);

    computation comp0("comp0", {i0, i1, i2}, input00(i2) * input01(i2) - input02(i0, i2) * input03(i0, i2));
    
    comp0.unroll(i2, 4);
    comp0.parallelize(i0);
    
    buffer buf00("buf00", {512}, p_int32, a_input);
    buffer buf01("buf01", {512}, p_int32, a_input);
    buffer buf02("buf02", {512, 512}, p_int32, a_input);
    buffer buf03("buf03", {512, 512}, p_int32, a_input);
    buffer buf0("buf0", {512, 128, 512}, p_int32, a_output);
    
    input00.store_in(&buf00);
    input01.store_in(&buf01);
    input02.store_in(&buf02);
    input03.store_in(&buf03);
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf00, &buf01, &buf02, &buf03, &buf0}, "../data/programs/function72799/function72799_schedule_0/function72799_schedule_0.o");

    return 0;
}