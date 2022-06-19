/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgendel <sgendel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:40:01 by sgendel           #+#    #+#             */
/*   Updated: 2022/02/24 20:11:31 by sgendel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int	count_of_format(va_list	arguments, const char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar(va_arg(arguments, int));
	else if (format == 's')
		count += ft_printstr(va_arg(arguments, char *));
	else if (format == 'd' || format == 'i')
		count += ft_printnbr(va_arg(arguments, int));
	else if (format == '%')
		count += ft_printpercent();
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	arguments;

	va_start(arguments, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += count_of_format(arguments, format[i + 1]);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(arguments);
	return (count);
}
