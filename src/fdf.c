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

#include "../inc/fdf.h"
#include <stdlib.h>
#include <stdio.h>
#include "../minilibx_macos/mlx.h"

#define W_WIDTH 600
#define W_HEIGHT 300
// #define MLX_ERROR 1
#define RED 0xFF0000

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *img_ptr, int x, int y, int color)
{
	char	*dst;

	dst = img_ptr->addr + (y * img_ptr->line_length + x * (img_ptr->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	key_hook(int keycode, t_data img_ptr)
{
	printf("Hello from key_hook!\n");
	return (0);
}

int main()
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_data	img_ptr;

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, W_WIDTH, W_HEIGHT, "TEST");

	mlx_key_hook(mlx_win, key_hook, &img_ptr);

	img_ptr.img = mlx_new_image(mlx_ptr, W_WIDTH, W_HEIGHT);
	img_ptr.addr = mlx_get_data_addr(img_ptr.img, &img_ptr.bits_per_pixel, &img_ptr.line_length, &img_ptr.endian);
	my_mlx_pixel_put(&img_ptr, W_WIDTH/2, W_HEIGHT/2, RED);
	mlx_put_image_to_window(mlx_ptr, mlx_win, img_ptr.img, 0, 0);
	mlx_loop(mlx_ptr);
	
}
