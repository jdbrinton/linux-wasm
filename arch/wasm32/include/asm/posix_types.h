#ifndef _ASM_WASM32_POSIX_TYPES_H
#define _ASM_WASM32_POSIX_TYPES_H

/*
 * This file defines the kernel's POSIX types for the wasm32 architecture.
 * These definitions are based on standard 32-bit architectures.
 */

typedef unsigned short      __kernel_mode_t;
typedef unsigned short      __kernel_ipc_pid_t;
typedef unsigned short      __kernel_uid_t;
typedef unsigned short      __kernel_gid_t;
typedef unsigned short      __kernel_old_uid_t;
typedef unsigned short      __kernel_old_gid_t;
typedef unsigned int        __kernel_uid32_t;
typedef unsigned int        __kernel_gid32_t;
typedef int                 __kernel_pid_t;
typedef int                 __kernel_key_t;
typedef int                 __kernel_mqd_t;
typedef unsigned long       __kernel_size_t;
typedef long                __kernel_ssize_t;
typedef int                 __kernel_ptrdiff_t;
typedef long                __kernel_long_t;
typedef unsigned long       __kernel_ulong_t;
typedef long long           __kernel_long_long_t;
typedef unsigned long long  __kernel_ulong_long_t;

/* Offsets and time types */
typedef __kernel_long_t     __kernel_off_t;
typedef long long           __kernel_loff_t;
typedef __kernel_long_t     __kernel_time_t;
typedef long long           __kernel_time64_t;
typedef __kernel_long_t     __kernel_suseconds_t;
typedef __kernel_long_t     __kernel_old_time_t;

/* Additional types */
typedef __kernel_long_t     __kernel_clock_t;
typedef int                 __kernel_timer_t;
typedef int                 __kernel_clockid_t;
typedef char*               __kernel_caddr_t;
typedef short               __kernel_daddr_t;
typedef unsigned short      __kernel_uid16_t;
typedef unsigned short      __kernel_gid16_t;
typedef unsigned int        __kernel_old_dev_t;

/* Aligned 64-bit types */
typedef long long           __kernel_s64;
typedef unsigned long long  __kernel_u64;

/* File system IDs */
typedef struct {
    int val[2];
} __kernel_fsid_t;

/* sigset_t related definitions */
#define _NSIG           64
typedef unsigned long       __kernel_sigset_t;

/* Include guard for signal preamble size */
#define __ARCH_SI_PREAMBLE_SIZE    (4 * sizeof(int))

#endif /* _ASM_WASM32_POSIX_TYPES_H */
