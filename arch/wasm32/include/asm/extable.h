#ifndef _ASM_WASM32_EXTABLE_H
#define _ASM_WASM32_EXTABLE_H

struct exception_table_entry {
    unsigned long insn;
    unsigned long fixup;
};

#endif
