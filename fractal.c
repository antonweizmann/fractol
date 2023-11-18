/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:09:46 by aweizman          #+#    #+#             */
/*   Updated: 2023/11/18 15:43:44 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	check_conds(t_fractal *fract)
{
	if (!ft_strncmp(fract->color_request, "psychedelic", 11))
		get_color(fract, 1);
	else if (!ft_strncmp(fract->color_request, "mono", 4))
		get_color(fract, 2);
	else if (!ft_strncmp(fract->color_request, "elegant", 7))
		get_color(fract, 3);
	else
		return (0);
	if (!ft_strncmp(fract->fractal_request, "mandelbrot", 10))
		fract->fract_type = MANDELBROT;
	else if (!ft_strncmp(fract->fractal_request, "julia", 5))
		fract->fract_type = JULIA;
	else if (!ft_strncmp(fract->fractal_request, "burningship", 11))
		fract->fract_type = BURNINGSHIP;
	else
		return (0);
	return (1);
}

void	get_color(t_fractal *fract, int c)
{
	if (c == 1)
	{
		fract->r = 1;
		fract->g = 9;
		fract->b = 2;
	}
	else if (c == 2)
	{
		fract->r = 5;
		fract->g = 3;
		fract->b = 6;
	}
	else if (c == 3)
	{
		fract->r = 9;
		fract->g = 8;
		fract->b = 7;
	}
}

void	draw_fractal(void *param)
{
	t_fractal	*fract;

	fract = param;
	check_img(fract);
	if (fract->fract_type == MANDELBROT)
		mandelbrot(fract);
	else if (fract->fract_type == JULIA)
		julia(fract);
	else if (fract->fract_type == BURNINGSHIP)
		burningship(fract);
	else
		return ;
}

void	check_img(t_fractal *fract)
{
	int	i;

	i = 0;
	if (fract->mlx->height != fract->height
		|| fract->mlx->width != fract->width)
	{
		fract->height = fract->mlx->height;
		fract->width = fract->mlx->width;
		mlx_delete_image(fract->mlx, fract->img);
		fract->img = mlx_new_image(fract->mlx, fract->width, fract->height);
		if (!fract->img || (mlx_image_to_window(fract->mlx,
					fract->img, 0, 0)) < 0)
			return ;
	}
}
