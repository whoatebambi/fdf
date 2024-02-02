/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcouserg <fcouserg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:32:17 by fcouserg          #+#    #+#             */
/*   Updated: 2023/12/05 14:53:10 by fcouserg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		length;
	va_list	args;

	i = 0;
	length = 0;
	va_start(args, str);
	if (str == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%' && (ft_strchr("cspdiuxX%", str[i + 1]) == NULL))
			return (-1);
		if (str[i] == '%')
		{
			length += ft_format(args, str[i + 1]);
			i++;
		}
		else
			length += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (length);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int	i;
// 	unsigned int	j;
// 	char	*str;
// 	void	*ptr;

// 	i = -2147483648;
// 	ft_printf("\nint min :\n");
// 	ft_printf("<-ft : %d\n", ft_printf("%d", i));
// 	printf("<-OG : %d\n", printf("%d", i));

// 	str = NULL;
// 	ft_printf("\nstr NULL :\n");
// 	ft_printf("<-ft : %d\n", ft_printf("%s", str));
// 	printf("<-OG : %d\n", printf("%s", str));

// 	ft_printf("\n\nptr NULL :\n");
// 	ft_printf("<-ft : %d\n", ft_printf("%p", str));
// 	printf("<-OG : %d\n", printf("%p", str));

// 	ft_printf("\nguillemets :\n");
// 	ft_printf("<-ft : %d\n", ft_printf(""));
// 	printf("<-OG : %d\n", printf(""));

// 	ft_printf("\nft_printf(0) :\n");
// 	ft_printf("<-ft : %d\n", ft_printf(0));
// 	printf("<-OG : %d\n", printf(0));

// 	ft_printf("\npourcent :\n");
// 	ft_printf("<-ft : %d\n", ft_printf("%%"));
// 	printf("<-OG : %d\n", printf("%%"));
	
// 	ptr = NULL;	
// 	str = "les loulous";
// 	ptr = str;
// 	ft_printf("\ndifferents flags au milieu d'un phrase :\n");
// 	ft_printf("<-ft : %d\n", ft_printf
// 	("%p Salut %s l'int min %% vaut %d au revoir %s", ptr, str, i, str));
// 	printf("<-OG : %d\n", printf
// 	("%p Salut %s l'int min %% vaut %d au revoir %s", ptr, str, i, str));
// 	i = 42;

// 	ft_printf("\nprint X :\n");
// 	ft_printf("<-ft : %d\n", ft_printf("%X", i));
// 	printf("<-OG : %d\n", printf("%X", i));

// 	ft_printf("\nprint x :\n");
// 	ft_printf("<-ft : %d\n", ft_printf("%x", i));
// 	printf("<-OG : %d\n", printf("%x", i));
// 	j = 4294967295;

// 	ft_printf("\nprint u :\n");
// 	ft_printf("<-ft : %d\n", ft_printf("%u", j));
// 	printf("<-OG : %d\n", printf("%u", j));
// }
