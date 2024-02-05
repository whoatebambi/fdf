/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcouserg <fcouserg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:32:17 by fcouserg          #+#    #+#             */
/*   Updated: 2023/11/28 15:57:00 by fcouserg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, const char format)
{
	int	length;

	length = 0;
	if (format == 'c')
		length += ft_putchar(va_arg(args, int));
	else if (format == 's')
		length += ft_putstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		length += ft_putnbr((va_arg(args, int)));
	else if (format == 'X' || format == 'x')
		length += ft_puthexa(va_arg(args, unsigned int), format);
	else if (format == 'p')
		length += ft_putptr(va_arg(args, void *));
	else if (format == 'u')
		length += ft_putunsigned(va_arg(args, unsigned int));
	else if (format == '%')
		length += ft_putpercent();
	return (length);
}
