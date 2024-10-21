#ifndef _ASM_WASM32_PGTABLE_H
#define _ASM_WASM32_PGTABLE_H

#include <linux/mm_types.h>
#include <asm/page.h>

/* Include generic headers for missing page table levels */
#include <asm-generic/pgtable-nopmd.h>
#include <asm-generic/pgtable-nopud.h>
#include <asm-generic/pgtable-nop4d.h>

/* Define page table entry operations */
static inline int pte_none(pte_t pte)
{
    return !pte_val(pte);
}

static inline void pte_clear(struct mm_struct *mm, unsigned long addr, pte_t *ptep)
{
    pte_val(*ptep) = 0;
}

static inline int pte_present(pte_t pte)
{
    return pte_val(pte) & _PAGE_PRESENT;
}

static inline unsigned long pte_pfn(pte_t pte)
{
    return pte_val(pte) >> PAGE_SHIFT;
}

static inline pte_t pfn_pte(unsigned long pfn, pgprot_t prot)
{
    return __pte((pfn << PAGE_SHIFT) | pgprot_val(prot));
}

static inline struct page *pte_page(pte_t pte)
{
    return pfn_to_page(pte_pfn(pte));
}

static inline pte_t mk_pte(struct page *page, pgprot_t prot)
{
    return pfn_pte(page_to_pfn(page), prot);
}

static inline void set_pte(pte_t *ptep, pte_t pteval)
{
    *ptep = pteval;
}

#define PGDIR_SHIFT     22
#define PGDIR_SIZE      (1UL << PGDIR_SHIFT)
#define PGDIR_MASK      (~(PGDIR_SIZE - 1))

static inline unsigned long pgd_index(unsigned long addr)
{
    return addr >> PGDIR_SHIFT;
}

static inline pgd_t *pgd_offset(struct mm_struct *mm, unsigned long addr)
{
    return mm->pgd + pgd_index(addr);
}

// static inline int pgd_none(pgd_t pgd)
// {
//     return !pgd_val(pgd);
// }

// static inline int pgd_bad(pgd_t pgd)
// {
//     return 0;
// }

// static inline int pgd_present(pgd_t pgd)
// {
//     return pgd_val(pgd) != 0;
// }

// static inline void pgd_clear(pgd_t *pgdp)
// {
//     pgd_val(*pgdp) = 0;
// }

// static inline p4d_t *p4d_offset(pgd_t *pgd, unsigned long addr)
// {
//     return (p4d_t *)pgd;
// }

// static inline pud_t *pud_offset(p4d_t *p4d, unsigned long addr)
// {
//     return (pud_t *)p4d;
// }

// static inline pmd_t *pmd_offset(pud_t *pud, unsigned long addr)
// {
//     return (pmd_t *)pud;
// }

static inline pte_t *pte_offset_kernel(pmd_t *pmd, unsigned long addr)
{
    return (pte_t *)pmd;
}

// static inline pte_t *pte_offset_map(pmd_t *pmd, unsigned long addr)
// {
//     return pte_offset_kernel(pmd, addr);
// }

static inline void pte_unmap(pte_t *pte)
{
}

extern pgd_t swapper_pg_dir[];

#include <asm-generic/pgtable_uffd.h>

#endif /* _ASM_WASM32_PGTABLE_H */