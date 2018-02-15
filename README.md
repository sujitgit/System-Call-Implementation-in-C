Name: Sujit Kumar
email: skumar27@binghamton.edu

Objective:
using the concepts learned in the class, implement and test a system call that returns the current system time by means of a call-by-reference argument. More specifically, your system call should have the following prototype as seen by user-level applications.

int my_xtime(struct timespec *current_time);

struct timespec is defined in include/linux/time.h as follows:

struct timespec {
        time_t  tv_sec;         /* seconds */
        long    tv_nsec;        /* nanoseconds */
};

The system call should verify that user memory space, pointed to by current_time, is valid and writable. If not, is should return a failure (EFAULT) to the user process. If the memory-check succeeds, then it should retrieve the value of kernel's xtime variable using current_kernel_time(...) fucntion, which will read xtime atomically for you. Then copy the retrieved value to user space address (pointed to by current_time argument). The system call should also print the current time in nanoseconds, to the console using the printk() function.
Also write a user-level application which calls your new system call my_xtime(...) and prints out the time obtained from the call-by-reference argument. 



files modified: 
/linux-4.4.1/kernel/makefile
/linux-4.4.1/arch/x86/entry/syscalls/syscall_64.tbl

File added:
/linux-4.4.1/kernel/my_xtime_func.c


git link: https://github.com/sujitgit/kernel-4.4.1
