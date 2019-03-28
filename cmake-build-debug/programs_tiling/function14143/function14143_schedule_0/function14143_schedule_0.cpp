#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function14143_schedule_0");

    constant c0("c0", 64), c1("c1", 256), c2("c2", 2048);

    var i0("i0", 0, c0), i1("i1", 0, c1), i2("i2", 0, c2), i01("i01"), i02("i02"), i03("i03"), i04("i04");

    input input00("input00", {i0, i1}, p_int32);

    input input01("input01", {i0, i2}, p_int32);

    computation comp0("comp0", {i0, i1, i2}, input00(i0, i1) + input01(i0, i2));
    
    comp0.tile(i0, i1, 32, 32, i01, i02, i03, i04);
    comp0.parallelize(i01);
    
    buffer buf00("buf00", {64, 256}, p_int32, a_input);
    buffer buf01("buf01", {64, 2048}, p_int32, a_input);
    buffer buf0("buf0", {64, 256, 2048}, p_int32, a_output);
    
    input00.store_in(&buf00);
    input01.store_in(&buf01);
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf00, &buf01, &buf0}, "../data/programs/function14143/function14143_schedule_0/function14143_schedule_0.o");

    return 0;
}