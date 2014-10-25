obj-m += sangdb.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules	
install:
	sudo insmod sangdb.ko
uninstall:
	sudo rmmod sangdb
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
