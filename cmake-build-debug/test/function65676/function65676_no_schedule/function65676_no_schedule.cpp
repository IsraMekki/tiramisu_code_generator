#include <tiramisu/tiramisu.h>

using namespace tiramisu;

int main(int argc, char **argv){
    tiramisu::init("function65676_no_schedule");

    constant c0("c0", 512), c1("c1", 131072);

    var i0("i0", 0, c0), i1("i1", 0, c1);

    input input00("input00", {i1}, p_int32);

    input input01("input01", {i0}, p_int32);

    computation comp0("comp0", {i0, i1}, input00(i1) * input01(i0));
    
    comp0.parallelize(i0);
    
    buffer buf00("buf00", {131072}, p_int32, a_input);
    buffer buf01("buf01", {512}, p_int32, a_input);
    buffer buf0("buf0", {512, 131072}, p_int32, a_output);
    
    input00.store_in(&buf00);
    input01.store_in(&buf01);
    comp0.store_in(&buf0);

    tiramisu::codegen({&buf00, &buf01, &buf0}, "../data/programs/function65676/function65676_no_schedule/function65676_no_schedule.o");

    return 0;
}