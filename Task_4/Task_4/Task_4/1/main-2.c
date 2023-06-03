#define _POSIX_C_SOURCE 199309L

#include <time.h>
#include <stdio.h>
#include <unistd.h>

#define OK 0

// Замерительный метод - clock_gettime
int main (void)
{
   struct timespec tw = {0,100*1e+6};
   struct timespec tr;

   struct timespec start, ending;
   unsigned long long beg, end;

   clock_gettime( CLOCK_MONOTONIC_RAW, &start );

   beg = start.tv_sec * 1000ULL + start.tv_nsec / 1000ULL;
   nanosleep(&tw, &tr);
   clock_gettime( CLOCK_MONOTONIC_RAW, &ending );
   end = ending.tv_sec * 1000ULL + ending.tv_nsec / 1000ULL;

   printf("%llu\n", end-beg);

   return OK;
}
