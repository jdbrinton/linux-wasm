#ifndef _ASM_WASM32_BUG_H
#define _ASM_WASM32_BUG_H

#include <linux/compiler.h>
#include <linux/build_bug.h>
#include <asm-generic/bug.h>
#include <asm/signal.h>
#include <linux/instruction_pointer.h>


/* Override _THIS_IP_ since WebAssembly doesn't support retrieving the instruction pointer */
// #define _THIS_IP_ (0UL)

/* Optionally override __WARN to match the expected number of arguments */
#undef __WARN
#define __WARN()                                                        \
        __warn(__FILE__, __LINE__, (void*)_THIS_IP_, 0,                        \
               NULL, NULL)

/* You can also override other macros or provide additional definitions as needed */

#endif /* _ASM_WASM32_BUG_H */
