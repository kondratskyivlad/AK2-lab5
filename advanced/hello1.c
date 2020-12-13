#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>

#include "hello1.h"

int print_hello(uint repeats)
{
	int i;

	pr_alert("repeats: %d\n", repeats);
	if (repeats == 0) {
		pr_warn("Small value!\n");
	} else if (repeats > 5 && repeats <= 10) {
		pr_warn("Big value!\n");
	} else if (repeats > 10) {
		pr_err("The parameter value is greater than 10.\n");
		return -EINVAL;
	}

	for (i = 0; i < repeats; i++) {
		pr_alert(KERN_EMERG "Hello, world!\n");
	}

	return 0;
}
EXPORT_SYMBOL(print_hello);

static int __init hello1_init(void)
{
	pr_alert("hello1 started!\n");
	return 0;
}

static void __exit hello1_exit(void)
{
	pr_alert("hello1 closed!\n");
}

module_init(hello1_init);
module_exit(hello1_exit);

MODULE_AUTHOR("Vladislav Kondratsky");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training. Module 1.");
MODULE_LICENSE("Dual BSD/GPL");
