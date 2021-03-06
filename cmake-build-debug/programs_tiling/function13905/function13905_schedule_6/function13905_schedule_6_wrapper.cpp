#include "Halide.h"
#include "function13905_schedule_6_wrapper.h"
#include "tiramisu/utils.h"
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <fstream>
#include <chrono>

#define MAX_RAND 200

int main(int, char **){
    Halide::Buffer<int32_t> buf00(512);

    
    Halide::Buffer<int32_t> buf01(1024);

    
    Halide::Buffer<int32_t> buf02(128);

    
    Halide::Buffer<int32_t> buf03(512, 1024);

    
    Halide::Buffer<int32_t> buf04(1024);

    
    Halide::Buffer<int32_t> buf05(128, 1024);

    
    Halide::Buffer<int32_t> buf06(512, 128);

    
    Halide::Buffer<int32_t> buf07(128);

    Halide::Buffer<int32_t> buf0(512, 128, 1024);
    init_buffer(buf0, (int32_t)0);

    
    auto t1 = std::chrono::high_resolution_clock::now();

    function13905_schedule_6(buf00.raw_buffer(), buf01.raw_buffer(), buf02.raw_buffer(), buf03.raw_buffer(), buf04.raw_buffer(), buf05.raw_buffer(), buf06.raw_buffer(), buf07.raw_buffer(), buf0.raw_buffer());

    auto t2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> diff = t2 - t1;

    std::ofstream exec_times_file;
    exec_times_file.open("../data/programs/function13905/function13905_schedule_6/exec_times.txt", std::ios_base::app);
    if (exec_times_file.is_open()){
        exec_times_file << diff.count() * 1000000 << "us" <<std::endl;
        exec_times_file.close();
    }

    return 0;
}