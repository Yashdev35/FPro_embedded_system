#include<iostream>
#include</home/yash/hardware/embedded System/cpp/FPro_Codes/robust_access/chu_io_rw.h>
#include</home/yash/hardware/embedded System/cpp/FPro_Codes/bitmanupulation.h>
#include "/home/yash/hardware/embedded System/cpp/FPro_Codes/drivers/gpo.h"

GpoCore::GpoCore(uint32_t core_base_addr){
    base_addr = core_base_addr;
    wr_data = 0;
}

GpoCore ::~GpoCore(){}

void GpoCore::write(uint32_t data){
    wr_data = data;
    io_write(base_addr,DATA_REG,wr_data);
}

void GpoCore::write(int bit_value, int bit_pos){
    bit_write(wr_data,bit_pos,bit_value);
    io_write(base_addr,DATA_REG,wr_data);
}