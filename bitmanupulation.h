/* Set bit n in data */
#define bit_set(data, n)      ( (data) |=  (1UL << (n)) )
/* Clear bit n in data */
#define bit_clear(data, n)    ( (data) &= ~(1UL << (n)) )
/* Toggle bit n in data */
#define bit_toggle(data, n)   ( (data) ^=  (1UL << (n)) )
/* Read bit n (yields 0 or 1) */
#define bit_read(data, n)     ( (((data) >> (n)) & 0x01UL) )
/* Write bit n to bitvalue (0 or 1) */
#define bit_write(data, n, bitvalue) \
    ( (bitvalue) \
        ? bit_set(data, n)  \
        : bit_clear(data, n) )
/* Convenience: the mask for bit n */
#define bit(n)                (1UL << (n))
