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

int ft_puthex_ul(unsigned long n, char *base)
{
    int num;

    num = 0;
    if (n >= 16)
        num += ft_puthex_ul(n / 16, base);
    num += ft_putchar(base[n % 16]);
    return (num);
}

int ft_putptr(void *ptr)
{
    int num;

    num = 0;
    num += ft_putstr("0x");
    num += ft_puthex_ul((unsigned long)ptr, "0123456789abcdef");
    return (num);
}