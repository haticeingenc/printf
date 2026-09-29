/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hingenc <hingenc@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 16:14:16 by hingenc           #+#    #+#             */
/*   Updated: 2026/09/29 22:10:06 by hingenc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_type(char format, va_list args)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		len += ft_putptr(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		len += ft_putunsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_puthex(va_arg(args, unsigned int), format);
	else if (format == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	if (!format)
		return (-1);
	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			len += check_type(format[i + 1], args);
			i++;
		}
		else if (format[i] != '%')
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
int	ft_putunsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += ft_putunsigned(n / 10);
	len += ft_putchar((n % 10) + '0');
	return (len);
}