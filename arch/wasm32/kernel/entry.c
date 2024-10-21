// arch/wasm32/kernel/entry.c

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/printk.h>
#include <linux/console.h>
#include <linux/module.h>

__attribute__((export_name("_start")))
void _start(void)
{
    start_kernel();
}

void __init setup_arch(char **cmdline_p)
{
    // Architecture-specific initialization
    *cmdline_p = NULL;
}

void __init start_kernel(void)
{
    setup_arch(NULL);
    printk("Hello from WASM32 Linux Kernel!\n");
    console_init();
    tty_init();
}
