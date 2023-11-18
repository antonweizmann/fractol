/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:39:42 by aweizman          #+#    #+#             */
/*   Updated: 2023/11/18 15:44:41 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	random_color(t_fractal *fract)
{
	unsigned long	a;
	unsigned long	b;
	unsigned long	d;
	unsigned long	c;
	unsigned long	m;

	a = 1664525;
	b = 984211;
	d = 2477653;
	c = 1013904223;
	m = 4294967296;
	fract->r = ((a * fract->r + c) % m) % 20;
	fract->g = ((b * fract->g + c) % m) % 20;
	fract->b = ((d * fract->b + c) % m) % 20;
}

int	error(void)
{
	ft_printf(".fractal <fractal> <color_scheme>\n");
	ft_printf("Please choose a type of fractal and its color scheme.\n");
	ft_printf("Your <fractal> options are: mandelbrot, \
julia, burningship, mandelbox.\n");
	ft_printf("Your <color_scheme> options are: mono, elegant, psychedelic.\n");
	return (0);
}

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	int					diff;
	const unsigned char	*s1;
	const unsigned char	*s2;
	size_t				i;

	s1 = (unsigned char *) str1;
	s2 = (unsigned char *) str2;
	i = 0;
	diff = 0;
	while (!diff && *s1 && *s2 && i++ < n)
		diff = *s1++ - *s2++;
	if (!diff && (*s1 || *s2) && i++ < n)
		diff = *s1++ - *s2++;
	return (diff);
}

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	display_menu(t_fractal *fract)
{
	fract->strs[0] = mlx_put_string(fract->mlx, "Controls", 460, 355);
	fract->strs[1] = mlx_put_string(fract->mlx, "Reset          - R", 385, 400);
	fract->strs[2] = mlx_put_string(fract->mlx, "Color Shift    - C", 385, 430);
	fract->strs[3] = mlx_put_string(fract->mlx,
			"Move           - Arrows", 385, 460);
	fract->strs[4] = mlx_put_string(fract->mlx,
			"Zoom           - Scroll", 385, 490);
	fract->strs[5] = mlx_put_string(fract->mlx,
			"Julia Constant - WASD", 385, 520);
}
