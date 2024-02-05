/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcouserg <fcouserg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:32:17 by fcouserg          #+#    #+#             */
/*   Updated: 2023/12/05 14:30:32 by fcouserg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptrlen(size_t nbr)
{
	int	length;

	length = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= 16;
		length++;
	}
	return (length);
}

static void	ft_printptr(size_t ptr)
{
	char	*base;

	base = "0123456789abcdef";
	if (ptr >= 16)
		ft_printptr(ptr / 16);
	write(1, &base[ptr % 16], 1);
}

int	ft_putptr(void *ptr)
{
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	ft_printptr((size_t)ptr);
	return (ft_ptrlen((size_t)ptr) + 2);
}
