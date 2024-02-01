/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcouserg <fcouserg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:33:43 by fcouserg          #+#    #+#             */
/*   Updated: 2023/11/14 18:09:46 by fcouserg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	void	*dsttemp;

	dsttemp = dst;
	if (!dst && !src)
		return (dst);
	if (dst == src)
		return (dst);
	if (dst > src)
		while (n--)
			((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
	else
		while (n--)
			*(unsigned char *)(dst++) = *(unsigned char *)(src++);
	return (dsttemp);
}
