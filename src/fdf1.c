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
#include <math.h>
#include "../minilibx_macos/mlx.h"

#define W_WIDTH 1400
#define W_HEIGHT 800
#define RED 0xFF0000

int	draw_line_bresenham(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color)
{
	double	deltaX;
	double	deltaY;
	int		pixels;
	double pixelX = beginX;
	double pixelY = beginY;

	deltaX = endX - beginX;
	deltaY = endY - beginY;
	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	while (pixels)
	{
		mlx_pixel_put(mlx, win, pixelX, pixelY, color);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
	return (0);
}

void swap(int* a , int*b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

float absolute(float x ) 
{ 
    if (x < 0) return -x; 
    else return x; 
} 

//returns integer part of a floating point number 
int nb_to_int(float x) 
{ 
    return (int)x; 
} 

//returns fractional part of a number 
float nb_to_frac(float x) 
{ 
    if (x>0) return x - nb_to_int(x); 
    else return x - (nb_to_int(x)+1); 
} 
  
//returns 1 - fractional part of number 
float nb_to_r_frac(float x) 
{ 
    return 1 - nb_to_frac(x); 
} 

int add_alpha(int color , float transparency) 
{ 
	// Convert transparency to an integer alpha value (0 to 255)
	int	alpha = (int)(transparency * 255);
	// Shift the alpha value to the correct position (24 bits) and add the original color
	int	argb_color = (alpha << 24) | color;
    return (argb_color);
}

int	draw_line_xiaolin(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color)
{
	int	steep = absolute(endY - beginY) > absolute(endX - beginX);
	// swap the co-ordinates if slope > 1 or we draw backwards 
    if (steep)
    {
        swap(&beginX, &beginY); 
        swap(&endX, &endY); 
    } 
    if (beginX > endX) 
    { 
        swap(&beginX, &endX); 
        swap(&beginY, &endY); 
    } 
	float	deltaX = endX - beginX;
	float	deltaY = endY - beginY;
	float	gradient = deltaY/deltaX;
	if (deltaX == 0.0) 
        gradient = 1;

    float interY = beginY; 
	int	x = beginX;
	while (x <= endX)
	{
		if (steep)
		{
			mlx_pixel_put(mlx, win, nb_to_int(interY), x, add_alpha(color, nb_to_r_frac(interY)));
			mlx_pixel_put(mlx, win, nb_to_int(interY)-1, x, add_alpha(color, nb_to_frac(interY)));
		}
		else
		{
			mlx_pixel_put(mlx, win, x, nb_to_int(interY), add_alpha(color, nb_to_r_frac(interY)));
			mlx_pixel_put(mlx, win, x, nb_to_int(interY)-1, add_alpha(color, nb_to_frac(interY)));
		}
		interY += gradient; 
		x++;
	}
	return(0);
}

int main()
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, W_WIDTH, W_HEIGHT, "Drawing a line");

	draw_line_bresenham(mlx, win, W_WIDTH - 40, W_HEIGHT, -40, 0, RED);
	draw_line_xiaolin(mlx, win, W_WIDTH, W_HEIGHT, 0, 0, RED);
	// mlx_pixel_put(mlx, win, W_WIDTH/2, W_HEIGHT/2, RED);
	mlx_loop(mlx);
}
