/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <oel-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:16:34 by oel-asri          #+#    #+#             */
/*   Updated: 2024/07/09 12:59:35 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	key_handler(int keysym, t_fractol *fractal)
{
	if (keysym == 53)
		destroy_display(fractal);
	else if (keysym == 123)
		fractal->shift_x += 10;
	else if (keysym == 124)
		fractal->shift_x -= 10;
	else if (keysym == 126)
		fractal->shift_y += 10;
	else if (keysym == 125)
		fractal->shift_y -= 10;
	else if (keysym == 49)
	{
		fractal->red = (fractal->red * 10) % 255;
		fractal->green = (fractal->green * 10) % 255;
		fractal->blue = (fractal->blue * 10) % 255;
	}
	mlx_destroy_image(fractal->mlx_ptr, fractal->img);
	render(fractal);
	return (0);
}

int	mouse_handler(int keysym, int x __attribute__ ((unused)), int y \
	__attribute__ ((unused)), t_fractol *fractal)
{
	if (keysym == 4)
		fractal->zoom *= 0.3;
	if (keysym == 5)
		fractal->zoom /= 0.3;
	mlx_destroy_image(fractal->mlx_ptr, fractal->img);
	render(fractal);
	return (0);
}
