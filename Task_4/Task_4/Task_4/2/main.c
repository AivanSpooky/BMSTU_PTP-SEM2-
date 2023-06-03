#include <stdio.h>
#include <stdlib.h>

#include <time.h>
#include <sys/time.h>

#include "array_t.h"
#include "sort.h"

#define OK 0
#define ERR_IO 1

#ifndef NMAX
#error NMAX IS NOT DEFINED
#endif
#ifndef SORT_TYPE
#error TYPE IS NOT DEFINED
#endif
#ifndef ARR_TYPE
#error ARR_TYPE IS NOT DEFINED
#endif

typedef int array_t[NMAX];

// Структуру переопределяю, так как для стандарта с99 это сделать необходимо (иначе возникнет ошибка компиляции)
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
    array_t a;
    int sort_type = SORT_TYPE;
    int size = atoi(argv[1]);
    int array_type = ARR_TYPE;

    switch (array_type)
    {
        case 1:
            init(a, size);
            break;
        case 2:
            init_sorted(a, size);
            break;
    }

    struct timeval current_time;
    unsigned long long beg, end;

	// Действия
	switch(sort_type)
	{
		case 1:
			gettimeofday(&current_time, NULL);
			beg = current_time.tv_sec * 1000ULL + current_time.tv_usec / 1000ULL;
			selection_sort1(a, size);
			gettimeofday(&current_time, NULL);
			end = current_time.tv_sec * 1000ULL + current_time.tv_usec / 1000ULL;
			break;
		case 2:
			gettimeofday(&current_time, NULL);
			beg = current_time.tv_sec * 1000ULL + current_time.tv_usec / 1000ULL;
			selection_sort2(a, size);
			gettimeofday(&current_time, NULL);
			end = current_time.tv_sec * 1000ULL + current_time.tv_usec / 1000ULL;
			break;
		case 3:
			gettimeofday(&current_time, NULL);
			beg = current_time.tv_sec * 1000ULL + current_time.tv_usec / 1000ULL;
			selection_sort3(a, (a + size));
			gettimeofday(&current_time, NULL);
			end = current_time.tv_sec * 1000ULL + current_time.tv_usec / 1000ULL;
			break;
		default:
			return ERR_IO;
	}

    printf("%llu\n", (end - beg));

    return OK;
}
