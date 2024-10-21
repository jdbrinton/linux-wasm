#ifndef _ASM_WASM32_BYTEORDER_H
#define _ASM_WASM32_BYTEORDER_H

#include <linux/byteorder/little_endian.h>
#include <linux/types.h>

#define __LITTLE_ENDIAN 1234
#define __BIG_ENDIAN    4321
#define __BYTE_ORDER __LITTLE_ENDIAN

#define __LITTLE_ENDIAN_BITFIELD

#endif /* _ASM_WASM32_BYTEORDER_H */