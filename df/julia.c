/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <oel-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 07:19:05 by oel-asri          #+#    #+#             */
/*   Updated: 2024/07/09 09:13:13 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	get_color_julia(int it)
{
	return ((((it * 255) / 150) << 16) | (((it * 255) / 150) << 8) \
		| (((it * 255) / 150)));
}

void	create_julia(int x, int y, t_fractol *fr)
{
	int		it;
	int		point_outside;
	double	temp;

	fr->z.reel = map(x, REEL_LOWER_LIMIT, REEL_UPPER_LIMIT) * fr->zoom;
	fr->z.imaginary = map(800 - y, IMAGINARY_LOWER_LIMIT, \
		IMAGINARY_UPPER_LIMIT) * fr->zoom;
	point_outside = 0;
	it = 0;
	while (it++ < MAX_ITERATION && !point_outside)
	{
		temp = fr->z.reel * fr->z.reel - fr->z.imaginary * \
		fr->z.imaginary + fr->c.reel;
		fr->z.imaginary = 2 * fr->z.reel * fr->z.imaginary + fr->c.imaginary;
		fr->z.reel = temp;
		if (sqrt(fr->z.reel * fr->z.reel + fr->z.imaginary * \
			fr->z.imaginary) > 2.0)
			point_outside = 1;
	}
	if (!point_outside)
		color_pixel(fr, x, y, 0x000000);
	else
		color_pixel(fr, x, y, get_color_julia(it));
}