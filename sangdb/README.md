====
GDB
====
#make
#make install /insmod sangdb.ko
#cd /sys/module/sangdb
#cd sections
#cat .text .data .rodata.str1.1 .rodata.str1.8
0xffffffffa0032000
0xffffffffa0034000
0xffffffffa0033060
0xffffffffa00330a8
#gdb ./vmlinux /proc/kcore

(gdb) add-symbol-file ./sangdb.o 0xffffffffa0032000 -s .data 0xffffffffa0034000 -s .rodata.str1.1 0xffffffffa0033060  -s .rodata.str1.8 0xffffffffa00330a8
(gdb) p sangdb_count 
 $1 = 20


====
KDB
====
#login to tty*/virtual console
#echo kbd > /sys/module/kgdboc/parameters/kgdboc
#echo g > /proc/sysrq-trigger
[kdb]> 
