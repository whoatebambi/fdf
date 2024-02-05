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
#include "ft_printf.h"
#include "get_next_line.h"
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *ptr;

	if ((ptr = malloc(size)))
		ft_bzero(ptr, size);
	return (ptr);
}

void	ft_error(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
}

// t_fdf		*fdf_init(t_map *map)
// {
// 	t_fdf	*fdf;

// 	fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf));
// 	if (fdf == NULL)
// 		ft_error("fdf malloc failed\n");
// 	fdf->mlx = mlx_init();
// 	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FdF");
// 	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
// 	fdf->addr = mlx_get_data_addr(fdf->img, &(fdf->bpp), &(fdf->line_len), &(fdf->endian));
// 	fdf->map = map;
// 	return (fdf);
// }

// t_map		*map_init(void)
// {
// 	t_map	*map;

// 	map = (t_map *)ft_memalloc(sizeof(t_map));
// 	if (map == NULL)
// 		ft_error("map malloc failed\n");
// 	map->width = 0;
// 	map->height = 0;
// 	map->coords_arr = NULL;
// 	map->colors_arr = NULL;
// 	map->z_min = INT_MAX; //FT_INT_MAX ?
// 	map->z_max = INT_MIN; //FT_INT_MIN ?
// 	map->z_range = 0;
// 	return (map);
// }

// int		main(int argc, char **argv)
// {
// 	int		fd;
// 	t_map	*map;
// 	t_fdf	*fdf;

// 	if (argc != 2)
// 		ft_error("usage: ./fdf map.fdf");
// 	fd = open(argv[1], O_RDONLY);
// 	if (fd <= 0)
// 		ft_error("fd open failed\n");
// 	map = map_init();

// 	char	*line;
// 	line = get_next_line(fd);
// 	ft_printf("%s\n", line);

// 	// read_map(fd, &coords_stack, map);
// 	// if (read_map(fd, &coords_stack, map) == -1)
// 	// 	ft_error("map reading failed\n");
// 	fdf = fdf_init(map);

// 	draw(fdf);
// 	setup_controls(fdf);

// 	mlx_loop(fdf->mlx);
// 	// mlx_destroy_image(fdf->mlx, fdf->win);// mlx_destroy_display(mlx); ??
// 	// free(fdf->mlx)
// 	return (0);
// }
