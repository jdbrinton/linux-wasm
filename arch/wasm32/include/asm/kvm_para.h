#ifndef _ASM_WASM32_KVM_PARA_H
#define _ASM_WASM32_KVM_PARA_H

#include <linux/types.h>

static inline bool kvm_para_available(void)
{
    return false;
}

static inline unsigned int kvm_arch_para_features(void)
{
    return 0;
}

static inline unsigned int kvm_arch_para_hints(void)
{
    return 0;
}

#endif /* _ASM_WASM32_KVM_PARA_H */
