#ifndef _CHU_IO_RW_H_INCLUDED
#define _CHU_IO_RW_H_INCLUDED

#include <inttypes.h>  /* for uint32_t */

/* Ensure C linkage for C++ compilers */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * Read a 32‑bit MMIO register.
 * @param base_addr  Base address of the MMIO region
 * @param offset     Register index (word offset)
 */
#define io_read(base_addr, offset) \
    (*(volatile uint32_t *)(((base_addr) + 4U * (offset))))

/**
 * Write a 32‑bit MMIO register.
 * @param base_addr  Base address of the MMIO region
 * @param offset     Register index (word offset)
 * @param data       Value to write
 */
#define io_write(base_addr, offset, data) \
    (*(volatile uint32_t *)(((base_addr) + 4U * (offset))) = (data))

/**
 * Compute the base address for a given slot in an array of 32‑word slots.
 * @param mmio_base  Base address of the MMIO region
 * @param slot       Slot number
 */
#define get_slot_addr(mmio_base, slot) \
    ((uint32_t)((mmio_base) + (slot) * 32U * 4U))

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _CHU_IO_RW_H_INCLUDED */
