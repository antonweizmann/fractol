/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:21:24 by aweizman          #+#    #+#             */
/*   Updated: 2023/11/11 13:58:40 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "./includes/MLX42/include/MLX42/MLX42.h"
# include "./includes/libft-printf/include/ft_printf.h"
# include <stdio.h>
# include <string.h>

# define ITERATIONS 50
# define MANDELBROT 1
# define JULIA 2
# define BURNINGSHIP 3
# define MANDELBOX 4

typedef struct s_fractal
{
	mlx_image_t		*img;
	mlx_t			*mlx;
	int				x;
	int				y;
	int32_t			mouse_x;
	int32_t			mouse_y;
	int				width;
	int				height;
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
	double			zoom;
	char			*name;
	int				max_iter;
	int				color;
}				t_fractal;

void	msg(char *str);
int		error(void);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);

int		init(t_fractal *fract);
void	init_mandelbrot(t_fractal *fract);

void	draw_fractal(void *param);
int		check_conds(t_fractal *fract);

void	mandelbrot(t_fractal *fract);
void	calculate_mandelbrot(t_fractal *fract);

void	zoom(double xdelta, double ydelta, void *param);
void	input_move(void *param);
#endif
