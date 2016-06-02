#include <linux/init.h>
#include <linux/module.h>

static int test_init(void)
{
	DEFINE_SEQLOCK(mr_seq_lock);
	unsigned long seq;
	printk(KERN_INFO "[init] Can you feel me?\n");

	write_seqlock(&mr_seq_lock);
	printk(KERN_INFO "I'm in mr_seq_lock write lock\n");
	write_sequnlock(&mr_seq_lock);

	do
	{
		seq = read_seqbegin(&mr_seq_lock);
		pr_info("seq = %ld\n", seq);
	}
	while(read_seqretry(&mr_seq_lock, seq));

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

