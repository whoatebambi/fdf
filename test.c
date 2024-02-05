// #include <stdio.h>
#include "libft.h"
#include "fdf.h"

int	main(void)
{
	char	*message;

	message = "Hello";
	// ft_printf("Hello\n");
	ft_printf("message = %d\n", (int)ft_strlen(message));
	return (0);
}