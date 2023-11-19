# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 16:57:44 by aweizman          #+#    #+#              #
#    Updated: 2023/11/19 17:07:35 by aweizman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

LIBFT	= ./includes/printf

MLX_DIR	= ./includes/MLX42

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

HEADERS = -I./srcs/fractal.h -I$(MLX_DIR)/include -I$(LIBFT)/include/ft_printf.h
MLX42	= $(MLX_DIR)/build/libmlx42.a -lglfw -framework Cocoa -framework OpenGL -framework IOKit

SRCS	= fractal burningship init julia main mandelbrot utils hooks

SRC_DIR	= srcs/

SRC		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCS)))

all : $(MLX_DIR) $(NAME)

$(NAME): $(SRC) $(LIBFT)/libftprintf.a
	@echo "compiling fractol..."
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(MLX42) $(LIBFT)/libftprintf.a $(HEADERS)

$(LIBFT)/libftprintf.a:
	@make -C $(LIBFT)

$(MLX_DIR):
	@echo "creating MLX42.."
	@cd includes/ && mkdir MLX42 && git clone https://github.com/codam-coding-college/MLX42.git
	@cd includes/MLX42/ && cmake -B build && cmake --build build -j4

install_brew:
	@echo "installing brew.." \
	@rm -rf $HOME/.brew && rm -rf $HOME/goinfre/.brew && \
	@git clone --depth=1 https://github.com/Homebrew/brew $HOME/goinfre/.brew && \
	@echo 'export PATH=$HOME/goinfre/.brew/bin:$PATH' >> $HOME/.zshrc && \
	@source $HOME/.zshrc && brew update \

install_glfw:
	@echo "installing glfw.."
	@brew install glfw

install: install_brew install_glfw

clean:
	@echo "cleaning up..."
	@make clean -C $(LIBFT)
	@rm -rf includes/MLX42

fclean: clean
	@echo "full cleaning up..."
	@make fclean -C $(LIBFT)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re install_brew install_glfw install

