#ifndef _UAPI_ASM_WASM32_SIGNAL_H
#define _UAPI_ASM_WASM32_SIGNAL_H

#include <linux/types.h>

/* Define the number of signals */
#define _NSIG           64
#define _NSIG_BPW       (sizeof(unsigned long) * 8)
#define _NSIG_WORDS     (_NSIG / _NSIG_BPW)

/* Definition of sigset_t */
typedef struct {
    unsigned long sig[_NSIG_WORDS];
} sigset_t;

/* Define old_sigset_t */
typedef unsigned long old_sigset_t;

/* Signal handler type */
typedef void (*__sighandler_t)(int);

/* Signal numbers */
#define SIGHUP          1
#define SIGINT          2
#define SIGQUIT         3
#define SIGILL          4
#define SIGTRAP         5
#define SIGABRT         6
#define SIGIOT          6
#define SIGBUS          7
#define SIGFPE          8
#define SIGKILL         9
#define SIGUSR1         10
#define SIGSEGV         11
#define SIGUSR2         12
#define SIGPIPE         13
#define SIGALRM         14
#define SIGTERM         15
#define SIGSTKFLT       16
#define SIGCHLD         17
#define SIGCONT         18
#define SIGSTOP         19
#define SIGTSTP         20
#define SIGTTIN         21
#define SIGTTOU         22
#define SIGURG          23
#define SIGXCPU         24
#define SIGXFSZ         25
#define SIGVTALRM       26
#define SIGPROF         27
#define SIGWINCH        28
#define SIGIO           29
#define SIGPOLL         SIGIO
#define SIGPWR          30
#define SIGSYS          31
#define SIGUNUSED       31

#define SIGRTMIN        32
#define SIGRTMAX        _NSIG

/* sa_flags values */
// #define SA_NOCLDSTOP    0x00000001u
// #define SA_NOCLDWAIT    0x00000002u
// #define SA_SIGINFO      0x00000004u
// #define SA_ONSTACK      0x08000000u
// #define SA_RESTART      0x10000000u
// #define SA_NODEFER      0x40000000u
// #define SA_RESETHAND    0x80000000u

// #define SA_NOMASK       SA_NODEFER
// #define SA_ONESHOT      SA_RESETHAND

/* sigprocmask how values */
#define SIG_BLOCK       0
#define SIG_UNBLOCK     1
#define SIG_SETMASK     2

/* sigaltstack structure */
typedef struct sigaltstack {
    void __user *ss_sp;
    int ss_flags;
    size_t ss_size;
} stack_t;

/* sigaltstack flags */
#define SS_ONSTACK      1
#define SS_DISABLE      2

#define MINSIGSTKSZ     2048
#define SIGSTKSZ        8192

/* Signal handler definitions */
// #define SIG_DFL ((void (*)(int))0)
// #define SIG_IGN ((void (*)(int))1)
// #define SIG_ERR ((void (*)(int))-1)

/* Define siginfo_t for user space if not already defined */
#ifndef __ARCH_SIGINFO_T
#define __ARCH_SIGINFO_T


#endif /* __ARCH_SIGINFO_T */

#endif /* _UAPI_ASM_WASM32_SIGNAL_H */
