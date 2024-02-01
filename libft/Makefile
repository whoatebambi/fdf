# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcouserg <fcouserg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 18:59:07 by fcouserg          #+#    #+#              #
#    Updated: 2023/11/21 14:52:36 by fcouserg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
CC			=	cc
CCFLAG		=	-Wall -Wextra -Werror

HDR_DIR		=	./inc/
HDR_FILE	=	libft.h
HEADERS		=	$(addprefix $(HDR_DIR), $(HDR_FILE))


SRC_DIR_LIBFT	=	./src/libft/
SRC_LIBFT		=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
					ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
					ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
					ft_memcmp.c ft_strnstr.c ft_calloc.c ft_strdup.c ft_atoi.c ft_substr.c \
					ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_itoa.c ft_striteri.c ft_putchar_fd.c \
					ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c \
					ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
					ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \


SRC_DIR_PRINTF	=	./src/ft_printf/
SRC_PRINTF		=	ft_printf.c ft_putpercent.c ft_strchr.c ft_strlen.c ft_putchar.c ft_putstr.c \
					ft_putnbr.c ft_putunsigned.c ft_puthexa.c ft_putptr.c ft_format.c \


ALL_SOURCES = $(SRC_LIBFT) $(SRC_PRINTF)


OBJ_DIR		=	./obj/
OBJ_FILE	=	$(patsubst %.c, %.o, $(ALL_SOURCES))
OBJECTS		=	$(addprefix $(OBJ_DIR), $(OBJ_FILE))


all			:	$(NAME)


$(NAME)		:	$(OBJ_DIR) $(OBJECTS)
		@ar -rcs $(NAME) $(OBJECTS)
		@echo "\033[0;92m* $(NAME) library file was created *\033[0m"


$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)


$(OBJ_DIR)%.o : $(SRC_DIR_LIBFT)%.c
		@$(CC) -I$(HDR_DIR) $(CCFLAGS) -c $< -o $@

$(OBJ_DIR)%.o : $(SRC_DIR_PRINTF)%.c
		@$(CC) -I$(HDR_DIR) $(CCFLAGS) -c $< -o $@

clean		:
		@rm -rf $(OBJECTS) $(OBJ_DIR)
		@echo "\033[0;91m* $(NAME) object files were deleted *\033[0m"

fclean		:	clean
		@rm -rf $(NAME)
		@echo "\033[0;91m* $(NAME) was deleted *\033[0m"

re			:	fclean $(NAME)

.PHONY		:	all clean fclean re
