/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <oel-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 07:48:45 by oel-asri          #+#    #+#             */
/*   Updated: 2024/07/09 12:54:40 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_handler(int keysym, t_fractol *fractal)
{
	if (keysym == 53)
		destroy_display(fractal);
	return (0);
}

int	mouse_handler(int keysym, int x __attribute__ ((unused)), \
	int y __attribute__ ((unused)), t_fractol *fractal)
{
	if (keysym == 4)
		fractal->zoom *= 0.3;
	if (keysym == 5)
		fractal->zoom /= 0.3;
	mlx_destroy_image(fractal->mlx_ptr, fractal->img);
	render(fractal);
	return (0);
}
