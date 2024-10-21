#ifndef _ASM_WASM32_CURRENT_H
#define _ASM_WASM32_CURRENT_H

#include <linux/types.h>
#include <asm/thread_info.h>

#define current (current_thread_info()->task)

#endif /* _ASM_WASM32_CURRENT_H */
