#include<iostream>
#include</home/yash/hardware/embedded System/cpp/FPro_Codes/robust_access/chu_io_rw.h>
#include</home/yash/hardware/embedded System/cpp/FPro_Codes/bitmanupulation.h>
#include "/home/yash/hardware/embedded System/cpp/FPro_Codes/drivers/uart_core.h"

UartCore :: UartCore ( uint32_t core_base_addr ) {
base_addr = core_base_addr ;
set_baud_rate (9600); // d e f a u l t baud r a t e
}
void UartCore :: set_baud_rate ( int baud ) {
uint32_t dvsr ;
dvsr = SYS_CLK_FREQ *1000000 / 16 / baud - 1;
io_write ( base_addr , DVSR_REG , dvsr );
}

int UartCore :: rx_fifo_empty () {
uint32_t rd_word ;
int empty ;
rd_word = io_read ( base_addr , RD_DATA_REG );
empty = ( int ) ( rd_word & RX_EMPT_FIELD ) >> 8;
return ( empty );
}
int UartCore :: tx_fifo_full () {
uint32_t rd_word ;
int full ;
rd_word = io_read ( base_addr , RD_DATA_REG );
full = ( int ) ( rd_word & TX_FULL_FIELD ) >> 9;
return ( full );
}
void UartCore :: tx_byte ( uint8_t byte ) {
while ( tx_fifo_full ()) { }; // busy w a i t i n g
io_write ( base_addr , WR_DATA_REG , ( uint32_t ) byte );
}
int UartCore :: rx_byte () {
uint32_t data ;
if ( rx_fifo_empty ())
return ( -1);
else {
data = io_read ( base_addr , RD_DATA_REG ) & RX_DATA_FIELD ;
io_write ( base_addr , RM_RD_DATA_REG , 0); //dummy w r i t e
return (( int ) data );
}