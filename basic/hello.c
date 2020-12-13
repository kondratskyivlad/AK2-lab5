#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/moduleparam.h>
#include <linux/errno.h>

static uint repeats = 1;
module_param(repeats, uint, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(repeats, "The number of times the greeting is repeated. Valid values are 0 - 10, unwanted values are 5 - 10.\n");

static int __init hello_init(void)
{
	int i;

	printk(KERN_EMERG "repeats: %d\n", repeats);
	if (repeats == 0) {
		printk(KERN_WARNING "Small value!\n");
	} else if (repeats > 5 && repeats <= 10) {
		printk(KERN_WARNING "Big value!\n");
	} else if (repeats > 10) {
		printk(KERN_ERR "The parameter value is greater than 10.\n");
		return -EINVAL;
	}

	for (i = 0; i < repeats; i++) {
		printk(KERN_EMERG "Hello, world!\n");
	}

	return 0;
}

static void __exit hello_exit(void)
{
	/* Do nothing here right now */
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_AUTHOR("Vladislav Kondratsky");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");
