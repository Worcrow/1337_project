/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelboart_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <oel-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:11:26 by oel-asri          #+#    #+#             */
/*   Updated: 2024/07/09 11:44:48 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	color_mandel(int it, int x, int y, t_fractol *fr)
{
	int	color;

	color = (((it * 255) / fr->red) << 16) | (((it * 255) / fr->green) << 8) \
		| (((it * 255) / fr->blue));
	color_pixel(fr, x, y, color);
}

void	create_mandelboart(int x, int y, t_fractol *fr)
{
	int		it;
	int		point_outside;
	double	temp;

	fr->c.reel = map(x + fr->shift_x, REEL_LOWER_LIMIT, \
		REEL_UPPER_LIMIT) * fr->zoom;
	fr->c.imaginary = map(HEIGHT - y - fr->shift_y, IMAGINARY_LOWER_LIMIT, \
		IMAGINARY_UPPER_LIMIT) * fr->zoom;
	(1) && (fr->z.reel = 0, fr->z.imaginary = 0, point_outside = 0, it = 0);
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
		color_pixel(fr, x, y, 0x0000);
	else
		color_mandel(it, x, y, fr);
}
