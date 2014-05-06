#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>


static int pscode_init(void)
{
	printk(KERN_INFO "Initializing Pscode Module\n");
	return 0;
}

static void pscode_exit(void)
{
	printk(KERN_INFO "Exiting Pscode Module\n");
}

module_init(pscode_init);
module_exit(pscode_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("HARISH");
MODULE_DESCRIPTION("Kernal first module ");
MODULE_SUPPORTED_DEVICE("test module");
