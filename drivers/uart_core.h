#ifndef UART_CORE_H_INCLUDED
#define UART_CORE_H_INCLUDED
#include</home/yash/hardware/embedded System/cpp/FPro_Codes/robust_access/chu_io_rw.h>
#include</home/yash/hardware/embedded System/cpp/FPro_Codes/robust_access/chu_io_map.h>

#include <cstdint>

class UartCore {
public:
    // Registers
    enum {
        RD_DATA_REG    = 0,  // read data register
        DVSR_REG       = 1,  // divisor register
        WR_DATA_REG    = 2,  // write data register
        RM_RD_DATA_REG = 3   // remove-read-data register
    };

    // Bit‑fields
    enum {
        TX_FULL_FIELD = 0x00000200,  // TX FIFO full indicator
        RX_EMPT_FIELD = 0x00000100,  // RX FIFO empty indicator
        RX_DATA_FIELD = 0x000000ff   // RX data mask
    };

    // Constructor / Destructor
    explicit UartCore(uint32_t core_base_addr);
    ~UartCore();

    // Configuration
    void set_baud_rate(int baud);

    // Status checks
    int rx_fifo_empty();
    int tx_fifo_full();

    // Data transfer
    void tx_byte(uint8_t byte);
    int  rx_byte();

    // Display helpers
    void disp(char ch);
    void disp(const char* str);
    void disp(int n, int base, int len);
    void disp(int n, int base);
    void disp(int n);
    void disp(double f, int digit);
    void disp(double f);

private:
    void disp_str(const char* str);
    uint32_t base_addr;
    int      baud_rate;
};
#endif // UART_CORE_H_INCLUDED