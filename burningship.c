/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:05:28 by aweizman          #+#    #+#             */
/*   Updated: 2023/11/16 17:51:25 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	burningship(t_fractal *fract)
{
	fract->y = 0;
	fract->pxsize = (fract->rmax - fract->rmin) / fract->width;
	while (fract->y < fract->height)
	{
		fract->x = 0;
		while (fract->x < fract->width)
		{
			calculate_burningship(fract);
			fract->x += 1;
		}
		fract->y += 1;
	}
}

void	calculate_burningship(t_fractal *fract)
{
	double	t;
	int		n;

	fract->zr = 0;
	fract->zi = 0;
	fract->cr = fract->rmin + fract->x * fract->pxsize;
	fract->ci = fract->imax - fract->y * fract->pxsize;
	n = 0;
	while (n < fract->max_iter && ((fract->zr * fract->zr)
			+ (fract->zi * fract->zi) < 4.))
	{
		t = fract->zr * fract->zr - fract->zi * fract->zi + fract->cr;
		fract->zi = 2 * fract->zr * fract->zi;
		fract->zi = (2 * (fract->zi < 0) - 1) * fract->zi + fract->ci;
		fract->zr = t;
		n++;
	}
	t = 1.0 * n / fract->max_iter;
	fract->color = ft_pixel(fract->r * 255 * (1 - t) * t * t * t,
			fract->g * 255 * (1 - t) * (1 - t) * t * t,
			fract->b * 255 * (1 - t) * (1 - t) * (1 - t) * t, 180);
	if (n == fract->max_iter)
		mlx_put_pixel(fract->img, fract->x, fract->y, ft_pixel(0, 0, 0, 255));
	else
		mlx_put_pixel(fract->img, fract->x, fract->y, fract->color);
}
