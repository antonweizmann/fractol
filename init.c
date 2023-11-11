/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:56:19 by aweizman          #+#    #+#             */
/*   Updated: 2023/11/11 19:23:50 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	init(t_fractal *fract)
{
	fract->x = 0;
	fract->y = 0;
	fract->julia_ind_mv = 0;
	if (fract->fract_type == MANDELBROT)
		init_mandelbrot(fract);
	else if (fract->fract_type == JULIA)
		init_julia(fract);
	// else if (fract->fract_type == BURNINGSHIP)
	// 	init_burningship(fract);
	// else if (fract->fract_type == MANDELBOX)
	// 	init_mandelbox(fract);
	fract->zoom = 1.05;
	fract->max_iter = 1000;
	fract->width = 1000;
	fract->height = 1000;
	fract->mlx = mlx_init(fract->width, fract->height, "fractol", true);
	if (!fract->mlx)
		return (0);
	fract->img = mlx_new_image(fract->mlx, fract->width, fract->height);
	if (!fract->img || (mlx_image_to_window(fract->mlx,
				fract->img, fract->x, fract->y)) < 0)
		return (0);
	return (1);
}

void	init_mandelbrot(t_fractal *fract)
{
	fract->name = "mandelbrot";
	fract->rmin = -1.7;
	fract->rmax = 0.7;
	fract->imin = -1.2;
	fract->imax = 1.2;
}

void	init_julia(t_fractal *fract)
{
	fract->name = "julia";
	fract->rmin = -1.7;
	fract->rmax = 1.7;
	fract->imin = -1.7;
	fract->imax = 1.7;
	fract->julia_index = (0 + fract->julia_ind_mv) % JULIA_SETS;
	fract->julia_x = 0;
	fract->julia_y = 0;
	fract->julia_const = malloc(sizeof(float *) * JULIA_SETS);
	init_julia_const(fract);
}

void	init_julia_const(t_fractal *fract)
{
	int	i;

	i = 0;
	while (i < JULIA_SETS)
		fract->julia_const[i++] = malloc(sizeof(float) * 2);
	fract->julia_const[0][0] = 0;
	fract->julia_const[0][1] = 0.8;
	fract->julia_const[1][0] = 0.37;
	fract->julia_const[1][1] = 0.1;
	fract->julia_const[2][0] = 0.355;
	fract->julia_const[2][1] = 0.355;
	fract->julia_const[3][0] = -0.54;
	fract->julia_const[3][1] = 0.54;
	fract->julia_const[4][0] = -0.4;
	fract->julia_const[4][1] = -0.59;
	fract->julia_const[5][0] = 0.34;
	fract->julia_const[5][1] = -0.05;
	fract->julia_const[6][0] = 0.355534;
	fract->julia_const[6][1] = -0.337292;
	fract->julia_const[7][0] = -1.34882125854492;
	fract->julia_const[7][1] = -0.454237874348958;
	fract->julia_const[8][0] = -0.202420806884766;
	fract->julia_const[8][1] = 0.39527333577474;
}
