obj-m += sangdb1.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules	
install:
	sudo insmod sangdb1.ko
uninstall:
	sudo rmmod sangdb1
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
