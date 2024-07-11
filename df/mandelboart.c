/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelboart.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <oel-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 07:25:51 by oel-asri          #+#    #+#             */
/*   Updated: 2024/07/09 07:45:04 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	color_mandel(int it, int x, int y, t_fractol *fr)
{
	int	color;

	color = (((it * 255) / 150) << 16) | (((it * 255) / 100) << 8) \
		| (((it * 255) / 50));
	color_pixel(fr, x, y, color);
}

void	create_mandelboart(int x, int y, t_fractol *fr)
{
	int		it;
	int		point_outside;
	double	temp;

	fr->c.reel = (map(x, REEL_LOWER_LIMIT, REEL_UPPER_LIMIT) - 0.4) * fr->zoom;
	fr->c.imaginary = map(y, IMAGINARY_LOWER_LIMIT, \
		IMAGINARY_UPPER_LIMIT) * fr->zoom;
	fr->z.reel = 0;
	fr->z.imaginary = 0;
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
		color_mandel(it, x, y, fr);
}
