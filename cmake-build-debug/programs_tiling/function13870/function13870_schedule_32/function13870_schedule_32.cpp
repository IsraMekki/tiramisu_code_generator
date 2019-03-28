#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function13870_schedule_32");

    constant c0("c0", 64), c1("c1", 64), c2("c2", 64), c3("c3", 128);

    var i0("i0", 0, c0), i1("i1", 0, c1), i2("i2", 0, c2), i3("i3", 0, c3), i01("i01"), i02("i02"), i03("i03"), i04("i04"), i05("i05"), i06("i06");

    input input00("input00", {i0, i3}, p_int32);

    input input01("input01", {i2}, p_int32);

    input input02("input02", {i0, i1, i2}, p_int32);

    input input03("input03", {i1}, p_int32);

    input input04("input04", {i1, i0}, p_int32);

    input input05("input05", {i1, i3}, p_int32);

    computation comp0("comp0", {i0, i1, i2, i3}, input00(i0, i3) + input01(i2) * input02(i0, i1, i2) + input03(i1) * input04(i1, i0) * input05(i1, i3));
    
    comp0.tile(i1, i2, i3, 64, 64, 64, i01, i02, i03, i04, i05, i06);
    comp0.parallelize(i0);
    
    buffer buf00("buf00", {64, 128}, p_int32, a_input);
    buffer buf01("buf01", {64}, p_int32, a_input);
    buffer buf02("buf02", {64, 64, 64}, p_int32, a_input);
    buffer buf03("buf03", {64}, p_int32, a_input);
    buffer buf04("buf04", {64, 64}, p_int32, a_input);
    buffer buf05("buf05", {64, 128}, p_int32, a_input);
    buffer buf0("buf0", {64, 64, 64, 128}, p_int32, a_output);
    
    input00.store_in(&buf00);
    input01.store_in(&buf01);
    input02.store_in(&buf02);
    input03.store_in(&buf03);
    input04.store_in(&buf04);
    input05.store_in(&buf05);
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf00, &buf01, &buf02, &buf03, &buf04, &buf05, &buf0}, "../data/programs/function13870/function13870_schedule_32/function13870_schedule_32.o");

    return 0;
}