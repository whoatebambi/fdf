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

int		mouse_press_event(int button, int x, int y, t_data *data)
{
	printf("Mouse press event\n");
	exit(0);
}

void	init_hooks(t_data *data)
{
	mlx_loop_hook(data->mlx, &render, data);
	mlx_hook(data->mlx_win, ON_MOUSEDOWN, ON_MOUSEDOWN, &mouse_press_event, data);
	mlx_loop(data->mlx);
}

int		init_image(t_data *data)
{
	data->image.img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (data->image.img == NULL)
	{
		printf("Error: mlx_new_image\n");
		return (-1);
	}
	printf("Image created\n");
	data->image.addr = mlx_get_data_addr(data->image.img, &data->image.bits_per_pixel, &data->image.line_length, &data->image.endian);
	if (data->image.addr == NULL)
	{
		printf("Error: mlx_get_data_addr\n");
		return (-1);
	}
	init_hooks(data);
	return (0);
}

int		init_window(t_data *data)
{
    data->mlx = mlx_init();
    if (data->mlx == NULL)
    {
        printf("Error: mlx_init\n");
        return (-1);
    }
    data->mlx_win = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
    if (data->mlx_win == NULL)
    {
        printf("Error: mlx_new_window\n");
        return (-1);
    }
	if (init_image(data) == -1)
		return (-1);
	data->background_color = 0xFF991439;
    return (0);
}
