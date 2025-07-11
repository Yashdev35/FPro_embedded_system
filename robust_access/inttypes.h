/* inttypes.h - Fixed-width integer types and format specifiers */

#ifndef _INTTYPES_H
#define _INTTYPES_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Signed integer types */
typedef int8_t   int8_t;
typedef int16_t  int16_t;
typedef int32_t  int32_t;
typedef int64_t  int64_t;

/* Unsigned integer types */
typedef uint8_t  uint8_t;
typedef uint16_t uint16_t;
typedef uint32_t uint32_t;
typedef uint64_t uint64_t;

/* Format specifiers for printf */
#define PRId8    "hhd"
#define PRIi8    "hhi"
#define PRIo8    "hho"
#define PRIu8    "hhu"
#define PRIx8    "hhx"
#define PRIX8    "hhX"

#define PRId16   "hd"
#define PRIi16   "hi"
#define PRIo16   "ho"
#define PRIu16   "hu"
#define PRIx16   "hx"
#define PRIX16   "hX"

#define PRId32   "d"
#define PRIi32   "i"
#define PRIo32   "o"
#define PRIu32   "u"
#define PRIx32   "x"
#define PRIX32   "X"

#define PRId64   "lld"
#define PRIi64   "lli"
#define PRIo64   "llo"
#define PRIu64   "llu"
#define PRIx64   "llx"
#define PRIX64   "llX"

/* Format specifiers for scanf */
#define SCNd8    "hhd"
#define SCNi8    "hhi"
#define SCNo8    "hho"
#define SCNu8    "hhu"
#define SCNx8    "hhx"

#define SCNd16   "hd"
#define SCNi16   "hi"
#define SCNo16   "ho"
#define SCNu16   "hu"
#define SCNx16   "hx"

#define SCNd32   "d"
#define SCNi32   "i"
#define SCNo32   "o"
#define SCNu32   "u"
#define SCNx32   "x"

#define SCNd64   "lld"
#define SCNi64   "lli"
#define SCNo64   "llo"
#define SCNu64   "llu"
#define SCNx64   "llx"

#ifdef __cplusplus
}
#endif

#endif /* _INTTYPES_H */
