#include "Halide.h"
#include "function13709_schedule_2_wrapper.h"
#include "tiramisu/utils.h"
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <fstream>
#include <chrono>

#define MAX_RAND 200

int main(int, char **){
    Halide::Buffer<int32_t> buf00(256, 512);

    
    Halide::Buffer<int32_t> buf01(512);

    
    Halide::Buffer<int32_t> buf02(256);

    
    Halide::Buffer<int32_t> buf03(512, 256);

    
    Halide::Buffer<int32_t> buf04(512);

    
    Halide::Buffer<int32_t> buf05(512, 512);

    
    Halide::Buffer<int32_t> buf06(256, 512);

    Halide::Buffer<int32_t> buf0(512, 256, 512);
    init_buffer(buf0, (int32_t)0);

    
    auto t1 = std::chrono::high_resolution_clock::now();

    function13709_schedule_2(buf00.raw_buffer(), buf01.raw_buffer(), buf02.raw_buffer(), buf03.raw_buffer(), buf04.raw_buffer(), buf05.raw_buffer(), buf06.raw_buffer(), buf0.raw_buffer());

    auto t2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> diff = t2 - t1;

    std::ofstream exec_times_file;
    exec_times_file.open("../data/programs/function13709/function13709_schedule_2/exec_times.txt", std::ios_base::app);
    if (exec_times_file.is_open()){
        exec_times_file << diff.count() * 1000000 << "us" <<std::endl;
        exec_times_file.close();
    }

    return 0;
}