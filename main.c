#include "ft_printf.h"

int main(void)
{
    int	a;
	int	b;

	a = ft_printf("%s|%c|%%\n", "hello", 'x');
	b = printf("%s|%c|%%\n", "hello", 'x');
	printf("mine: %d, real: %d\n", a, b);
	a = ft_printf("[%s]\n", "");
	b = printf("[%s]\n", "");
	printf("mine: %d, real: %d\n", a, b);
	return (0);
}
