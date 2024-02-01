/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcouserg <fcouserg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:32:17 by fcouserg          #+#    #+#             */
/*   Updated: 2023/11/23 17:56:03 by fcouserg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_putunsigned(unsigned int nbr)
{
	int			length;

	length = 0;
	if (nbr >= 10)
	{
		length += ft_putnbr(nbr / 10);
		length += ft_putnbr(nbr % 10);
	}
	else
	{
		ft_putchar(nbr + '0');
		length += 1;
	}
	return (length);
}
