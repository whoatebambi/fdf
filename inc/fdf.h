/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 10:39:59 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/08/02 10:40:00 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

#include "libft.h"
#include <mlx.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// MACROS
# define WINDOW_WIDTH 200
# define WINDOW_HEIGHT 200
# define GREEN 0xFF00

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_coordinate
{
	int				x;
	int				y;
	int				z;
}					t_coordinate;

typedef struct s_map
{
	int				width;
	int				height;
	t_coordinate	**array;
}					t_map;

typedef struct s_image
{
    void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}         t_image;


typedef struct s_data
{
    void    *mlx;
    void    *mlx_win;
    t_image image;
	t_map	*map;
    int     background_color;
}            t_data;

// parsing.c
int     parse_map(char *file_name, t_data *data);
void	get_width(char **map_array, t_map *map);
void	get_height(char **map_array, t_map *map);
char	*map_to_str(char *file_name);
void	get_coord(char **map_array, t_map *map);

// parsing_utils.c
void		check_args(int argc, char **argv);
void		check_folder(char *file_name);
void		check_file(char *filename);
void	check_isdigit(char *map);

// init.c
int			init_window(t_data *data);
int			init_image(t_data *data);
void		init_hooks(t_data *data);

// render.c
int			render(t_data *data);
void		set_background(t_data *data, int color);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw(t_data *data);


// utils.c
int	ft_word_count(char *s, char c);


#endif
