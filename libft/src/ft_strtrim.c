/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcouserg <fcouserg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:45:01 by fcouserg          #+#    #+#             */
/*   Updated: 2023/11/16 13:58:35 by fcouserg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	fts_isset(const char *str, const char c)
{
	int	i;

	i = 0;
	while (*(str + i))
		if (*(str + i++) == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*result;

	if (!s1)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	i = 0;
	while (fts_isset(set, s1[start]) && s1[i])
		start++;
	while (end > start && fts_isset(set, s1[end - 1]))
		end--;
	result = (char *)malloc((end - start + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (start < end)
		result[i++] = s1[start++];
	result[i] = '\0';
	return (result);
}
