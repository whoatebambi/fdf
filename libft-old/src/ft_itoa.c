/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcouserg <fcouserg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:33:43 by fcouserg          #+#    #+#             */
/*   Updated: 2023/11/16 13:53:42 by fcouserg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	s_isneg(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

static int	s_intlen(unsigned int nbr)
{
	size_t	i;

	if (nbr == 0)
		return (1);
	i = 0;
	while (nbr >= 1)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	len;
	unsigned int	neg;
	unsigned int	nbr;

	neg = s_isneg(n);
	if (neg)
		nbr = -n;
	else
		nbr = n;
	len = s_intlen(nbr);
	str = (char *)malloc(sizeof(char) * (len + neg + 1));
	if (!str)
		return (NULL);
	if (neg == 1)
		str[0] = '-';
	str[len + neg] = '\0';
	while (len > 0)
	{
		str[(len - 1) + neg] = (nbr % 10) + '0';
		nbr /= 10;
		len--;
	}
	return (str);
}
