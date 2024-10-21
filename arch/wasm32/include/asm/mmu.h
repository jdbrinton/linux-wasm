#ifndef _ASM_WASM32_MMU_H
#define _ASM_WASM32_MMU_H

#include <linux/mm_types.h>
#include <linux/sched.h>
#include <asm/thread_info.h>


typedef struct {
    u64 ctx_id;
    unsigned long end_brk;  /* End of the program break (heap) */
} mm_context_t;


static inline struct page *virt_to_page(const void *x)
{
    return NULL;
}

static inline unsigned long virt_to_pfn(const void *x)
{
    return 0;
}

static inline void switch_mm(struct mm_struct *prev_mm, struct mm_struct *next_mm, struct task_struct *tsk)
{
    if (prev_mm != next_mm) {
        tsk->active_mm = next_mm;
    }
}

static inline void finish_arch_switch_mm(struct mm_struct *prev_mm)
{
}

#endif /* _ASM_WASM32_MMU_H */