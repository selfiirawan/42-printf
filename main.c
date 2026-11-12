#include "ft_printf.h"

int main(void)
{
    int	x;

    x = 5;
    ft_printf("%p|%p\n", &x, NULL);
    printf("%p|%p\n", &x, NULL);

	return (0);
}
