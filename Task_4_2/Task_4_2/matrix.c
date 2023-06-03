#include "matrix.h"

#ifndef NMAX
#error NMAX IS NOT DEFINED
#endif

void init(int a[][NMAX])
{
    srand(time(NULL));
    for (size_t i = 0; i < NMAX; i++)
        for (size_t j = 0; j < NMAX; j++)
            a[i][j] = (rand() % (NMAX * 3));
}
