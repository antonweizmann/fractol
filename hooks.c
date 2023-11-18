/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:23:43 by aweizman          #+#    #+#             */
/*   Updated: 2023/11/18 15:44:31 by aweizman         ###   ########.fr       */
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

void	util_hooks(void *param)
{
	t_fractal	*fract;

	fract = param;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_R))
	{
		if (fract->fract_type == MANDELBROT)
			init_mandelbrot(fract);
		else if (fract->fract_type == BURNINGSHIP)
			init_burningship(fract);
		else if (fract->fract_type == JULIA)
		{
			fract->julia_ind_mv += 1;
			init_julia(fract);
		}
	}
	if (mlx_is_key_down(fract->mlx, MLX_KEY_C))
		random_color(fract);
}

void	input_move(void *param)
{
	t_fractal	*fract;
	double		range;

	fract = param;
	range = fract->rmax - fract->rmin;
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
		fract->imax -= 0.02 * range;
		fract->imin -= 0.02 * range;
	}
}

void	input_julia(void *param)
{
	t_fractal	*fract;

	fract = param;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fract->mlx);
	if (mlx_is_key_down(fract->mlx, MLX_KEY_W))
		fract->julia_y += 0.001;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_S))
		fract->julia_y -= 0.001;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_A))
		fract->julia_x -= 0.001;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_D))
		fract->julia_x += 0.001;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_W)
		&& mlx_is_key_down(fract->mlx, MLX_KEY_LEFT_SHIFT))
		fract->julia_y += 0.01;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_S)
		&& mlx_is_key_down(fract->mlx, MLX_KEY_LEFT_SHIFT))
		fract->julia_y -= 0.01;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_A)
		&& mlx_is_key_down(fract->mlx, MLX_KEY_LEFT_SHIFT))
		fract->julia_x -= 0.01;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_D)
		&& mlx_is_key_down(fract->mlx, MLX_KEY_LEFT_SHIFT))
		fract->julia_x += 0.01;
}

void	reload(mlx_key_data_t key, void *param)
{
	t_fractal	*fract;
	int			i;

	i = 0;
	fract = param;
	if (key.key == MLX_KEY_H && key.action == MLX_PRESS)
	{
		display_menu(fract);
	}
	if (key.key == MLX_KEY_H && key.action == MLX_RELEASE)
	{
		while (fract->strs[i] != 0)
		{
			mlx_delete_image(fract->mlx, fract->strs[i++]);
		}
	}
}
