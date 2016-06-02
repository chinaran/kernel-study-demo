#include <linux/init.h>
#include <linux/module.h>
#include <linux/semaphore.h>

static int test_init(void)
{
	DEFINE_SEMAPHORE(mr_sem);
	DECLARE_RWSEM(mr_rwsem);

	printk(KERN_INFO "[init] Can you feel me?\n");

	if (down_interruptible(&mr_sem))
	{
		printk(KERN_INFO "Get mr_sem lock\n");
	}

	printk(KERN_INFO "I'm in critical zone\n");

	up(&mr_sem);

	printk(KERN_INFO "end 1\n");

	down_read(&mr_rwsem);
	printk(KERN_INFO "I'm in read lock\n");
	up_read(&mr_rwsem);

	down_write(&mr_rwsem);
	printk(KERN_INFO "I'm in write lock\n");
	up_write(&mr_rwsem);

	printk(KERN_INFO "end 2\n");
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

