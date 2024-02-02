/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcouserg <fcouserg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:32:17 by fcouserg          #+#    #+#             */
/*   Updated: 2023/12/05 14:29:53 by fcouserg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hexalen(unsigned int nbr)
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

static void	ft_printhexa(unsigned int nbr, char format)
{
	char	*base;

	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nbr >= 16)
		ft_printhexa(nbr / 16, format);
	write(1, &base[nbr % 16], 1);
}

int	ft_puthexa(unsigned int nbr, char format)
{
	ft_printhexa(nbr, format);
	return (ft_hexalen(nbr));
}
