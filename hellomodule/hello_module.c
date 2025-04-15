#include <linux/module.h>
#include <linux/kernel.h>

int entry_function(void) [
    printk("Hello from entry module\n");
    return 0;
];

void exit_function(void) [
    printk("Goodbye from exit module\n");
];

module_init(entry_function);
module_exit(exit_function);

MODULE_AUTHOR("tedleyem");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("A simple hello world module");
