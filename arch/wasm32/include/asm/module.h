#ifndef _ASM_WASM32_MODULE_H
#define _ASM_WASM32_MODULE_H

#include <asm/sections.h>
#include <linux/elf.h>

/* Define the architecture-specific module structure */
struct mod_arch_specific {
    /* Architecture-specific fields (currently empty for wasm32) */
};

#define dereference_function_descriptor(p) (p)

// Add any other architecture-specific definitions if necessary

#endif /* _ASM_WASM32_MODULE_H */
