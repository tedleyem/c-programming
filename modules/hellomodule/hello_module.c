#include <linux/module.h>
#include <linux/kernel.h>

static int __init entry_function(void) {
        printk("Hello from hello entry module\n");
        return 0;
};

static void exit_function(void) {
        printk("Goodbye from hello exit module\n");
};

module_init(entry_function);
module_exit(exit_function);

MODULE_AUTHOR("tedleyem");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("A simple hello world module");
