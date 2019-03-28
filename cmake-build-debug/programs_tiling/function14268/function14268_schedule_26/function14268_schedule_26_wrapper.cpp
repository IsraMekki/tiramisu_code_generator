#include "Halide.h"
#include "function14268_schedule_26_wrapper.h"
#include "tiramisu/utils.h"
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <fstream>
#include <chrono>

#define MAX_RAND 200

int main(int, char **){
    Halide::Buffer<int32_t> buf00(512);

    
    Halide::Buffer<int32_t> buf01(512, 256);

    
    Halide::Buffer<int32_t> buf02(512, 256);

    
    Halide::Buffer<int32_t> buf03(512, 512);

    
    Halide::Buffer<int32_t> buf04(512);

    
    Halide::Buffer<int32_t> buf05(256);

    
    Halide::Buffer<int32_t> buf06(512, 512);

    Halide::Buffer<int32_t> buf0(512, 512, 256);
    init_buffer(buf0, (int32_t)0);

    
    auto t1 = std::chrono::high_resolution_clock::now();

    function14268_schedule_26(buf00.raw_buffer(), buf01.raw_buffer(), buf02.raw_buffer(), buf03.raw_buffer(), buf04.raw_buffer(), buf05.raw_buffer(), buf06.raw_buffer(), buf0.raw_buffer());

    auto t2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> diff = t2 - t1;

    std::ofstream exec_times_file;
    exec_times_file.open("../data/programs/function14268/function14268_schedule_26/exec_times.txt", std::ios_base::app);
    if (exec_times_file.is_open()){
        exec_times_file << diff.count() * 1000000 << "us" <<std::endl;
        exec_times_file.close();
    }

    return 0;
}