#ifndef _ASM_WASM32_ELF_H
#define _ASM_WASM32_ELF_H

#include <linux/types.h>

#include <uapi/linux/elf.h>

#define ELF_CLASS ELFCLASS32
#define ELF_DATA        ELFDATA2LSB
#define ELF_ARCH        EM_NONE /* Use appropriate EM_* value if defined for WASM32 */
#define ELF_MACHINE     ELF_ARCH

#define EI_NIDENT 16

#define ELF_CORE_COPY_REGS(pr_reg, regs) \
    memset((pr_reg), 0, sizeof(*(pr_reg)));

typedef Elf32_Ehdr Elf_Ehdr;
typedef Elf32_Shdr Elf_Shdr;
typedef Elf32_Sym  Elf_Sym;


/* Definitions for relocation types */
#define R_WASM32_NONE     0
#define R_WASM32_32       1
#define R_WASM32_PC32     2

typedef void* elf_gregset_t;
typedef void* elf_fpregset_t;

static inline int elf_check_arch(const Elf32_Ehdr* hdr)
{
    return 1;
}


#endif /* _ASM_WASM32_ELF_H */
