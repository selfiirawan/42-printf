#include "ft_printf.h"

int main(void)
{
    int a;

    a = -345;

    printf("original: %d\n", a);
    ft_printf("ft_print: %d\n", a);

	return (0);
}
