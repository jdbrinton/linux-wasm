#ifndef _ASM_WASM32_COMPILER_H
#define _ASM_WASM32_COMPILER_H

/* Only define _RET_IP_ if it's not already defined */
#ifndef _RET_IP_
#define _RET_IP_  ((unsigned long)0)
#endif

/* Override __builtin_return_address for WebAssembly */
#define __builtin_return_address(level)  ((void *)0)

#endif /* _ASM_WASM32_COMPILER_H */
