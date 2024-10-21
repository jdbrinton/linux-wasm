#ifndef _ASM_WASM32_UACCESS_H
#define _ASM_WASM32_UACCESS_H

#include <linux/compiler.h>
#include <linux/types.h>
#include <linux/errno.h>
#include <linux/string.h>
#include <asm/page.h>

static inline size_t strlcpy(char *dst, const char *src, size_t size)
{
    size_t src_len = 0;
    while (src[src_len] != '\0' && src_len < size - 1) {
        dst[src_len] = src[src_len];
        src_len++;
    }

    if (size > 0) {
        dst[src_len] = '\0';
    }

    // Return the length of the source string.
    while (src[src_len] != '\0') {
        src_len++;
    }

    return src_len;
}


#define user_addr_max() (TASK_SIZE)

#define VERIFY_READ     0
#define VERIFY_WRITE    1

#define access_ok(addr, size) (1)

static inline unsigned long raw_copy_from_user(void *to, const void __user *from, unsigned long n)
{
    memcpy(to, (const void *)from, n);
    return 0;
}

static inline unsigned long raw_copy_to_user(void __user *to, const void *from, unsigned long n)
{
    memcpy((void *)to, from, n);
    return 0;
}

static inline long strncpy_from_user(char *dst, const char __user *src, long count)
{
    // Since user and kernel space are not distinct in WASM, you can just use a regular copy.
    return strlcpy(dst, src, count);
}

#define __get_user(x, ptr) ({ \
    (x) = *(typeof(*(ptr)) __force *) (ptr); \
    0; \
})

#define __put_user(x, ptr) ({ \
    *(typeof(*(ptr)) __force *) (ptr) = (x); \
    0; \
})

#define get_user(x, ptr) __get_user(x, ptr)
#define put_user(x, ptr) __put_user(x, ptr)

/* Clear a block of user memory */
static inline unsigned long clear_user(void __user *to, unsigned long n)
{
    /* Since wasm32 may not have separate user/kernel spaces, we can use memset */
    memset((void *)to, 0, n);
    return 0; /* Return zero on success */
}


#include <linux/kernel.h>
#include <linux/thread_info.h>
#include <asm/processor.h>  /* For current_thread_info() */


/* Address limit definitions */
#define KERNEL_DS  ((mm_segment_t) { 0xFFFFFFFF })
#define USER_DS    ((mm_segment_t) { TASK_SIZE - 1 })

/* Current address limit */
static inline mm_segment_t get_fs(void)
{
    return current_thread_info()->thread.addr_limit;
}

static inline void set_fs(mm_segment_t fs)
{
    current_thread_info()->thread.addr_limit = fs;
}

/* Check if address is within the user space limit */
static inline int __access_ok(const void *addr, unsigned long size)
{
    unsigned long addr_ul = (unsigned long)addr;
    unsigned long limit = current_thread_info()->thread.addr_limit.seg;

    /* Check for address overflow */
    if (unlikely(addr_ul > limit))
        return 0;
    if (unlikely(size > limit - addr_ul))
        return 0;

    return 1;
}



static inline int nmi_uaccess_okay(void)
{
    /* For architectures without special NMI considerations, return true */
    return 1;
}

static inline long strnlen_user(const char __user *s, long n)
{
    const char *p = s;
    long len = 0;

    while (n) {
        char c;

        if (get_user(c, p))
            return 0; /* Error in copying from user space */

        len++;
        p++;
        n--;

        if (c == '\0')
            break;
    }

    return len;
}

// static inline int get_user(unsigned long *val, const void __user *addr)
// {
//     *val = *(const unsigned long *)addr;
//     return 0;
// }

// static inline int put_user(unsigned long val, void __user *addr)
// {
//     *(unsigned long *)addr = val;
//     return 0;
// }



#endif /* _ASM_WASM32_UACCESS_H */