/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcouserg <fcouserg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:33:43 by fcouserg          #+#    #+#             */
/*   Updated: 2023/11/14 12:59:45 by fcouserg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	lendst;
	unsigned int	lensrc;	

	i = 0;
	if (!dst && size == 0)
		return (0);
	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	j = lendst;
	if (size == 0 || size <= lendst)
		return (lensrc + size);
	while (src[i] && (i < size - lendst - 1))
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (lendst + lensrc);
}
