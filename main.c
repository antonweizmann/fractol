/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:35:29 by aweizman          #+#    #+#             */
/*   Updated: 2023/11/11 13:59:42 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	main(int argc, char **argv)
{
	t_fractal	*fract;

	if (argc != 3)
		return (error());
	fract = malloc(sizeof(t_fractal));
	if (!fract)
		return (msg("memory could not be allocated"), 0);
	fract->color_request = argv[2];
	fract->fractal_request = argv[1];
	if (!check_conds(fract))
		return (error());
	if (!init(fract))
		return (error());
	mlx_loop_hook(fract->mlx, &draw_fractal, fract);
	mlx_loop_hook(fract->mlx, &input_move, fract);
	mlx_scroll_hook(fract->mlx, zoom, fract);
	mlx_loop(fract->mlx);
	mlx_terminate(fract->mlx);
	return (0);
}

// draw_fractal into hook (maybe argv check somewhere else)
// zoom
// finish everything then play with color
