// arch/wasm32/kernel/wasm_input.c

#include <linux/interrupt.h>
#include <linux/tty.h>
#include <linux/tty_flip.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static struct tty_port wasm_tty_port;

__attribute__((visibility("default")))
__attribute__((export_name("handle_input")))
void handle_input(int ch)
{
    struct tty_port *port = &wasm_tty_port;
    struct tty_struct *tty = port->tty;

    if (tty) {
        char c = (char)ch;
        int space;

        space = tty_insert_flip_string(port, &c, 1);

        if (space != 1) {
            printk(KERN_WARNING "wasm_input: tty buffer full\n");
        }

        tty_flip_buffer_push(port);
    }
}

static int wasm_tty_open(struct tty_struct *tty, struct file *file)
{
    tty->driver_data = &wasm_tty_port;
    tty_port_tty_set(&wasm_tty_port, tty);
    return 0;
}

static void wasm_tty_close(struct tty_struct *tty, struct file *file)
{
    tty_port_tty_set(&wasm_tty_port, NULL);
}

static int wasm_tty_write(struct tty_struct *tty, const unsigned char *buf, int count)
{
    // You can implement this if needed
    return count;
}

static const struct tty_operations wasm_tty_ops = {
    .open = wasm_tty_open,
    .close = wasm_tty_close,
    .write = wasm_tty_write,
};

static struct tty_driver *wasm_tty_driver;

static int __init wasm_tty_init(void)
{
    int ret;

    wasm_tty_driver = alloc_tty_driver(1);
    if (!wasm_tty_driver)
        return -ENOMEM;

    wasm_tty_driver->driver_name = "wasm_tty";
    wasm_tty_driver->name = "ttyW";
    wasm_tty_driver->major = 0;
    wasm_tty_driver->type = TTY_DRIVER_TYPE_CONSOLE;
    wasm_tty_driver->subtype = SERIAL_TYPE_NORMAL;
    wasm_tty_driver->flags = TTY_DRIVER_REAL_RAW | TTY_DRIVER_DYNAMIC_DEV;
    wasm_tty_driver->init_termios = tty_std_termios;
    wasm_tty_driver->init_termios.c_cflag = B115200 | CS8 | CREAD | HUPCL | CLOCAL;
    tty_set_operations(wasm_tty_driver, &wasm_tty_ops);

    tty_port_init(&wasm_tty_port);
    wasm_tty_port.ops = NULL;

    ret = tty_register_driver(wasm_tty_driver);
    if (ret) {
        put_tty_driver(wasm_tty_driver);
        return ret;
    }

    tty_register_device(wasm_tty_driver, 0, NULL);
    return 0;
}

device_initcall(wasm_tty_init);
