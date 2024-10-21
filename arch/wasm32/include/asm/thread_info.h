#ifndef _ASM_WASM32_THREAD_INFO_H
#define _ASM_WASM32_THREAD_INFO_H

#define __ARCH_TASK_THREAD_INFO

#include <linux/types.h>
#include <asm/page.h>
#include <asm/cache.h>
#include <asm/processor.h>

/* Thread information flags */
/* Start with bit 0 and assign incrementally */
// #define TIF_SYSCALL           0  /* Placeholder example */
// #define TIF_NEED_RESCHED      1  /* Need reschedule */
#define TIF_MEMDIE            2  /* Selected by OOM killer */

// #define _TIF_SYSCALL          (1 << TIF_SYSCALL)
// #define _TIF_NEED_RESCHED     (1 << TIF_NEED_RESCHED)
#define _TIF_MEMDIE           (1 << TIF_MEMDIE)



#define THREAD_SIZE_ORDER    1
#define THREAD_SIZE          (PAGE_SIZE << THREAD_SIZE_ORDER)

#define TIF_SYSCALL_TRACE    (1 << 0)
#define TIF_NOTIFY_RESUME    (1 << 1)
#define TIF_SIGPENDING       (1 << 2)
#define TIF_NEED_RESCHED     (1 << 3)
#define TIF_SINGLESTEP       (1 << 4)
#define TIF_UPROBE           (1 << 5)
#define TIF_PATCH_PENDING    (1 << 6)
#define TIF_NEED_FPU_LOAD    (1 << 7)
#define TIF_NOTIFY_SIGNAL    (1 << 8)



// Define the task_thread_info macro
// #define task_thread_info(task) ((struct thread_info *)task->thread_info)

// #define __HAVE_THREAD_FUNCTIONS

#define INIT_THREAD_INFO(tsk)          \
{                                      \
    .task           = &(tsk),          \
    .preempt_count  = INIT_PREEMPT_COUNT,\
    .flags          = 0,               \
}

static struct thread_info wasm32_current_thread_info;

static inline struct thread_info *current_thread_info(void)
{
    return &wasm32_current_thread_info;
}

/* Macro to get the kernel stack pointer of a task */
#define KSTK_ESP(tsk) ((tsk)->thread.ksp)



#include <linux/thread_info.h>

#endif /* _ASM_WASM32_THREAD_INFO_H */