/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcouserg <fcouserg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:33:43 by fcouserg          #+#    #+#             */
/*   Updated: 2023/12/19 16:03:39 by fcouserg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

typedef struct s_list_gnl
{
	char			*content;
	struct s_list	*next;
}					t_list_gnl;

char				*get_next_line(int fd);
char				*read_and_save(char *save, int fd);
char				*get_line(char *save);
char				*clean_save(char *save);

char				*ft_strndup(char *str, int n);
char				*ft_strjoin_gnl(char *save, char *buf);
int					ft_strchr_gnl(char *str, char c);

#endif