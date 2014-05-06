obj-m += kthread.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules	
install:
	sudo insmod kthread.ko
uninstall:
	sudo rmmod kthread
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
