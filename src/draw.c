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

void	draw(t_map *map, t_fdf *fdf)
{
	// draw_line_bresenham(fdf, WIDTH - 40, HEIGHT, -40, 0, RED);
	// draw_line_xiaolin(fdf, WIDTH, HEIGHT, 0, 0, RED);
	int		x;
	int		y;

	// draw_background(fdf);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x != fdf->map->width - 1)
				draw_line(project(new_point(x, y, map), fdf), project(new_point(x + 1, y, map), fdf), fdf);
			if (y != fdf->map->height - 1)
				draw_line(project(new_point(x, y, map), fdf), project(new_point(x, y + 1, map), fdf), fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}

static void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	int		i;

	if (x >= 100 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * fdf->bpp / 8) + (y * fdf->line_len);
		fdf->addr[i] = color;
		fdf->addr[++i] = color >> 8;
		fdf->addr[++i] = color >> 16;
	}
}

static void	draw_line(t_point f, t_point s, t_fdf *fdf)
{
	t_point	delta;
	t_point	sign;
	t_point	cur;
	int		error[2];
	delta.x = FT_ABS(s.x - f.x);
	delta.y = FT_ABS(s.y - f.y);
	sign.x = f.x < s.x ? 1 : -1;
	sign.y = f.y < s.y ? 1 : -1;
	error[0] = delta.x - delta.y;
	cur = f;
	while (cur.x != s.x || cur.y != s.y)
	{
		// put_pixel(fdf, cur.x, cur.y, get_color(cur, f, s, delta));
		put_pixel(fdf, cur.x, cur.y, RED);
		if ((error[1] = error[0] * 2) > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += sign.y;
		}
	}
}

// Convert coordinate to iso projection
static void	iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
	// *x = *x;
	// *y = *y;
}

t_point		project(t_point p, t_fdf *fdf)
{
	p.x *= fdf->camera->zoom;
	p.y *= fdf->camera->zoom;
	p.z *= fdf->camera->zoom / fdf->camera->z_divisor;
	p.x -= (fdf->map->width * fdf->camera->zoom) / 2;
	p.y -= (fdf->map->height * fdf->camera->zoom) / 2;
	// rotate_x(&p.y, &p.z, fdf->camera->alpha);
	// rotate_y(&p.x, &p.z, fdf->camera->beta);
	// rotate_z(&p.x, &p.y, fdf->camera->gamma);
	if (fdf->camera->projection == ISO)
	{
		iso(&p.x, &p.y, p.z);
		fdf->camera->zoom = 30;
		fdf->camera->y_offset = (HEIGHT / 4);
	}
	p.x += (WIDTH - 0) / 2 + fdf->camera->x_offset + 0;
	p.y += (HEIGHT - (HEIGHT / 2) + fdf->map->height * fdf->camera->zoom) / 2 + fdf->camera->y_offset;
	return (p);
}

// Get index in array by x and y
int		get_index(int x, int y, int width)
{
	return (y * width + x);
}

t_point	new_point(int x, int y, t_map *map)
{
	t_point	point;
	int		index;
 
	index = get_index(x, y, map->width);
	point.x = x;
	point.y = y;
	point.z = map->coords_arr[index];
	// point.color = (map->colors_arr[index] == -1) ?
	// 		get_default_color(point.z, map) : map->colors_arr[index];
	point.color = (map->colors_arr[index] == -1) ?
		RED : map->colors_arr[index];
	return (point);
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
