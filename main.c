/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:35:29 by aweizman          #+#    #+#             */
/*   Updated: 2023/11/16 17:58:24 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	main(int argc, char **argv)
{
	t_fractal	*fract;

	if (argc < 3)
		return (error());
	fract = malloc(sizeof(t_fractal));
	if (!fract)
		return (ft_printf("memory could not be allocated\n"), 0);
	fract->color_request = argv[2];
	fract->fractal_request = argv[1];
	if (!check_conds(fract))
		return (error());
	init(fract);
	mlx_loop_hook(fract->mlx, &draw_fractal, fract);
	mlx_loop_hook(fract->mlx, &input_move, fract);
	mlx_loop_hook(fract->mlx, &input_julia, fract);
	mlx_loop_hook(fract->mlx, &util_hooks, fract);
	mlx_key_hook(fract->mlx, reload, fract);
	mlx_scroll_hook(fract->mlx, zoom, fract);
	mlx_loop(fract->mlx);
	mlx_terminate(fract->mlx);
	return (0);
}

// draw_fractal into hook (maybae argv check somewhere else)
// zoom
// finish everything then play with color

	// mlx_key_hook(fract->mlx, &input_left, fract);
	// mlx_key_hook(fract->mlx, &input_right, fract);
	// mlx_key_hook(fract->mlx, &input_up, fract);
	// mlx_key_hook(fract->mlx, &input_down, fract);
	// mlx_key_hook(fract->mlx, &input_esc, fract);
	// mlx_key_hook(fract->mlx, input_reload, fract);
