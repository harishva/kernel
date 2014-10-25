insmod sangdb1.ko

[   38.530853] PGD 0 

[   38.530862] Oops: 0002 [#1] SMP 

[   38.530875] Modules linked in: sangdb1(OE+) iwldvm iwlwifi

[   38.530896] CPU: 3 PID: 4024 Comm: insmod Tainted: G           OE 3.16.6 #8

[   38.530916] Hardware name: Dell Inc. Latitude E6420/0K0DNP, BIOS A21 11/14/2013

[   38.530937] task: ffff88011b449920 ti: ffff8800b09b4000 task.ti: ffff8800b09b4000

[   38.530958] RIP: 0010:[<ffffffffa002d019>]  [<ffffffffa002d019>] sanf1_crash+0x19/0x4c [sangdb1]

[   38.530984] RSP: 0018:ffff8800b09b7d38  EFLAGS: 00010246

[   38.531000] RAX: 0000000000000000 RBX: 000000000000000a RCX: 0000000000000006

[   38.531020] RDX: 0000000000000007 RSI: 0000000000000046 RDI: 0000000000000246

[   38.531040] RBP: ffff8800b09b7d48 R08: 0000000000000092 R09: 00000000000003c0

[   38.531060] R10: 0000000000000000 R11: ffff8800b09b7a5e R12: 000000000000000a

[   38.531079] R13: 0000000000000000 R14: ffffffffa0032000 R15: 0000000000000001

[   38.531099] FS:  00002ba2dcaaeb80(0000) GS:ffff88012dc60000(0000) knlGS:0000000000000000

[   38.531122] CS:  0010 DS: 0000 ES: 0000 CR0: 0000000080050033

[   38.531138] CR2: 0000000000000000 CR3: 00000000b0844000 CR4: 00000000000407e0

[   38.531157] Stack:

[   38.531165]  ffffffff82003020 ffff8800bebe2ce0 ffff8800b09b7d58 ffffffffa003202a

[   38.531189]  ffff8800b09b7dc8 ffffffff8100212c ffffffffa002f070 000000000000001d

[   38.531214]  ffff8800aba2ef00 0000000000000001 ffff8800b09b7db0 ffffffff811fb9a2

[   38.531240] Call Trace:

[   38.531251]  [<ffffffffa003202a>] sangdb_start+0x2a/0x1000 [sangdb1]

[   38.531272]  [<ffffffff8100212c>] do_one_initcall+0xbc/0x1f0

[   38.531291]  [<ffffffff811fb9a2>] ? __vunmap+0xb2/0x100

[   38.531308]  [<ffffffff8114dd2c>] load_module+0x1cfc/0x2710

[   38.531325]  [<ffffffff81149c90>] ? store_uevent+0x40/0x40

[   38.531342]  [<ffffffff8114a871>] ? copy_module_from_fd.isra.46+0x121/0x180

[   38.531362]  [<ffffffff8114e8b6>] SyS_finit_module+0x86/0xb0

[   38.531381]  [<ffffffff81add66d>] system_call_fastpath+0x1a/0x1f


/sys/module/sangdb1/sections# cat .text .data .rodata.str1.1 .rodata.str1.8

0xffffffffa002d000

0xffffffffa002f000

0xffffffffa002e060

0xffffffffa002e0a8

gdb ./vmlinux /proc/kcore

add-symbol-file /home/harishva/test/kernel/sangdb1/sangdb1.o 0xffffffffa002d000 -s .data 0xffffffffa002f000 -s .rodata.str1.1 0xffffffffa002e060 -s .rodata.str1.8 0xffffffffa002e0a8

(gdb) list *0xffffffffa002d019

0xffffffffa002d019 is in sanf1_crash (/home/harishva/test/kernel/sangdb1/sangdb1.c:27).

22		int i;

23		for ( i=0;i<count;i++)

24		{

25			printk(KERN_INFO "sanf1_crash loop %d \n",++sangdb_count);

26		}

27		*p='A';

28	}

29	static void __exit sangdb_end(void)

30	{

31		printk(KERN_INFO "Module sangbd_count %d\n", sangdb_count);



