#include "ft_printf.h"

int ft_puthex(unsigned int n, char *base)
{
    int num;

    num = 0;
    if (n >= 16)
        num += ft_puthex(n / 16, base);
    num += ft_putchar(base[n % 16]);
    return (num);
}