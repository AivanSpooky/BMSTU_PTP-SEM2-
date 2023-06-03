#include <stdio.h>

int div(int a, int b, int *c);

int main(void)
{
    int a = 5, b = 2;
    int c, err;

    err = div(a, b, &c);
    if (err != 0)
        return 1;
    printf("%d div %d = %d\n", a, b, div(a, b, &c));

    a = 10;
    b = 0;

    err = div(a, b, &c);
    if (err != 0)
        return 1;
    printf("%d div %d = %d\n", a, b, div(a, b, &c));

    return 0;
}

int div(int a, int b, int *c)
{
    if (b == 0)
        return 1;
    *c = (a / b);
    return 0;
}
