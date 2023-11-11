/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:09:46 by aweizman          #+#    #+#             */
/*   Updated: 2023/11/11 18:27:47 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	check_conds(t_fractal *fract)
{
	if (!ft_strncmp(fract->color_request, "psychedelic", 11))
		fract->color = 0xFCBE11;
	else if (!ft_strncmp(fract->color_request, "mono", 4))
		fract->color = 0xFFFFFF;
	else if (!ft_strncmp(fract->color_request, "elegant", 7))
		fract->color = 0xB08E6B;
	else
		return (0);
	if (!ft_strncmp(fract->fractal_request, "mandelbrot", 10))
		fract->fract_type = MANDELBROT;
	else if (!ft_strncmp(fract->fractal_request, "julia", 5))
		fract->fract_type = JULIA;
	// else if (!ft_strncmp(fract->fractal_request, "burningship", 11))
	// 	fract->fract_type = BURNINGSHIP;
	// else if (!ft_strncmp(fract->fractal_request, "mandelbox", 9))
	// 	fract->fract_type = MANDELBOX;
	else
		return (0);
	return (1);
}

void	draw_fractal(void *param)
{
	t_fractal	*fract;

	fract = param;
	if (fract->fract_type == MANDELBROT)
		mandelbrot(fract);
	else if (fract->fract_type == JULIA)
		julia(fract);
	// else if (fract->fract_type == BURNINGSHIP)
	// 	burningship(fract);
	// else if (fract->fract_type == MANDELBOX)
	// 	mandelbox(fract);
	else
		return ;
}
