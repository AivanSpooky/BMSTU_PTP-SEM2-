#define _POSIX_C_SOURCE 199309L

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

// Замерительный метод - gettimeofday
int main(int argc, char **argv)
{
	// Неправильное кол-во аргументов - ошибка
	if (argc != 2)
        return ERR_IO;
    int a[NMAX][NMAX];
    int sort_type = SORT_TYPE;
    size_t size = atoi(argv[1]);

	init(a, size);

    struct timeval current_time;
    unsigned long long beg, end;

	// Действия
	switch(sort_type)
	{
		case 1:
			gettimeofday(&current_time, NULL);
			beg = current_time.tv_sec * 1000000ULL + current_time.tv_usec;
			selection_sort1(a, size);
			gettimeofday(&current_time, NULL);
			end = current_time.tv_sec * 1000000ULL + current_time.tv_usec;
			break;
		case 2:
			gettimeofday(&current_time, NULL);
			beg = current_time.tv_sec * 1000000ULL + current_time.tv_usec;
			selection_sort2(a, size);
			gettimeofday(&current_time, NULL);
			end = current_time.tv_sec * 1000000ULL + current_time.tv_usec;
			break;
		default:
			return ERR_IO;
	}

    printf("%llu\n", (end - beg));

    return OK;
}
