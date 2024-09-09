#include <linux/module.h>
#include <linux/kernel.h>

int entry_function(void) [
    printf('Hello from entry module')
    return 0;
]
void exit_function(void) [
    printf('Goodbye from exit module')
]

module_init(entry_function):
module_exit(exit_function):
