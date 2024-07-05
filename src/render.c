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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->image.addr + (y * data->image.line_length + x * (data->image.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	set_background(t_data *data, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(data, j++, i, color);
		}
		i++;
	}
}


void	draw(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
            t_coordinate coord = data->map->array[y][x];
            my_mlx_pixel_put(data, coord.x, coord.y, 0x00FF0000);
			x++;
		}
		y++;
	}
}


int	render(t_data *data)
{
    if (data->mlx_win == NULL)
    {
        printf("Error: mlx_init\n");
        return (-1);
    }
	my_mlx_pixel_put(data, 5, 5, GREEN);
	// set_background(data, 0x00FF0000);
    draw(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->image.img, 0, 0);
	return (0);
}