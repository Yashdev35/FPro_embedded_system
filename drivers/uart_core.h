# ifndef _UART_CORE_H_INCLUDED
# define _UART_CORE_H_INCLUDED
#include</home/yash/hardware/embedded System/cpp/FPro_Codes/robust_access/chu_io_rw.h>
# include </home/yash/hardware/embedded System/cpp/FPro_Codes/robust_access/chu_io_map.h>
class UartCore {
enum {
    RD_DATA_REG = 0 ,
DVSR_REG = 1,
WR_DATA_REG = 2 ,
RM_RD_DATA_REG = 3 // remove read data
};
/∗ masks ∗/
enum {
TX_FULL_FIELD = 0 x00000200 ,
RX_EMPT_FIELD = 0 x00000100 ,
RX_DATA_FIELD = 0 x000000ff
};
public :
/∗ methods ∗/
UartCore ( uint32_t core_base_addr );
~ UartCore ();
// b a s i c I /O a c c e s s
void set_baud_rate ( int baud );
int rx_fifo_empty ();
int tx_fifo_full ();
void tx_byte ( uint8_t byte );
int rx_byte ();
// d i s p l a y methods
void disp ( char ch );
void disp ( const char * str );
void disp ( int n , int base , int len );
void disp ( int n , int base );
void disp ( int n );
void disp ( double f , int digit );
void disp ( double f );
private :
uint32_t base_addr ;
int baud_rate ;
void disp_str ( const char * str );
};
# endif // UART CORE H INCLUDED