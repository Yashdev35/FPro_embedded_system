#include <inttypes.h>

class GpiCore{

    enum{
        DATA_REG = 0
    };

public:
    GpiCore(uint32_t core_base_addr);
    ~GpiCore();

    uint32_t read();
    int read(int bit_pos);

private:
    uint32_t base_addr;
};