#include <linux/init.h>
#include <linux/module.h>

static int test_init(void)
{
	printk(KERN_INFO "[init] Can you feel me?\n");


	return 0;
}

static void test_exit(void)
{
	printk(KERN_INFO "[exit] Yes.\n");
}


module_init(test_init);
module_exit(test_exit);

MODULE_AUTHOR("Alan Wang <alan@wrcode.com>");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("A simple Module");
MODULE_ALIAS("A simple module");

