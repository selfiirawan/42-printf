/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirawan <sirawan@student.42penang.edu.my>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 10:42:48 by sirawan           #+#    #+#             */
/*   Updated: 2026/11/09 10:42:51 by sirawan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list *args, char spec)
{
	if (spec == '%')
		return (ft_putchar('%'));
	if (spec == 'c')
		return (ft_putchar(va_arg(*args, int)));
	if (spec == 's')
		return (ft_putstr(va_arg(*args, char *)));
	if (spec == 'd' || spec == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	if (spec == 'u')
		return (ft_putunbr(va_arg(*args, unsigned int)));
	if (spec == 'x')
		return (ft_puthex(va_arg(*args, unsigned int), "0123456789abcdef"));
	if (spec == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), "0123456789ABCDEF"));
	if (spec == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				break ;
			count += ft_format(&args, format[i + 1]);
			i += 2;
		}
		else
		{
			count += ft_putchar(format[i]);
			i++;
		}
	}
	va_end(args);
	return (count);
}
