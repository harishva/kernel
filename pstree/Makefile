obj-m += pstree.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules	
install:
	sudo insmod pstree.ko
uninstall:
	sudo rmmod pstree
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
