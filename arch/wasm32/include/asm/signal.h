#ifndef _ASM_WASM32_SIGNAL_H
#define _ASM_WASM32_SIGNAL_H

#include <linux/types.h>
#include <linux/compiler.h>
#include <uapi/asm-generic/signal-defs.h> /* For internal kernel signal definitions */
#include <uapi/asm/signal.h>   /* User-space signal definitions */

/* Kernel-specific sigset_t definition */
typedef struct {
    unsigned long sig[_NSIG_WORDS];
} kernel_sigset_t;


/* Architecture-specific signal flags (if any) */
// #define SA_EXPOSE_TAGBITS    0x00000000u /* Unsupported in wasm32 */
// #define SA_UNSUPPORTED       SA_EXPOSE_TAGBITS

/* Define __ARCH_UAPI_SA_FLAGS */
#define __ARCH_UAPI_SA_FLAGS 0u

#endif /* _ASM_WASM32_SIGNAL_H */
