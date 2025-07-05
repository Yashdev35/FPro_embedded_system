#include<iostream>
#include</home/yash/hardware/embedded System/cpp/FPro_Codes/robust_access/chu_io_rw.h>
#include</home/yash/hardware/embedded System/cpp/FPro_Codes/bitmanupulation.h>
#include "/home/yash/hardware/embedded System/cpp/FPro_Codes/drivers/timer.h"

TimerCore::TimerCore(uint32_t core_base_addr) {
    base_addr = core_base_addr;
    ctrl = 0;
}

TimerCore::~TimerCore() {}

void TimerCore::pause(){
    ctrl = ctrl & ~EN;
    io_write(base_addr,CTRL_REG,ctrl);
}

void TimerCore::go(){
    ctrl = ctrl | EN;
    io_write(base_addr,CTRL_REG,ctrl);
}

void TimerCore::clear(){
    uint32_t w_data = ctrl | CLR;
    io_write(base_addr,CTRL_REG,w_data);
}

uint64_t TimerCore::read_tick(){
    uint64_t lower, upper;
    lower = io_read(base_addr,COUNTER_LOWER_REG);
    upper = io_read(base_addr,COUNTER_UPPER_REG);
    return ((upper << 32) | lower);
}

uint64_t TimerCore::read_time() {
    uint64_t tick = read_tick();
    return tick / 100;
}  

void TimerCore::sleep(uint64_t us){
    uint64_t start_time,now;
    start_time = read_time();
    now = start_time;
    while((now - start_time) < us){
        now = read_time();
    }
}