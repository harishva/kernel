obj-m += threads.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules	
install:
	sudo insmod threads.ko
uninstall:
	sudo rmmod threads
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
