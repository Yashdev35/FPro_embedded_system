#include <inttypes.h>

class TimerCore{

    enum{
        COUNTER_LOWER_REG = 0,
        COUNTER_UPPER_REG = 1,
        CTRL_REG = 2
    };

    enum{
        EN = 0x00000001,
        CLR = 0x00000002
    };

public:
    TimerCore(uint32_t core_base_addr);
    ~TimerCore();

    void pause();
    void go();
    void clear();
    uint64_t read_tick();
    uint64_t read_time();
    void sleep(uint64_t us); //sleep for us microseconds

private:
    uint32_t base_addr;
    uint32_t ctrl;
};