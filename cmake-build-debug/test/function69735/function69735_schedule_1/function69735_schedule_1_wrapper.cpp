#include "Halide.h"
#include "function69735_schedule_1_wrapper.h"
#include "tiramisu/utils.h"
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <fstream>
#include <chrono>

#define MAX_RAND 200

int main(int, char **){
    Halide::Buffer<int32_t> buf00(32768);

    
    Halide::Buffer<int32_t> buf01(32768);

    
    Halide::Buffer<int32_t> buf02(2048);

    
    Halide::Buffer<int32_t> buf03(32768);

    
    Halide::Buffer<int32_t> buf04(32768);

    
    Halide::Buffer<int32_t> buf05(2048);

    
    Halide::Buffer<int32_t> buf06(2048);

    
    Halide::Buffer<int32_t> buf07(2048);

    
    Halide::Buffer<int32_t> buf08(32768);

    
    Halide::Buffer<int32_t> buf09(32768);

    Halide::Buffer<int32_t> buf0(2048, 32768);
    init_buffer(buf0, (int32_t)0);

    
    auto t1 = std::chrono::high_resolution_clock::now();

    function69735_schedule_1(buf00.raw_buffer(), buf01.raw_buffer(), buf02.raw_buffer(), buf03.raw_buffer(), buf04.raw_buffer(), buf05.raw_buffer(), buf06.raw_buffer(), buf07.raw_buffer(), buf08.raw_buffer(), buf09.raw_buffer(), buf0.raw_buffer());

    auto t2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> diff = t2 - t1;

    std::ofstream exec_times_file;
    exec_times_file.open("../data/programs/function69735/function69735_schedule_1/exec_times.txt", std::ios_base::app);
    if (exec_times_file.is_open()){
        exec_times_file << diff.count() * 1000000 << "us" <<std::endl;
        exec_times_file.close();
    }

    return 0;
}