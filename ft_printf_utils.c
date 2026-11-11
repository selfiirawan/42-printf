#include "ft_printf.h"

int ft_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int ft_putstr(char *s)
{
    int i;

    if (!s)
    {
        write(1, "(null)", 6);
        return (6);
    }
    i = 0;
    while (s[i])
    {
        ft_putchar(s[i]);
        i++;
    }
    return (i);
}

int ft_putnbr(int n)
{
    int num;

    if (n == INT_MIN)
    {
        write(1, "-2147483648", 11);
	    return (11);
    }
    num = 0;
    if (n < 0)
    {
        num += ft_putchar('-');
        n = -n;
    }
    if (n >= 10)
        num += ft_putnbr(n / 10);
    num += ft_putchar((n % 10) + '0');
    return (num);
}

int ft_putunbr(unsigned int n)
{
    int num;

    num = 0;
    if (n >= 10)
        num += ft_putunbr(n / 10);
    num += ft_putchar((n % 10) + '0');
    return (num);
}