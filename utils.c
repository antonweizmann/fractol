/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:39:42 by aweizman          #+#    #+#             */
/*   Updated: 2023/11/09 17:38:28 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	msg(char *str)
{
	printf("%s\n", str);
}

int	error(void)
{
	msg(".fractal <fractal> <color_scheme>");
	msg("Please choose a type of fractal and its color scheme.");
	msg("Your <fractal> options are: mandelbrot, \
julia, burningship, mandelbox.");
	msg("Your <color_scheme> options are: mono, elegant, psychedelic.");
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
