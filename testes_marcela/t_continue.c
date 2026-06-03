#include <stdio.h>

int main ()
{
    int a;
    int b;
    int res;
    b = 0;
    res = 0;
    a = 5;

    while (b <= 5)
    {
        if (b == 5)
        {
            b++;
            printf("%d B ",b);
            continue;
        }
        res = b + a;
        printf("%d RES ",res);
        b++;
    }
}