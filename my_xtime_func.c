#include  <linux/linkage.h>
#include  <linux/export.h>
#include  <asm/uaccess.h>
#include  <linux/printk.h>
#include  <linux/slab.h>
#include  <linux/time.h>
asmlinkage int sys_my_xtime(struct timespec *current_time) {
struct timespec xtime;
struct timespec *gtime;
gtime = &xtime;
printk(KERN_ALERT "system call myTimerSysCall implementation block begins");
if(! access_ok(VERIFY_WRITE, current_time, sizeof(struct timespec ))) {
	return -EFAULT;
}
   xtime = current_kernel_time();
   if (copy_to_user(current_time, gtime, sizeof(struct timespec))) 
		return -EFAULT ;

   printk(KERN_ALERT "\nsystem call myTimerSysCall implementation block ends\n");
   printk(KERN_ALERT "\nThe nanosecond part of the time is %ld\n", xtime.tv_nsec);
   printk(KERN_ALERT "\nThe second part of the time is %ld\n", xtime.tv_sec);
   return 0;
}
EXPORT_SYMBOL(sys_my_xtime);
