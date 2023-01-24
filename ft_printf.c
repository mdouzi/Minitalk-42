/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi <mdouzi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 22:34:48 by mdouzi            #+#    #+#             */
/*   Updated: 2023/01/24 21:15:11 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_what(const char format, va_list args)
{
	int	i;

	i = 0;
	if (format == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (format == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		i += ft_putnbr(va_arg(args, int));
	else if (format == 'x')
		i += ft_puthex(va_arg(args, unsigned int), "0123456789abcdef");
	else if (format == '%')
		i += ft_putchar('%');
	else if (format == 'X')
		i += ft_puthex(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (format == 'u')
		i += ft_putunsigned(va_arg(args, unsigned int));
	else if (format == 'p')
	{
		ft_putstr("0x");
		i += 2 + ft_puthex(va_arg(args, unsigned long), "0123456789abcdef");
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			length += ft_what(format[i + 1], args);
			i++;
		}
		else
			length += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (length);
}
