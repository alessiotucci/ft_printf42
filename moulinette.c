#include <stdio.h>
#include "incl/ft_printf.h"

int main(void)
{
    printf("\nTEST1\n\n");
    printf("original:");
    int a = printf(" %+d ", 0);
    printf("\nmy function:");
    int b = ft_printf(" %+d ", 0);
    printf(" %d %d\n", a, b);

    printf("\nTEST2\n\n");
    printf("original:");
    a = printf(" %+d ", -1);
    printf("\nmy function:");
    b = ft_printf(" %+d ", -1);
    printf(" %d %d\n", a, b);

    printf("\nTEST3\n\n");
    printf("original:");
    a = printf(" %+d ", 9);
    printf("\nmy function:");
    b = ft_printf(" %+d ", 9);
    printf(" %d %d\n", a, b);

    printf("\nTEST4\n\n");
    printf("original:");
    a = printf(" %+d ", 10);
    printf("\nmy function:");
    b = ft_printf(" %+d ", 10);
    printf(" %d %d\n", a, b);

    printf("\nTEST5\n\n");
    printf("original:");
    a = printf(" %+d ", -11);
    printf("\nmy function:");
    b = ft_printf(" %+d ", -11);
    printf(" %d %d\n", a, b);

    printf("\nTEST6\n\n");
    printf("original:");
    a = printf(" %+d ", 15);
    printf("\nmy function:");
    b = ft_printf(" %+d ", 15);
    printf(" %d %d\n", a, b);

    printf("\nTEST7\n\n");
    printf("original:");
    a = printf(" %+d ", -16);
    printf("\nmy function:");
    b = ft_printf(" %+d ", -16);
    printf(" %d %d\n", a, b);

    printf("\nTEST8\n\n");
    printf("original:");
    a = printf(" %+d ", 17);
    printf("\nmy function:");
    b = ft_printf(" %+d ", 17);
    printf(" %d %d\n", a, b);

    printf("\nTEST9\n\n");
    printf("original:");
    a = printf(" %+d ", 99);
    printf("\nmy function:");
    b = ft_printf(" %+d ", 99);
    printf(" %d %d\n", a, b);

    printf("\nTEST10\n\n");
    printf("original:");
    a = printf(" %+d ", 100);
    printf("\nmy function:");
    b = ft_printf(" %+d ", 100);
    printf(" %d %d\n", a, b);

    printf("\nTEST11\n\n");
    printf("original:");
    a = printf(" %+d ", 101);
    printf("\nmy function:");
    b = ft_printf(" %+d ", 101);
    printf(" %d %d\n", a, b);

    printf("\nTEST12\n\n");
    printf("original:");
    a = printf(" %+d ", -9);
    printf("\nmy function:");
    b = ft_printf(" %+d ", -9);
    printf(" %d %d\n", a, b);

}
