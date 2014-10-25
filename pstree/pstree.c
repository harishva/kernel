#include <linux/sched.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
static int pscode_init(void)
{
	struct task_struct *task;
	printk(KERN_INFO "Initializing Pscode Module\n");
for_each_process(task) {
        /* this pointlessly prints the name and PID of each task */
        printk("%s :[%d] %ld \n", task->comm, task->pid,task->state);
}
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
MODULE_DESCRIPTION("Kernal PS tree module ");
MODULE_SUPPORTED_DEVICE("PS tree module");

