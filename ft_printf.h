/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirawan <sirawan@student.42penang.edu.my>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 10:36:18 by sirawan           #+#    #+#             */
/*   Updated: 2026/11/09 10:36:33 by sirawan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(const char *, ...);
int ft_putchar(char c);
int ft_format(va_list *args, char spec);

#endif
