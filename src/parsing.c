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

void	get_coord(char **map_array, t_map *map)
{
	char **line;
	int x;
	int y;
	int width;

	y = 0;
    
    map->array = NULL;
	map->array = ft_calloc(map->height, sizeof(t_coordinate *)); // do i need the +1?
	while (map_array[y])
	{
        x = 0;
		line = ft_split(map_array[y], ' ');
		// error ft_split
        map->array[y] = ft_calloc(map->width, sizeof(t_coordinate)); // do i need the +1?
        // error ft_calloc
        while (line[x])
        {
            map->array[y][x].x = x;
            map->array[y][x].y = y;
            map->array[y][x].z = ft_atoi(line[x]);
            // printf("[%d] x: %d, y: %d, z: %d\n", y, array[y][x].x, array[y][x].y, array[y][x].z);
            x++;
        }
		free(line);
		y++;
	}
}

char	*map_to_str(char *file_name)
{
	int fd;
    char *line;
    char *map;

    fd = open(file_name, O_RDONLY);
    map = ft_calloc(1, sizeof(char));
    if (map == NULL)
	{
		printf("Error: ft_calloc\n");
		close(fd);
		exit (-1);
	}
	line = get_next_line(fd);
	if (line == NULL)
	{
		printf("Error: empty file\n");
		close(fd);
		free(map);
		exit (-1);
	}
	while (line != NULL)
	{
		map = ft_strjoin(map, line);
		free(line);
		line = get_next_line(fd);
	}
    close(fd);
    return (map);
}

void	get_height(char **map_array, t_map *map)
{
	int i;

	i = 0;
	while (map_array[i])
		i++;
	map->height = i;
	printf("height: %d\n", map->height);
}


void	get_width(char **map_array, t_map *map)
{
	int i;
	int j;
	int width;

	i = 0;
	width = ft_word_count(map_array[i], ' ');
	while (map_array[i])
	{
		if (ft_word_count(map_array[i], ' ') != width)
		{
			printf("Error: incorrect format\n");
			// free(map_array);
			exit (-1);
		}
		i++;
	}
	map->width = width;
    printf("width: %d\n", map->width);
}

int     parse_map(char *file_name, t_data *data)
{
	char *map;
	char **map_array;

	map = map_to_str(file_name);
	check_isdigit(map);
	map_array = ft_split(map, '\n');
	free(map);
    data->map = malloc(sizeof(t_map));
    // error malloc
	get_height(map_array, data->map);
	get_width(map_array, data->map);
	// for (int i = 0; map_array[i]; i++)
	// 	printf("%s\n", map_array[i]);
	get_coord(map_array, data->map);
    // error get_coord
    return (0);
}