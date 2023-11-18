	# **************************************************************************** #
	#                                                                              #
	#                                                         :::      ::::::::    #
	#    Makefile                                           :+:      :+:    :+:    #
	#                                                     +:+ +:+         +:+      #
	#    By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+         #
	#                                                 +#+#+#+#+#+   +#+            #
	#    Created: 2023/11/08 16:57:44 by aweizman          #+#    #+#              #
	#    Updated: 2023/11/16 15:44:10 by aweizman         ###   ########.fr        #
	#                                                                              #
	# **************************************************************************** #

	NAME	= fractol

	LIBFT	= ./includes/libft-printf

	MLX_DIR	= ./includes/MLX42

	CC		= cc

	CFLAGS	= -Wall -Wextra -Werror

	HEADERS = -I./srcs/fractal.h -I$(MLX_DIR)/include -I$(LIBFT)/include/ft_printf.h
	MLX42	= $(MLX_DIR)/build/libmlx42.a -lglfw -framework Cocoa -framework OpenGL -framework IOKit

	SRCS	= fractal burningship init julia main mandelbrot utils hooks

	SRC_DIR	= srcs/

	SRC		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCS)))

	all : $(NAME)

	$(NAME): $(SRC) $(LIBFT)/libftprintf.a
			$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(MLX42) $(LIBFT)/libftprintf.a $(HEADERS)

	$(LIBFT)/libftprintf.a:
		make -C $(LIBFT)

	clean:
		make clean -C $(LIBFT)

	fclean:
		make clean -C $(LIBFT)
		make fclean -C $(LIBFT)
		rm -f $(NAME)

	re: $(SRC)
		make clean -C $(LIBFT)
		make fclean -C $(LIBFT)
		rm -f $(NAME)
		$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(MLX42) $(LIBFT)/libftprintf.a $(HEADERS

	.PHONY: all clean fclean re
