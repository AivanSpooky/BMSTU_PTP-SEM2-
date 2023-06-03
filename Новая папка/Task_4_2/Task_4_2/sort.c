#include "sort.h"
#include <stdio.h>

#ifndef NMAX
#error NMAX IS NOT DEFINED
#endif

// Вспомогательные функции для обоих реализаций сортировок
// Функция находит сумму элементов массива
int find_sum(const int *a, size_t a_size)
{
	int sum = 0;
	for (size_t i = 0; i < a_size; i++)
		sum += a[i];
	return sum;
}
// Функция меняет местами массивы (по-элементно)
void swap_arrays(int a[], int b[], size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        int tmp = a[i];
        a[i] = b[i];
        b[i] = tmp;
    }
}


// Реализация 1
// Функция находит минимум в диапазоне от strat_ind до end_ind (с кешированием суммы)
size_t find_min_elem1(int a[][NMAX], size_t start_ind, size_t end_ind)
{
	size_t min_elem = start_ind;
	int min_sum = find_sum(a[start_ind], end_ind);
	for (size_t j = start_ind; j < end_ind; j++)
	{
		// Кеширование суммы
		int cur_sum = find_sum(a[j], end_ind);
		//
		if (cur_sum < min_sum)
		{
			min_sum = cur_sum;
			min_elem = j;
		}
	}
	return min_elem;
}
// Функция сортировки выбором
void selection_sort1(int a[][NMAX], size_t a_size)
{
	size_t min_elem = 0;
	for (size_t i = 0; i < a_size; i++)
	{
		min_elem = find_min_elem1(a, i, a_size);
		swap_arrays(a[i], a[min_elem], a_size);
	}
}
// конец


// Реализация 2
// Функция находит минимум в диапазоне от strat_ind до end_ind (без кеширования суммы)
size_t find_min_elem2(int a[][NMAX], size_t start_ind, size_t end_ind)
{
	size_t min_elem = start_ind;
	for (size_t j = start_ind; j < end_ind; j++)
	{
		if (find_sum(a[j], end_ind) < find_sum(a[min_elem], end_ind))
		{
			min_elem = j;
		}
	}
	return min_elem;
}
// Функция сортировки выбором
void selection_sort2(int a[][NMAX], size_t a_size)
{
	size_t min_elem = 0;
	for (size_t i = 0; i < a_size; i++)
	{
		min_elem = find_min_elem2(a, i, a_size);
		swap_arrays(a[i], a[min_elem], a_size);
	}
}
// конец
