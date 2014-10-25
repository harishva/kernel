#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

void sanf1_crash(int);
static int sangdb_count=10;
int sangdb_ver=1;
char *sangdb_str="KGDB/KDB/GDB class";
char *p = 0;

EXPORT_SYMBOL(sangdb_ver);
EXPORT_SYMBOL(sangdb_str);

static int __init sangdb_start(void)
{
	printk(KERN_INFO "Module sangdb being loaded = %s ,ver = %d \n",sangdb_str,sangdb_ver);
	sanf1_crash(sangdb_count);
	return 0;
}
void sanf1_crash(int count)
{
	int i;
	for ( i=0;i<count;i++)
	{
		printk(KERN_INFO "sanf1_crash loop %d \n",++sangdb_count);
	}
	*p='A';
}
static void __exit sangdb_end(void)
{
	printk(KERN_INFO "Module sangbd_count %d\n", sangdb_count);
        sanf1_crash(sangdb_count);
	printk(KERN_INFO "Module sangdb being unloaded\n");
}

module_init(sangdb_start);
module_exit(sangdb_end);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("HARISH");
MODULE_DESCRIPTION("Kernal debug module ");
MODULE_SUPPORTED_DEVICE("Debug module");
