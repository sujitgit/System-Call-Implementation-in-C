#include<stdio.h>
#include<unistd.h>
#include<linux/unistd.h>
#include<linux/time.h>

int main(int argc, char *argv[]) {

   struct timespec xtimeNow;
   xtimeNow.tv_sec = 0;
   xtimeNow.tv_nsec = 0;
   int result;
   result = syscall(326, &xtimeNow);
   if (result == 0) {
   	printf("\nresult of syscall run: SUCCESS\n");
   } else {
	printf("\nresult of syscall run: FAILED\n");
   }
   /* print the actual value */
   printf("\nTest TEST  TEST : %ld %ld \n", xtimeNow.tv_sec, xtimeNow.tv_nsec);
   printf("\nDays from 1 January 1970: %ld \nHours: %ld \nMinutes: %ld \nSeconds: %ld \nNanoseconds:%ld \n", (xtimeNow.tv_sec/86400), ((xtimeNow.tv_sec%86400)/3600), (((xtimeNow.tv_sec%86400)%3600)/60),((((xtimeNow.tv_sec%86400)%3600)%60)), xtimeNow.tv_nsec);

   return 0;
}

