/* SPDX-License-Identifier: GPL-2.0 */

/*
 * Linker script for the wasm32 architecture.
 */

OUTPUT_ARCH(wasm32)

ENTRY(_start)

SECTIONS
{
    . = ALIGN(4);

    /* Text section */
    .text : {
        _stext = .;
        *(.text)
        *(.text.*)
        _etext = .;
    }

    /* Read-only data section */
    .rodata : {
        __start_rodata = .;
        *(.rodata)
        *(.rodata.*)
        __end_rodata = .;
    }

    /* Data section */
    .data : {
        _sdata = .;
        *(.data)
        *(.data.*)
        _edata = .;
    }

    /* Init code and data */
    .init : {
        __init_begin = .;
        *(.init.text)
        *(.init.data)
        __init_end = .;
    }

    /* BSS section */
    .bss : {
        __bss_start = .;
        *(.bss)
        *(.bss.*)
        *(COMMON)
        __bss_stop = .;
    }

    _end = .;

    /* Discard unused sections */
    /DISCARD/ : {
        *(.note.GNU-stack)
        *(.comment)
    }
}
