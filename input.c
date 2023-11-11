/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:37:27 by aweizman          #+#    #+#             */
/*   Updated: 2023/11/11 18:44:43 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	input_left(mlx_key_data_t key, void *param)
{
	t_fractal	*fract;
	double		range;

	fract = param;
	range = fract->rmax - fract->rmin;
	if (key.key == MLX_KEY_LEFT && key.action == MLX_PRESS)
	{
		fract->rmax -= 0.02 * range;
		fract->rmin -= 0.02 * range;
	}
	else if (key.key == MLX_KEY_LEFT && (key.modifier == MLX_KEY_LEFT_ALT
			|| key.modifier == MLX_KEY_RIGHT_ALT) && key.action == MLX_PRESS)
		fract->julia_x -= 0.001;
}

void	input_right(mlx_key_data_t key, void *param)
{
	t_fractal	*fract;
	double		range;

	fract = param;
	range = fract->rmax - fract->rmin;
	if (key.key == MLX_KEY_RIGHT)
	{
		fract->rmax += 0.02 * range;
		fract->rmin += 0.02 * range;
	}
	else if (key.key == MLX_KEY_RIGHT && (key.modifier == MLX_KEY_LEFT_ALT
			|| key.modifier == MLX_KEY_RIGHT_ALT))
		fract->julia_x += 0.001;
}

void	input_up(mlx_key_data_t key, void *param)
{
	t_fractal	*fract;
	double		range;

	fract = param;
	range = fract->rmax - fract->rmin;
	if (key.key == MLX_KEY_UP)
	{
		fract->imax += 0.02 * range;
		fract->imin += 0.02 * range;
	}
	else if (key.key == MLX_KEY_UP && (key.modifier == MLX_KEY_LEFT_ALT
			|| key.modifier == MLX_KEY_RIGHT_ALT))
		fract->julia_y += 0.001;
}

void	input_down(mlx_key_data_t key, void *param)
{
	t_fractal	*fract;
	double		range;

	fract = param;
	range = fract->rmax - fract->rmin;
	if (key.key == MLX_KEY_DOWN)
	{
		fract->imax -= 0.02 * range;
		fract->imin -= 0.02 * range;
	}
	else if (key.key == MLX_KEY_DOWN && (key.modifier == MLX_KEY_LEFT_ALT
			|| key.modifier == MLX_KEY_RIGHT_ALT))
		fract->julia_y -= 0.001;
}

void	input_esc(mlx_key_data_t key, void *param)
{
	t_fractal	*fract;
	double		range;

	fract = param;
	if (key.key == MLX_KEY_ESCAPE)
		mlx_close_window(fract->mlx);
}
