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

NAME = tutorial

SOURCES = src/fdf.c

OBJECTS = $(subst .c,.o,$(SOURCES))

FLAGS = -Wall -Wextra #-Werror
LINKS = -I libft -L libft \
    -I /usr/local/include -L /usr/local/lib \
    -l mlx -l ft -framework OpenGL -framework Appkit

# Remember to implement your rules...

$(NAME): $(OBJECTS)
    gcc $(SOURCES) -o $(NAME) $(FLAGS) $(LINKS)



# NAME				= client
# SVR					= server
# CLNBN				= client_bonus
# SVRBN				= server_bonus

# # Directories
# LIBFT				= ./libft/libft.a
# INC					= inc/
# SRC_DIR				= src/
# OBJ_DIR				= obj/

# # Compiler and CFlags
# CC					= cc
# CFLAGS				= -Wall -Werror -Wextra -I
# RM					= rm -f

# # Create full paths for source and object files
# SRCCL 				= $(addprefix $(SRC_DIR), $(addsuffix .c, $(NAME)))
# SRCSV 				= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SVR)))
# SRCCLB 				= $(addprefix $(SRC_DIR), $(addsuffix .c, $(CLNBN)))
# SRCSVB 				= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SVRBN)))

# OBJCL 				= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(NAME)))
# OBJSV 				= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SVR)))
# OBJCLB				= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(CLNBN)))
# OBJSVB 				= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SVRBN)))

# start:				
# 					@make all

# $(LIBFT):
# 					@make -C ./libft

# all:				$(NAME) $(SVR)		

# $(NAME):			$(OBJCL) $(LIBFT)
# 					@$(CC) $(CFLAGS) $(INC) $(OBJCL) $(LIBFT) -o $(NAME)
# 					@echo "\033[0;92m* client file was created *\033[0m"

# $(SVR):				$(OBJSV) $(LIBFT)
# 					@$(CC) $(CFLAGS) $(INC) $(OBJSV) $(LIBFT) -o $(SVR)
# 					@echo "\033[0;92m* server file was created *\033[0m"
					
# bonus:				all $(CLNBN) $(SVRBN)

# $(CLNBN):			$(OBJCLB) $(LIBFT)
# 					@$(CC) $(CFLAGS) $(INC) $(OBJCLB) $(LIBFT) -o $(CLNBN)
# 					@echo "\033[0;92m* client_bonus file was created *\033[0m"

# $(SVRBN):			$(OBJSVB) $(LIBFT)
# 					@$(CC) $(CFLAGS) $(INC) $(OBJSVB) $(LIBFT) -o $(SVRBN)
# 					@echo "\033[0;92m* server_bonus file was created *\033[0m"


# $(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
# 					@mkdir -p $(@D)
# 					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

# clean:
# 					@$(RM) -r $(OBJ_DIR)
# 					@make clean -C ./libft
# 					@echo "\033[0;91m* object files were deleted *\033[0m"

# fclean:				clean
# 					@$(RM) $(NAME) $(SVR) $(CLNBN) $(SVRBN)
# 					@$(RM) $(LIBFT)
# 					@echo "\033[0;91m* all files were deleted *\033[0m"

# re:					fclean all

# .PHONY:				start all clean fclean re bonus
