#define _POSIX_C_SOURCE 199309L

#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <x86gprintrin.h>

#define OK 0


int nanosleep(const struct timespec *req, struct timespec *rem);

// Замерительный метод - __rdtsc()
int main (void)
{
   struct timespec tw = {0,1000*1e+6};
   struct timespec tr;

   unsigned long long t1 = __rdtsc();
   nanosleep(&tw, &tr);
   unsigned long long t2 = __rdtsc();

   printf("%llu\n", (t2 - t1)/CLOCKS_PER_SEC);

   return OK;
}
