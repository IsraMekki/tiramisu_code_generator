#include "Halide.h"
#include "function13805_schedule_30_wrapper.h"
#include "tiramisu/utils.h"
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <fstream>
#include <chrono>

#define MAX_RAND 200

int main(int, char **){
    Halide::Buffer<int32_t> buf00(64, 64);

    
    Halide::Buffer<int32_t> buf01(64);

    
    Halide::Buffer<int32_t> buf02(64);

    
    Halide::Buffer<int32_t> buf03(64, 128);

    
    Halide::Buffer<int32_t> buf04(128, 64, 64);

    
    Halide::Buffer<int32_t> buf05(128, 64);

    
    Halide::Buffer<int32_t> buf06(128);

    
    Halide::Buffer<int32_t> buf07(128);

    
    Halide::Buffer<int32_t> buf08(128, 64, 128);

    
    Halide::Buffer<int32_t> buf09(128, 64);

    Halide::Buffer<int32_t> buf0(128, 64, 64, 128);
    init_buffer(buf0, (int32_t)0);

    
    auto t1 = std::chrono::high_resolution_clock::now();

    function13805_schedule_30(buf00.raw_buffer(), buf01.raw_buffer(), buf02.raw_buffer(), buf03.raw_buffer(), buf04.raw_buffer(), buf05.raw_buffer(), buf06.raw_buffer(), buf07.raw_buffer(), buf08.raw_buffer(), buf09.raw_buffer(), buf0.raw_buffer());

    auto t2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> diff = t2 - t1;

    std::ofstream exec_times_file;
    exec_times_file.open("../data/programs/function13805/function13805_schedule_30/exec_times.txt", std::ios_base::app);
    if (exec_times_file.is_open()){
        exec_times_file << diff.count() * 1000000 << "us" <<std::endl;
        exec_times_file.close();
    }

    return 0;
}