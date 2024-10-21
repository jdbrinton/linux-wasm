// arch/wasm32/kernel/wasm_console.c

#include <linux/console.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

extern void console_write(const char *message);

static void wasm_console_write(struct console *con, const char *s, unsigned int count)
{
    char buffer[256];
    unsigned int limit = min(count, sizeof(buffer) - 1);

    memcpy(buffer, s, limit);
    buffer[limit] = '\0';

    console_write(buffer);
}

static struct console wasm_console = {
    .name       = "wasmcons",
    .write      = wasm_console_write,
    .flags      = CON_PRINTBUFFER,
    .index      = -1,
};

static int __init wasm_console_init(void)
{
    register_console(&wasm_console);
    return 0;
}

console_initcall(wasm_console_init);
