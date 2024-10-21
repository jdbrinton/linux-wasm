#ifndef _ASM_WASM32_PREEMPT_H
#define _ASM_WASM32_PREEMPT_H

#include <asm/thread_info.h>

#define PREEMPT_ENABLED  0  // Define it as 0 if preemption is not supported in WASM
// #define PREEMPT_DISABLED 1


static inline unsigned int preempt_count(void)
{
    return current_thread_info()->preempt_count;
}

static inline void preempt_count_add(int val)
{
    current_thread_info()->preempt_count += val;
}

static inline void __preempt_count_add(int val)
{
    current_thread_info()->preempt_count += val;
}

static inline void preempt_count_sub(int val)
{
    current_thread_info()->preempt_count -= val;
}

static inline void __preempt_count_sub(int val)
{
    current_thread_info()->preempt_count -= val;
}

static inline void preempt_count_inc(void)
{
    preempt_count_add(1);
}

static inline void preempt_count_dec(void)
{
    preempt_count_sub(1);
}

static inline void preempt_count_set(int pc)
{
    current_thread_info()->preempt_count = pc;
}

static inline void preempt_disable(void)
{
    preempt_count_inc();
}

static inline void preempt_enable_no_resched(void)
{
    preempt_count_sub(1);
}

static inline void preempt_enable(void)
{
    preempt_enable_no_resched();
}

static inline void preempt_disable_notrace(void)
{
    preempt_disable();
}

static inline void preempt_enable_notrace(void)
{
    preempt_enable();
}

static inline int preemptible(void)
{
    return preempt_count() == 0;
}

static inline void set_preempt_need_resched(void)
{
    set_ti_thread_flag(current_thread_info(), TIF_NEED_RESCHED);
}

static inline void clear_preempt_need_resched(void)
{
    clear_ti_thread_flag(current_thread_info(), TIF_NEED_RESCHED);
}

static inline int test_preempt_need_resched(void)
{
    return test_ti_thread_flag(current_thread_info(), TIF_NEED_RESCHED);
}

static inline void init_task_preempt_count(struct task_struct *p)
{
    // No-op for WASM
}

static inline int should_resched(int preempt_offset)
{
    // Stubbed out for WASM, return 0 to indicate no need for rescheduling
    return 0;
}

static inline void init_idle_preempt_count(struct task_struct *idle, int cpu)
{
    // No-op for WASM
}




#endif /* _ASM_WASM32_PREEMPT_H */