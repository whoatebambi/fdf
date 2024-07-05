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

int		main(int argc, char **argv)
{
    t_data  data;

    check_args(argc, argv);
    if (parse_map(argv[1], &data) == -1)
        return (-1);
    if (init_window(&data) == -1)
    {
        // free map
        return (-1);
    }
    printf("END END\n");
	return (0);
}
