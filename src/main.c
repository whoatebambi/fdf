/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcouserg <fcouserg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:33:43 by fcouserg          #+#    #+#             */
/*   Updated: 2023/11/16 11:18:50 by fcouserg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*ft_memalloc(size_t size)
{
	void *ptr;

	if ((ptr = malloc(size)))
		ft_bzero(ptr, size);
	return (ptr);
}

void	terminate(char *s)
{
	if (errno == 0)
		printf("TEST ERRNO\n");// ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(1);
}

t_fdf		*fdf_init(void)
{
	t_fdf	*fdf;

	if (!(fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf))))
		terminate(ERR_FDF_INIT);
	printf("ft_memalloc\n");
	if (!(fdf->mlx = mlx_init()))
		terminate(ERR_FDF_INIT);
	printf("mlx_init\n");
	if (!(fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FdF")))
		terminate(ERR_FDF_INIT);
	printf("mlx_new_window\n");
	if (!(fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT)))
		terminate(ERR_FDF_INIT);
	printf("mlx_new_image\n");
	fdf->addr = mlx_get_data_addr(fdf->img, &(fdf->bpp), &(fdf->line_len), &(fdf->endian));
	printf("mlx_get_data_addr\n");

	// if (!(fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf))))
	// 	terminate(ERR_FDF_INIT);
	// printf("ft_memalloc\n");
	// if (!(fdf->mlx = mlx_init()))
	// 	terminate(ERR_FDF_INIT);
	// printf("mlx_init\n");
	// if (!(fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FdF")))
	// 	terminate(ERR_FDF_INIT);
	// printf("mlx_new_window\n");
	// if (!(fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT)))
	// 	terminate(ERR_FDF_INIT);
	// printf("mlx_new_image\n");
	// fdf->addr = mlx_get_data_addr(fdf->img, &(fdf->bpp), &(fdf->line_len), &(fdf->endian));
	// printf("mlx_get_data_addr\n");
	return (fdf);
}


int main(void)
{
	t_fdf		*fdf;

	fdf = fdf_init();
	errno = 0;

	draw(fdf);
	setup_controls(fdf);
    mlx_loop(fdf->mlx);
	
	terminate(ERR_USAGE);
	return (0);
    // // mlx_destroy_window(fdf.mlx, fdf.win);
    // mlx_destroy_image(fdf->mlx, fdf->win);// mlx_destroy_display(mlx);
    // free(fdf->mlx);
}
