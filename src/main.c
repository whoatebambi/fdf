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

t_fdf		*fdf_init(t_map *map)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf));
	if (fdf == NULL)
		ft_error("fdf malloc failed\n");
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FdF");
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->addr = mlx_get_data_addr(fdf->img, &(fdf->bpp), &(fdf->line_len), &(fdf->endian));
	fdf->map = map;
	return (fdf);
}

t_camera	*camera_init(t_fdf *fdf)
{
	t_camera	*camera;

	camera = (t_camera *)ft_memalloc(sizeof(t_camera));
	camera->zoom = 50; // FT_MIN((WIDTH - 100) / fdf->map->width / 2, HEIGHT / fdf->map->height / 2);
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->z_divisor = 1;
	camera->x_offset = 0;
	camera->y_offset = 0;
	return (camera);
}

t_map	*map_init(void)
{
	t_map	*map;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	if (map == NULL)
		ft_error("map malloc failed\n");
	map->width = 0;
	map->height = 0;
	map->coords_arr = NULL;
	map->colors_arr = NULL;
	map->z_min = INT_MAX; //FT_INT_MAX ?
	map->z_max = INT_MIN; //FT_INT_MIN ?
	map->z_range = 0;
	return (map);
}

void	read_map(int fd, t_coord_val **coords_stack, t_map *map)
{
	char		**coords_line;
	char		*line;
	
	while ((line = get_next_line(fd)) != NULL)
	{
		coords_line = ft_split(line, ' ');
		parse_line(coords_line, coords_stack, map);
		map->height++;
	}
	// free line
	// free coords_line
}


// Convert stack with t_coord_val elements (contains z value and color value)
// to array with z values and array with color values.
void		stack_to_arrays(t_coord_val **coords_stack, t_map *map)
{
	t_coord_val	*coord;
	ssize_t		i;
	size_t		arr_size;

	arr_size = map->width * map->height * sizeof(int);
	map->coords_arr = (int *)ft_memalloc(arr_size);
	map->colors_arr = (int *)ft_memalloc(arr_size);
	i = map->width * map->height - 1;
	while ((coord = pop(coords_stack)) && i >= 0)
	{
		map->coords_arr[i] = coord->z;
		map->colors_arr[i] = coord->color;
		if (coord->z > map->z_max)
			map->z_max = coord->z;
		if (coord->z < map->z_min)
			map->z_min = coord->z;
		i--;
		free(coord);
	}
	map->z_range = map->z_max - map->z_min;
}

int		main(int argc, char **argv)
{
	int		fd;
	t_map	*map;
	t_fdf	*fdf;
	t_coord_val	*coords_stack;

	if (argc != 2)
		ft_error("usage: ./fdf map.fdf");
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		ft_error("fd open failed\n");
	map = map_init();
	read_map(fd, &coords_stack, map);
	// ft_printf("map->width = %d\n", map->width);
	// ft_printf("map->height = %d\n", map->height);
	// if (read_map(fd, &coords_stack, map) == -1)
	// 	ft_error("map reading failed\n");
	fdf = fdf_init(map);
	stack_to_arrays(&coords_stack, map);
	fdf->camera = camera_init(fdf);
	draw(fdf->map, fdf);
	setup_controls(fdf);
	mlx_loop(fdf->mlx);
	// mlx_destroy_image(fdf->mlx, fdf->win);// mlx_destroy_display(mlx); // ??
	// free(fdf->mlx)
	return (0);
}
