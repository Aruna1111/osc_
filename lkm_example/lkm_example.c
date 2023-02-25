#include <linux/init.h> /* Needed for the macros */
#include <linux/module.h> /* Needed by all modules */
#include <linux/printk.h> /* Needed for pr_info() */

/* Using the module_init() and module_exit() macros it is easy to write code without #ifdefs
*/

static int __init hello_init(void) /* Defines which function is to be called at module insertion time */
{
    pr_info("Hello, Aliya and Aruna\n");
    return 0;
}

static void __exit hello_exit(void) /* Macro defines the function to be called at module removal time */
{
    pr_info("Goodbye, Aliya and Aruna\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
