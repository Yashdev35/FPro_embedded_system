#include<iostream>
#include</home/yash/hardware/embedded System/cpp/FPro_Codes/robust_access/chu_io_rw.h>
#include</home/yash/hardware/embedded System/cpp/FPro_Codes/bitmanupulation.h>
#include "/home/yash/hardware/embedded System/cpp/FPro_Codes/drivers/gpi.h"

GpiCore::GpiCore(uint32_t core_base_addr){
    base_addr = core_base_addr;
}

uint32_t GpiCore::read(){
    return io_read(base_addr,DATA_REG);//*(volatile int *p)((base_addr) + 4U*DATA_REG)
}

int GpiCore::read(int bit_pos){
    uint32_t read_data = io_read(base_addr,DATA_REG);
    return bit_read(read_data,bit_pos);
}