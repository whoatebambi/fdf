/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcouserg <fcouserg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:33:43 by fcouserg          #+#    #+#             */
/*   Updated: 2023/11/16 11:18:50 by fcouserg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// #include "../libft/inc/libft.h"
// #include "libft.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../minilibx_macos/mlx.h"
// #include "mlx.h"
#include <fcntl.h>
#include <limits.h>

#define WIDTH 1400
#define HEIGHT 800
#define RED 0xFF0000
#define GREEN 0xFF00
#define WHITE 0xFFFFFF

typedef struct			s_coord_val
{
	int					z;
	int					color;
	struct s_coord_val	*next;
}						t_coord_val;

typedef struct			s_map
{
	int					width;
	int					height;
	int					*coords_arr;
	int					*colors_arr;
	int					z_min;
	int					z_max;
	int					z_range;
}						t_map;

typedef struct s_fdf
{
    void	*mlx;
    void	*win;
	void	*img;
    char	*addr;
    int		bpp;
    int		line_len;
    int		endian;
    t_map	*map;
}	t_fdf;




void	*ft_memalloc(size_t size);
void	ft_error(char *msg);
t_fdf	*fdf_init(t_map *map);
t_map	*map_init(void);
void	read_map(int fd, t_coord_val **coords_stack, t_map *map);
void	parse_line(char	**coords_line, t_coord_val **coords_stack, t_map *map);
static 	t_coord_val	*new_coord(char *coords_line);
void	push(t_coord_val **coords_stack, t_coord_val *new);


int		ft_close(void *param);
int		key_press(int key);
void	setup_controls(t_fdf *fdf);

void	draw(t_fdf *fdf);
int		draw_line_bresenham(t_fdf *fdf, int beginX, int beginY, int endX, int endY, int color);
void	swap(int* a, int*b);
float	absolute(float x);
int		nb_to_int(float x);
float	nb_to_frac(float x);
float	nb_to_r_frac(float x);
int		add_alpha(int color, float transparency);
int		draw_line_xiaolin(t_fdf *fdf, int beginX, int beginY, int endX, int endY, int color);

void	img_pix_put(t_fdf *fdf, int x, int y, int color);


#endif