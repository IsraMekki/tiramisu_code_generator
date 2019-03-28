#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function14507_schedule_7");

    constant c0("c0", 32768), c1("c1", 2048);

    var i0("i0", 0, c0), i1("i1", 0, c1), i01("i01"), i02("i02"), i03("i03"), i04("i04");

    input input00("input00", {i0}, p_int32);

    computation comp0("comp0", {i0, i1}, input00(i0));
    
    comp0.tile(i0, i1, 128, 64, i01, i02, i03, i04);
    comp0.parallelize(i01);
    
    buffer buf00("buf00", {32768}, p_int32, a_input);
    buffer buf0("buf0", {32768, 2048}, p_int32, a_output);
    
    input00.store_in(&buf00);
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf00, &buf0}, "../data/programs/function14507/function14507_schedule_7/function14507_schedule_7.o");

    return 0;
}