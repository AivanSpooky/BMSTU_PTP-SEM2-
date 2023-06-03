#include "array_t.h"

void init(int *a, int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
        a[i] = (rand() % (size * 3));
}

void init_sorted(int *a, int size)
{
    for (int i = 0; i < size; i++)
        a[i] = i;
}
