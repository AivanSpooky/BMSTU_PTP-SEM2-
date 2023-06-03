#define _POSIX_C_SOURCE 199309L

#include <stdio.h>
#include <time.h>


int nanosleep(const struct timespec *req, struct timespec *rem);

int main (void)
{    
   struct timespec tw = {1,0};

   struct timespec tr;

   nanosleep(&tw, &tr);

   printf("Done");
   
   return 0;
}
