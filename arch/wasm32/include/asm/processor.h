#ifndef _ASM_WASM32_PROCESSOR_H
#define _ASM_WASM32_PROCESSOR_H

#include <linux/types.h>

/* mm_segment_t definition */
typedef struct {
    unsigned long seg;
} mm_segment_t;

struct task_struct;

struct pt_regs {
    unsigned long pc;
    unsigned long sp;
    unsigned long regs[29];
    unsigned long lr;
};

struct thread_struct {
    mm_segment_t addr_limit;
    struct pt_regs regs;
    unsigned long ksp; /* Kernel Stack Pointer */
};

// Define INIT_THREAD for your architecture
#define INIT_THREAD {                \
    .regs = {                        \
        .pc = 0,                     /* Program counter */       \
        .sp = 0,                     /* Stack pointer */         \
        .lr = 0,                     /* Link register */         \
        .regs = {0},                 /* General-purpose registers */  \
    },                               \
}

struct thread_info {
    unsigned long       flags;
    unsigned long       syscall_work;
    unsigned int        preempt_count;
    struct task_struct *task;
    u32                 status;
#ifdef CONFIG_SMP
    u32                 cpu;
#endif
    struct pt_regs regs;
    struct thread_struct thread;
};

static inline void cpu_relax(void)
{
    asm volatile("" ::: "memory");
}

static inline unsigned long __get_wchan(struct task_struct *p)
{
    return 0;  // Return 0 as WASM may not need to support wchan
}


#endif /* _ASM_WASM32_PROCESSOR_H */