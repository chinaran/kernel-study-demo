#include <linux/init.h>
#include <linux/module.h>

static int test_init(void)
{
	int t;
	atomic_t v;
	atomic_t u = ATOMIC_INIT(1);

	printk(KERN_INFO "[init] Can you feel me?\n");

	printk(KERN_INFO "u = %d\n", atomic_read(&u));

	atomic_set(&v, 4);
	printk(KERN_INFO "v = %d\n", atomic_read(&v));

	atomic_add(2, &v);
	printk(KERN_INFO "v = %d\n", atomic_read(&v));

	atomic_inc(&v);
	printk(KERN_INFO "v = %d\n", atomic_read(&v));

	t = atomic_dec_and_test(&u);
	printk(KERN_INFO "t = %d\n", t);

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

