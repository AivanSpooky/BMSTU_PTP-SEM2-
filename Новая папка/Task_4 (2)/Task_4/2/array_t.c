#include "array_t.h"

void init(int *a, int size)
{
    for (int i = 0; i < size; i++)
        a[i] = (size > 8) ? (i % (size / (size/8) )) : i;
}

void init_sorted(int *a, int size)
{
    for (int i = 0; i < size; i++)
        a[i] = i;
}
