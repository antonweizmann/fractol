/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:23:43 by aweizman          #+#    #+#             */
/*   Updated: 2023/11/11 13:58:49 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	zoom(double xdelta, double ydelta, void *param)
{
	t_fractal	*fract;
	double		range;
	double		new_range;
	double		x_ratio;
	double		y_ratio;

	xdelta = 0;
	fract = param;
	fract->mouse_x = 0;
	fract->mouse_y = 0;
	mlx_get_mouse_pos(fract->mlx, &fract->mouse_x, &fract->mouse_y);
	x_ratio = (double)fract->mouse_x / fract->width;
	y_ratio = (double)fract->mouse_y / fract->height;
	range = fract->rmax - fract->rmin;
	if (ydelta > 0)
		new_range = range * (1 / fract->zoom) - range;
	if (ydelta < 0)
		new_range = range * fract->zoom - range;
	fract->rmin = fract->rmin - new_range * x_ratio;
	fract->rmax = fract->rmax + new_range * (1 - x_ratio);
	fract->imax = fract->imax + new_range * y_ratio;
	fract->imin = fract->rmin - new_range * (1 - y_ratio);
}

void	input_move(void *param)
{
	t_fractal	*fract;
	double		range;

	fract = param;
	range = fract->rmax - fract->rmin;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fract->mlx);
	if (mlx_is_key_down(fract->mlx, MLX_KEY_RIGHT))
	{
		fract->rmax += 0.02 * range;
		fract->rmin += 0.02 * range;
	}
	if (mlx_is_key_down(fract->mlx, MLX_KEY_LEFT))
	{
		fract->rmax -= 0.02 * range;
		fract->rmin -= 0.02 * range;
	}
	if (mlx_is_key_down(fract->mlx, MLX_KEY_UP))
	{
		fract->imax += 0.02 * range;
		fract->imin += 0.02 * range;
	}
	if (mlx_is_key_down(fract->mlx, MLX_KEY_DOWN))
	{
		fract->rmax -= 0.02 * range;
		fract->rmin -= 0.02 * range;
	}
}
