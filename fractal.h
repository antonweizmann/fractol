/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:21:24 by aweizman          #+#    #+#             */
/*   Updated: 2023/11/18 17:30:27 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "../includes/MLX42/include/MLX42/MLX42.h"
# include "../includes/libft-printf/include/ft_printf.h"
# include <stdio.h>
# include <string.h>
# include <math.h>

# define ITERATIONS 50
# define MANDELBROT 1
# define JULIA 2
# define BURNINGSHIP 3
# define MANDELBOX 4
# define JULIA_SETS 9

typedef struct s_fractal
{
	mlx_image_t		*img;
	mlx_image_t		**strs;
	mlx_t			*mlx;
	int				x;
	int				y;
	int32_t			mouse_x;
	int32_t			mouse_y;
	int				width;
	int				height;
	int				r;
	int				g;
	int				b;
	char			*color_request;
	char			*fractal_request;
	int				fract_type;
	double			rmin;
	double			rmax;
	double			imin;
	double			imax;
	double			pxsize;
	double			zr;
	double			zi;
	double			cr;
	double			ci;
	double			julia_x;
	double			julia_y;
	float			**julia_const;
	int				julia_index;
	int				julia_ind_mv;
	double			zoom;
	int				max_iter;
	int				color;
}				t_fractal;

void	random_color(t_fractal *fract);
int		error(void);
int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void	display_menu(t_fractal *fract);

void	init(t_fractal *fract);
void	init_mandelbrot(t_fractal *fract);
void	init_julia(t_fractal *fract);
void	init_julia_const(t_fractal *fract);
void	init_burningship(t_fractal *fract);

void	draw_fractal(void *param);
int		check_conds(t_fractal *fract);
void	check_img(t_fractal *fract);
void	get_color(t_fractal *fract, int c);

void	mandelbrot(t_fractal *fract);
void	calculate_mandelbrot(t_fractal *fract);
void	julia(t_fractal *fract);
void	calculate_julia(t_fractal *fract);
void	burningship(t_fractal *fract);
void	calculate_burningship(t_fractal *fract);

void	zoom(double xdelta, double ydelta, void *param);
void	input_move(void *param);
void	input_julia(void *param);
void	reload(mlx_key_data_t key, void *param);
void	util_hooks(void *param);
// void	input_left(mlx_key_data_t key, void *param);
// void	input_right(mlx_key_data_t key, void *param);
// void	input_up(mlx_key_data_t key, void *param);
// void	input_down(mlx_key_data_t key, void *param);
// void	input_esc(mlx_key_data_t key, void *param);
#endif
