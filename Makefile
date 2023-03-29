# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoyohann <yoyohann@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 23:14:02 by yoyohann          #+#    #+#              #
#    Updated: 2023/02/28 23:14:02 by yoyohann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = gcc
MLXD = mlx/
MLX = libmlx.a 
LIBFT = libft.a
LIBFTDIR = ./libft/
CFLAGS = -Wall -Wextra -Werror 
RM = rm -f
EFLAGS = -Llibft -Lmlx -lmlx -framework OpenGL -framework AppKit
SRCFILES = $(wildcard src/*.c)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@		

all : $(NAME)

$(NAME):
	@cd $(LIBFTDIR) && make
	@cd $(MLXD) && make
	@cp $(MLXD)$(MLX) .
	$(CC) $(CFLAGS) $(LIBFTDIR)$(LIBFT) $(EFLAGS) $(SRCFILES) -o $(NAME)
	clear

clean:
	@cd $(MLXD) && make clean
	@cd $(LIBFTDIR) && make clean
	$(RM) $(MLX)
	$(RM) *.o 

fclean: clean
	$(RM) $(NAME)

re: fclean all


