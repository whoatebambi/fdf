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

void	draw(t_fdf *fdf)
{
	draw_line_bresenham(fdf, WIDTH - 40, HEIGHT, -40, 0, RED);
	draw_line_xiaolin(fdf, WIDTH, HEIGHT, 0, 0, RED);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}

void	img_pix_put(t_fdf *fdf, int x, int y, int color)
{
    char    *pixel;

    pixel = fdf->addr + (y * fdf->line_len + x * (fdf->bpp / 8));
    *(int *)pixel = color;
	// int i = fdf->bpp - 8;
    // pixel = fdf->addr + (y * fdf->line_len + x * (fdf->bpp / 8));
    // while (i >= 0)
    // {
    //     /* big endian, MSB is the leftmost bit */
    //     if (fdf->endian != 0)
    //         *pixel++ = (color >> i) & 0xFF;
    //     /* little endian, LSB is the leftmost bit */
    //     else
    //         *pixel++ = (color >> (fdf->bpp - 8 - i)) & 0xFF;
    //     i -= 8;
    // }
}

int	draw_line_bresenham(t_fdf *fdf, int beginX, int beginY, int endX, int endY, int color)
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
		img_pix_put(fdf, pixelX, pixelY, color);
		pixelX += deltaX;
		pixelY += deltaY;
		pixels--;
	}
	return (0);
}

int	draw_line_xiaolin(t_fdf *fdf, int beginX, int beginY, int endX, int endY, int color)
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
			img_pix_put(fdf, nb_to_int(interY), x, add_alpha(color, nb_to_r_frac(interY)));
			img_pix_put(fdf, nb_to_int(interY)-1, x, add_alpha(color, nb_to_frac(interY)));
		}
		else
		{
			img_pix_put(fdf, x, nb_to_int(interY), add_alpha(color, nb_to_r_frac(interY)));
			img_pix_put(fdf, x, nb_to_int(interY)-1, add_alpha(color, nb_to_frac(interY)));
		}
		interY += gradient; 
		x++;
	}
	return(0);
}

void	swap(int *a, int *b) 
{ 
    int	temp;

	temp = *a; 
    *a = *b; 
    *b = temp; 
} 

float	absolute(float x) 
{ 
	if (x < 0)
		return (-x); 
	else
		return (x); 
} 

//returns integer part of a floating point number 
int	nb_to_int(float x) 
{ 
	return ((int)x); 
} 

//returns fractional part of a number 
float	nb_to_frac(float x) 
{ 
	if (x>0)
		return (x - nb_to_int(x)); 
	else
		return (x - (nb_to_int(x)+1)); 
} 
  
//returns 1 - fractional part of number 
float	nb_to_r_frac(float x) 
{ 
	return (1 - nb_to_frac(x)); 
}

int	add_alpha(int color , float transparency) 
{ 
	int	alpha;
	int	argb_color;
	// Convert transparency to an integer alpha value (0 to 255)
	alpha = (int)(transparency * 255);
	// Shift the alpha value to the correct position (24 bits) and add the original color
	argb_color = (alpha << 24) | color;
	return (argb_color);
}
