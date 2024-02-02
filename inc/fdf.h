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

#include "../libft/inc/libft.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../minilibx_macos/mlx.h"

#define WIDTH 1400
#define HEIGHT 800
#define RED 0xFF0000
#define GREEN 0xFF00
#define WHITE 0xFFFFFF

typedef struct s_fdf
{
    void	*mlx;
    void	*win;
	void	*img;
    char	*addr;
    int		bpp;
    int		line_len;
    int		endian;
}	t_fdf;


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