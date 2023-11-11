/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:56:19 by aweizman          #+#    #+#             */
/*   Updated: 2023/11/11 14:06:47 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	init(t_fractal *fract)
{
	fract->x = 0;
	fract->y = 0;
	if (fract->fract_type == MANDELBROT)
		init_mandelbrot(fract);
	// else if (fract->fract_type == JULIA)
	// 	init_julia(fract);
	// else if (fract->fract_type == BURNINGSHIP)
	// 	init_burningship(fract);
	// else if (fract->fract_type == MANDELBOX)
	// 	init_mandelbox(fract);
	fract->zoom = 1.05;
	fract->max_iter = 100;
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
