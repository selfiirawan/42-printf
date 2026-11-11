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