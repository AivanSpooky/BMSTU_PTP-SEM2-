#define _POSIX_C_SOURCE 199309L

#include <time.h>
#include <stdio.h>
#include <unistd.h>

#define OK 0


int nanosleep(const struct timespec *req, struct timespec *rem);

// Замерительный метод - clock()
int main (void)
{
   struct timespec tw = {0,100*1e+6};
   struct timespec tr;

   double time_spent = 0;

   clock_t begin = clock();
   nanosleep(&tw, &tr);
   clock_t end = clock();

   time_spent += (double)(end - begin);

   printf("%f\n", time_spent);
   
   return OK;
}
