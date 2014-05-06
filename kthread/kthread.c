#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/kthread.h>
#include<linux/sched.h>

struct task_struct *task;
int data;
int ret;
int thread_function(void *data)
{
    int var;
    var = 10;
    return var;
}

static int kernel_init(void)
{
    data = 20;
    printk(KERN_INFO"--------------------------------------------");
    task = kthread_create(&thread_function,(void *)data,"harish");
//    task = kthread_run(&thread_function,(void *)data,"harish");
    printk(KERN_INFO"Kernel Thread : %s\n",task->comm);
    return 0;
}

static void kernel_exit(void)
{
    ret = kthread_stop(task);
}

module_init(kernel_init);
module_exit(kernel_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("HARISH");
MODULE_DESCRIPTION("Kernal Thread");
MODULE_SUPPORTED_DEVICE("kthread");
