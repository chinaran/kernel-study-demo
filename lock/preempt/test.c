#include <linux/init.h>
#include <linux/module.h>

static int test_init(void)
{
	int ret;
	int cpu;

	printk(KERN_INFO "[init] Can you feel me?\n");

	ret = preempt_count();
	pr_info("ret = %d\n", ret);

	preempt_disable();

	ret = preempt_count();
	pr_info("ret = %d\n", ret);

	preempt_enable();

	ret = preempt_count();
	pr_info("ret = %d\n", ret);

	cpu = get_cpu();
	pr_info("cpu = %d\n", cpu);
	put_cpu();

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

