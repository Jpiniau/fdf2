# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/03 13:52:39 by jpiniau           #+#    #+#              #
#    Updated: 2015/11/13 17:34:12 by jpiniau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Werror -Wextra

INCLUDES = libft/includes 

INCLUDES2 = minilibx_macos

SRC = fdf.c\
	  create_matrix.c\
	  check_matrix.c\
	  set_point.c\
	  transform.c\
	  ft_collect.c\
	  ft_line.c\
	  ft_vue.c\
	  ft_pixel_put.c\
	  action.c\
	  ft_line.c\
	  ft_switch.c\
	  ft_menu.c

OBJ = $(SRC:.c=.o)

all : lib $(NAME)

lib :
	@echo "creation de la libft"
	@make -C libft
	@echo "creation de mlx"
	@make -C minilibx_macos

$(NAME) : $(OBJ)
	gcc $(FLAGS) -o $(NAME) $^ -L libft/ -lft -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

%.o : %.c fdf.h
	gcc $(FLAGS) -o $@ -c $< -I $(INCLUDES) -I $(INCLUDES2)

clean :
	rm -fr *.o

fclean : clean
	rm -fr $(NAME)

re : fclean all
