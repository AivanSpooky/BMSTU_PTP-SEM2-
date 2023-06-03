#ifndef __SORT_H__
#define __SORT_H__

#include <stddef.h>

// Сортировка с индексацией a[i]
void selection_sort1(int *a, size_t n);

// Сортировка с заменой индексации *(a+i)
void selection_sort2(int *a, size_t a_size);

// Сортировка с указателями массива *pb и *pe
void selection_sort3(int *pb, int *pe);

#endif
