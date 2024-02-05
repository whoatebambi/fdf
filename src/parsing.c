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



t_map		*map_init(void)
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

static t_coord_val	*new_coord(char *coords_line)
{
	t_coord_val	*coord;
	char		**parts;

	coord = (t_coord_val *)ft_memalloc(sizeof(t_coord_val));
	// if NULL
	parts = ft_split(coords_line, ',');
	// ft_isnumber(parts[0], 10);
	// parts[1] && !ft_isnumber(parts[1], 16);
	coord->z = ft_atoi(parts[0]);
	coord->color = 0;// parts[1] ? ft_atoi_base(parts[1], 16) : -1;
	coord->next = NULL;
	// free_strsplit_arr(parts);
	return (coord);
}
void	push(t_coord_val **coords_stack, t_coord_val *new)
{
	if (coords_stack)
	{
		if (new)
			new->next = *coords_stack;
		*coords_stack = new;
	}
}

void	parse_line(char	**coords_line, t_coord_val **coords_stack, t_map *map)
{
	int	width;

	width = 0;
	while (*coords_line)
	{
		push(coords_stack, new_coord(*(coords_line++)));
		width++;
	}
	if (map->height == 0)
		map->width = width;

}

int		main(int argc, char **argv)
{
	int		fd;
	t_map	*map;
	// t_fdf	*fdf;
	t_coord_val	*coords_stack;

	coords_stack = NULL;
	if (argc != 2)
		ft_error("usage: ./fdf map.fdf");
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		ft_error("fd open failed\n");
	map = map_init();

	read_map(fd, &coords_stack, map);
	ft_printf("map->width = %d\n", map->width);
	ft_printf("map->height = %d\n", map->height);

	while (coords_stack != NULL)
	{
		int y = 0;
		while (y < map->height)
		{
			int x = 0;
			while (x < map->width)
			{
				ft_printf(" %d ", coords_stack->z);
				coords_stack = coords_stack->next;
				x++;
			}
			ft_printf("\n");
			y++;
		}
	}
	
	// read_map(fd, &coords_stack, map);
	// if (read_map(fd, &coords_stack, map) == -1)
	// 	ft_error("map reading failed\n");
	return (0);
}
// typedef struct			s_map
// {
// 	int					width;
// 	int					height;
// 	int					*coords_arr;
// 	int					*colors_arr;
// 	int					z_min;
// 	int					z_max;
// 	int					z_range;
// }						t_map;

// typedef struct			s_coord_val
// {
// 	int					z;
// 	int					color;
// 	struct s_coord_val	*next;
// }						t_coord_val;