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

void    check_args(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <file_name>\n", argv[0]);
        exit(-1);
    }
    //check_folder(argv[1]);
    check_file(argv[1]);
}

void    check_folder(char *file_name) // is it really useful?
{
    int fd;

    fd = open(file_name, O_RDONLY | O_DIRECTORY);
    if (fd == -1)
    {
        printf("Error: open path\n");
        exit(-1);
    }
    close(fd);
}

void    check_file(char *file_name)
{
    int fd;
    // char *line;

    fd = open(file_name, O_RDONLY);
    if (fd == -1)
    {
        printf("Error: open file\n");
        exit(-1);
    }
    close(fd);
}

void	check_isdigit(char *map)
{
	int i;

	i = 0;
	while (map[i])
	{
		if (ft_isdigit(map[i]) == 0 && map[i] != ' ' && map[i] != '\n')
		{
			printf("Error: non digit character found\n");
			free(map);
			exit (-1);
		}
		i++;
	}
}
