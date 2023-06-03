#ifndef __ARRAY_T_H__
#define __ARRAY_T_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

// Инициализировать список произвольных значений
void init(int *a, int size);

// Инициализировать список значений в отсортированном порядке
void init_sorted(int *a, int size);

#endif