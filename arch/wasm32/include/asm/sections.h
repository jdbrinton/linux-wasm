#ifndef _ASM_WASM32_SECTIONS_H
#define _ASM_WASM32_SECTIONS_H

#include <asm/extable.h>
#include <asm/section_def.h>
#include <asm/compiler.h>

/* Function to check if an address is within the kernel's rodata section */
static inline int is_kernel_rodata(unsigned long addr)
{
    return addr >= (unsigned long)__start_rodata && addr < (unsigned long)__end_rodata;
}

static inline int __is_kernel_text(unsigned long addr)
{
    return 1;  // Stub: Assume all addresses are in kernel text
}

static inline int __is_kernel(unsigned long addr)
{
    return 1;  // Stub: Assume all addresses are in kernel space
}

static inline int is_kernel_inittext(unsigned long addr)
{
    return 0;  // Stub: No init text section
}

// Declare dummy section boundaries (symbols to be defined in linker script)
extern char _sinittext[], _einittext[];

// Define init_section_intersects function
static inline int init_section_intersects(const void *start, size_t size)
{
    unsigned long s = (unsigned long)start;
    unsigned long e = s + size;

    return (s < (unsigned long)_einittext) && (e > (unsigned long)_sinittext);
}

// Declare dummy section boundaries (symbols to be defined in your linker script)
extern char _sinittext[], _einittext[];

// Define init_section_contains function
static inline int init_section_contains(const void *addr, size_t size)
{
    const unsigned long s = (unsigned long)addr;
    const unsigned long e = s + size;

    return (s >= (unsigned long)_sinittext) && (e <= (unsigned long)_einittext);
}


#endif /* _ASM_WASM32_SECTIONS_H */
