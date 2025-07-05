#ifndef _CHU_IO_MAP_INCLUDED
#define _CHU_IO_MAP_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

/* System clock frequency (MHz) */
#define SYS_CLK_FREQ   100U

/* I/O base address for MicroBlaze MCS */
#define BRIDGE_BASE    0xC0000000U

/* Slot module definitions */
#define S0_SYS_TIMER   0
#define S1_UART1       1
#define S2_LED         2
#define S3_SW          3

/* ...additional slot definitions for cores in Parts III and IV... */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _CHU_IO_MAP_INCLUDED */
