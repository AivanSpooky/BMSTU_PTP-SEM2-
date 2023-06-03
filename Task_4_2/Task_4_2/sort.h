#ifndef __SORT_H__
#define __SORT_H__

#include <stddef.h>

// Сортировка с кешированием суммы элементов строк
void selection_sort1(int a[][NMAX], size_t n);

// Сортировка без кеширования суммы элементов строк
void selection_sort2(int a[][NMAX], size_t n);

#endif
