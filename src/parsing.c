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

t_coord_val	*pop(t_coord_val **coords_stack)
{
	t_coord_val *top;

	top = NULL;
	if (coords_stack && *coords_stack)
	{
		top = *coords_stack;
		*coords_stack = (*coords_stack)->next;
	}
	return (top);
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
