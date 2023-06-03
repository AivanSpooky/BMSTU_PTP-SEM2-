#include "sort.h"
#include <stdio.h>

// Реализация 1
// Функция находит минимум в диапазоне от strat_ind до end_ind
size_t find_min_elem1(const int a[], size_t start_ind, size_t end_ind)
{
	size_t min_elem = start_ind;
	for (size_t j = start_ind; j < end_ind; j++)
	{
		if (a[j] < a[min_elem])
		{
			min_elem = j;
		}
	}
	return min_elem;
}
// Функция сортировки выбором
void selection_sort1(int *a, size_t a_size)
{
	size_t min_elem = 0;
	int tmp_elem = 0;
	for (size_t i = 0; i < a_size; i++)
	{
		min_elem = find_min_elem1(a, i, a_size);
		tmp_elem = a[i];
		a[i] = a[min_elem];
		a[min_elem] = tmp_elem;
	}
}
// конец

// Реализация 2
size_t find_min_elem2(const int a[], size_t start_ind, size_t end_ind)
{
	size_t min_elem = start_ind;
	for (size_t j = start_ind; j < end_ind; j++)
	{
		if (*(a + j) < *(a + min_elem))
		{
			min_elem = j;
		}
	}
	return min_elem;
}

void selection_sort2(int *a, size_t a_size)
{
	size_t min_elem = 0;
	int tmp_elem = 0;
	for (size_t i = 0; i < a_size; i++)
	{
		min_elem = find_min_elem2(a, i, a_size);
		tmp_elem = *(a + i);
		*(a + i) = *(a + min_elem);
		*(a + min_elem) = tmp_elem;
	}
}
// конец

// Реализация 3
void selection_sort3(int *pb, int *pe)
{
	int min_elem = 0;
	int tmp_elem = *pb;
	for (int i = 0; i < (pe - pb); i++)
	{
        min_elem = i;
		for (int j = i; j < (pe - pb); j++)
	    { 
            //printf("l:%dr:%d\n", *(pb + j), min_elem);
		    if (*(pb + j) < *(pb + min_elem))
		    {
			    min_elem = j;
		    }
	    }
		tmp_elem = *(*(&(pb)) + i);
		*(pb + i) = *(pb + min_elem);
		*(pb + min_elem) = tmp_elem;
	}
}
// конец
