#ifndef _ASM_WASM32_MEMORY_H
#define _ASM_WASM32_MEMORY_H

#include <linux/const.h>
#include <linux/types.h>
#include <asm/thread_info.h>

/* Define the virtual memory layout for wasm32 */

/* Start of kernel virtual memory */
#define PAGE_OFFSET          _AC(0x00000000, UL)

/* Start and end of the vmalloc area (can be zero if unsupported) */
#define VMALLOC_START        _AC(0x20000000, UL)
#define VMALLOC_END          _AC(0x2FFFFFFF, UL)

/* Start and end of the ioremap area */
#define IOREMAP_START        _AC(0x30000000, UL)
#define IOREMAP_END          _AC(0x3FFFFFFF, UL)

/* Define empty ranges if not supported */
#if !defined(CONFIG_MMU)
#undef VMALLOC_START
#undef VMALLOC_END
#define VMALLOC_START        _AC(0x00000000, UL)
#define VMALLOC_END          _AC(0x00000000, UL)
#undef IOREMAP_START
#undef IOREMAP_END
#define IOREMAP_START        _AC(0x00000000, UL)
#define IOREMAP_END          _AC(0x00000000, UL)
#endif

/* Physical memory offset */
#define PHYS_OFFSET          _AC(0x00000000, UL)

/* Task size (user space address space limit) */
#define TASK_SIZE            (_AC(1, UL) << 32) /* 4 GB for 32-bit */
#define TASK_SIZE_MAX        (TASK_SIZE)            /* Maximum user space size */
#define TASK_SIZE_32         (TASK_SIZE)
#define TASK_SIZE_64         (TASK_SIZE)

#define HIGH_MEMORY     _AC(0xFFFFFFFF, UL)  /* End of kernel virtual memory */

extern void *high_memory;

/* Other necessary definitions */

#endif /* _ASM_WASM32_MEMORY_H */
