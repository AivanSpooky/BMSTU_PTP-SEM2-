#include <stdio.h>
#include <stdlib.h>

#include <time.h>
#include <sys/time.h>

#include "matrix.h"
#include "sort.h"

#define OK 0
#define ERR_IO 1

#ifndef NMAX
#error NMAX IS NOT DEFINED
#endif
#ifndef SORT_TYPE
#error TYPE IS NOT DEFINED
#endif

struct timespec
{
   time_t tv_sec;
   long tv_nsec;
};

int nanosleep(const struct timespec *req, struct timespec *rem);

// Замерительный метод - gettimeofday
int main(int argc, char **argv)
{
	if (argc != 2)
        return ERR_IO;
    int a[NMAX][NMAX];
    int sort_type = SORT_TYPE;
    int size = atoi(argv[1]);

	init(a);

    struct timeval current_time;
    unsigned long long beg, end;

	// Замер начала
	gettimeofday(&current_time, NULL);
	beg = current_time.tv_sec * 1000000ULL + current_time.tv_usec;
	// Действия
	switch(sort_type)
	{
		case 1:
			selection_sort1(a, size);
			break;
		case 2:
			selection_sort2(a, size);
			break;
		default:
			return ERR_IO;
	}
	// Замер конца
	gettimeofday(&current_time, NULL);
	end = current_time.tv_sec * 1000000ULL + current_time.tv_usec;

    printf("%llu\n", (end - beg));

    return OK;
}
