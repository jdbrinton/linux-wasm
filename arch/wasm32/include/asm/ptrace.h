#ifndef _ASM_WASM32_PTRACE_H
#define _ASM_WASM32_PTRACE_H

#include <linux/sched.h>
#include <linux/thread_info.h>

static inline int user_mode(const struct pt_regs *regs)
{
    return 0;
}

static inline struct pt_regs *task_pt_regs(struct task_struct *task)
{
    return &task_thread_info(task)->regs;
}

/* Return pointer to current pt_regs */
static inline struct pt_regs *current_pt_regs(void)
{
    /* Implement based on your architecture */
    return NULL; /* Placeholder */
}

/* Get user stack pointer from pt_regs */
static inline unsigned long user_stack_pointer(struct pt_regs *regs)
{
    if (regs)
        return regs->sp;
    return 0;
}

/* Define current_user_stack_pointer */
#define current_user_stack_pointer() user_stack_pointer(current_pt_regs())



#endif /* _ASM_WASM32_PTRACE_H */