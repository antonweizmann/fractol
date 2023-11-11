/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:32:38 by aweizman          #+#    #+#             */
/*   Updated: 2023/11/11 17:55:25 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	julia(t_fractal *fract)
{
	int		n;

	fract->y = 0;
	fract->pxsize = (fract->rmax - fract->rmin) / fract->width;
	while (fract->y < fract->height)
	{
		fract->x = 0;
		while (fract->x < fract->width)
		{
			calculate_julia(fract);
			fract->x += 1;
		}
		fract->y += 1;
	}
}

void	calculate_julia(t_fractal *fract)
{
	double	t;
	int		n;

	fract->zr = fract->rmin + fract->x * fract->pxsize;
	fract->zi = fract->imax - fract->y * fract->pxsize;
	fract->cr = fract->julia_const[fract->julia_index][0] + fract->julia_x;
	fract->ci = fract->julia_const[fract->julia_index][1] + fract->julia_y;
	n = 0;
	while (n < fract->max_iter && ((fract->zr * fract->zr)
			+ (fract->zi * fract->zi) < 4.))
	{
		t = fract->zr * fract->zr - fract->zi * fract->zi + fract->cr;
		fract->zi = 2 * fract->zr * fract->zi + fract->ci;
		fract->zr = t;
		n++;
	}
	t = 1.0 * n / fract->max_iter;
	fract->color = ft_pixel(10 * 255 * (1 - t) * t * t * t,
			255 * 255 * (1 - t) * (1 - t) * t * t,
			30 * 255 * (1 - t) * (1 - t) * (1 - t) * t, 180);
	if (n == fract->max_iter)
		mlx_put_pixel(fract->img, fract->x, fract->y, ft_pixel(0, 0, 0, 255));
	else
		mlx_put_pixel(fract->img, fract->x, fract->y, fract->color);
}
