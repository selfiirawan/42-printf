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

int	ft_printf(const char *format, ...)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (format[i])
	{
		write(1, &format[i], 1);
		count++;
		i++;
	}
	return (count);
}
