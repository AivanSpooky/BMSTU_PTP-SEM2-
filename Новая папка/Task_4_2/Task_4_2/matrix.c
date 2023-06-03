#include "matrix.h"

#ifndef NMAX
#error NMAX IS NOT DEFINED
#endif

void init(int a[][NMAX], size_t size)
{
    srand(time(NULL));
    for (size_t i = 0; i < size; i++)
        for (size_t j = 0; j < size; j++)
            a[i][j] = (size > 8) ? (i % (size / (size/8) )) : i; // Всегда одинаковый массив случайных чисел для одного и того же NMAX
}
