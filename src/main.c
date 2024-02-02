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

t_fdf		*fdf_init(void)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf));
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FdF");
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->addr = mlx_get_data_addr(fdf->img, &(fdf->bpp), &(fdf->line_len), &(fdf->endian));
	return (fdf);
}


int main(void)
{
	t_fdf		*fdf;

	fdf = fdf_init();
	draw(fdf);
	setup_controls(fdf);
    mlx_loop(fdf->mlx);
    // mlx_destroy_image(fdf->mlx, fdf->win);// mlx_destroy_display(mlx); ??
    // free(fdf->mlx);
	return (0);
}
