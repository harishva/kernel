#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/jiffies.h>
#include <linux/timer.h>
unsigned long js, je,hz,te,time;
int jif_init(void){
    js = jiffies;
    hz = HZ;
    printk("\n[Jiffies start Time : %lu HZ: %lu]\nModule Started.\n", js,hz);
    return 0;
}

void jif_exit(void) {
    je = jiffies;
    te=je-js;
    time=te/hz;
    printk("\n[Jiffies End Time : %lu Diff Jiffies : %lu  TIME : %lu]\nModule Removed.\n", je,te,time);

}

module_init(jif_init);
module_exit(jif_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("JIFFIES EXAMPLE");
MODULE_AUTHOR("Harish V A");
