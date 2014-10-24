obj-m += jif.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules	
install:
	sudo insmod jif.ko
uninstall:
	sudo rmmod jif
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
