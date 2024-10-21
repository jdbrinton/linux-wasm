#ifndef _ASM_WASM32_PGTABLE_TYPES_H
#define _ASM_WASM32_PGTABLE_TYPES_H

#include <linux/types.h>
#include <asm/page.h>

/* Define basic page table types */
typedef struct { unsigned long pgd; } pgd_t;
// typedef struct { pgd_t pgd; } p4d_t;
// typedef struct { p4d_t p4d; } pud_t;
// typedef struct { pud_t pud; } pmd_t;
typedef struct { unsigned long pte; } pte_t;

#define pgd_val(x)   ((x).pgd)
// #define p4d_val(x)   ((x).p4d)
// #define pud_val(x)   ((x).pud)
// #define pmd_val(x)   ((x).pmd)
#define pte_val(x)   ((x).pte)

#define __pgd(x)     ((pgd_t) { (x) })
// #define __p4d(x)     ((p4d_t) { (x) })
// #define __pud(x)     ((pud_t) { (x) })
// #define __pmd(x)     ((pmd_t) { (x) })
#define __pte(x)     ((pte_t) { (x) })

/* Page table levels */
#define PTRS_PER_PGD    1
#define PTRS_PER_P4D    1
#define PTRS_PER_PUD    1
#define PTRS_PER_PMD    1
#define PTRS_PER_PTE    (PAGE_SIZE / sizeof(pte_t))

#define USER_PTRS_PER_PGD   (TASK_SIZE / PGDIR_SIZE)
#define FIRST_USER_ADDRESS  0

/* Page protection bits */
#define _PAGE_PRESENT   0x001
#define _PAGE_RW        0x002
#define _PAGE_USER      0x004
#define _PAGE_ACCESSED  0x008
#define _PAGE_DIRTY     0x010

typedef struct {
    unsigned long pgprot;
} pgprot_t;

#define pgprot_val(x)   ((x).pgprot)
#define __pgprot(x)     ((pgprot_t) { (x) })

#define PAGE_NONE       __pgprot(0)
#define PAGE_SHARED     __pgprot(_PAGE_PRESENT | _PAGE_RW | _PAGE_USER)
#define PAGE_COPY       __pgprot(_PAGE_PRESENT | _PAGE_USER)
#define PAGE_READONLY   __pgprot(_PAGE_PRESENT | _PAGE_USER)
#define PAGE_KERNEL     __pgprot(_PAGE_PRESENT | _PAGE_RW)

typedef struct page *pgtable_t;

#endif /* _ASM_WASM32_PGTABLE_TYPES_H */
