#include "Halide.h"
#include "function14715_schedule_20_wrapper.h"
#include "tiramisu/utils.h"
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <fstream>
#include <chrono>

#define MAX_RAND 200

int main(int, char **){
    Halide::Buffer<int32_t> buf00(256, 2048);

    
    Halide::Buffer<int32_t> buf01(256);

    
    Halide::Buffer<int32_t> buf02(256, 2048);

    
    Halide::Buffer<int32_t> buf03(2048);

    
    Halide::Buffer<int32_t> buf04(2048, 128);

    
    Halide::Buffer<int32_t> buf05(256);

    
    Halide::Buffer<int32_t> buf06(256);

    
    Halide::Buffer<int32_t> buf07(2048);

    
    Halide::Buffer<int32_t> buf08(128);

    
    Halide::Buffer<int32_t> buf09(2048, 128);

    Halide::Buffer<int32_t> buf0(256, 2048, 128);
    init_buffer(buf0, (int32_t)0);

    
    auto t1 = std::chrono::high_resolution_clock::now();

    function14715_schedule_20(buf00.raw_buffer(), buf01.raw_buffer(), buf02.raw_buffer(), buf03.raw_buffer(), buf04.raw_buffer(), buf05.raw_buffer(), buf06.raw_buffer(), buf07.raw_buffer(), buf08.raw_buffer(), buf09.raw_buffer(), buf0.raw_buffer());

    auto t2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> diff = t2 - t1;

    std::ofstream exec_times_file;
    exec_times_file.open("../data/programs/function14715/function14715_schedule_20/exec_times.txt", std::ios_base::app);
    if (exec_times_file.is_open()){
        exec_times_file << diff.count() * 1000000 << "us" <<std::endl;
        exec_times_file.close();
    }

    return 0;
}