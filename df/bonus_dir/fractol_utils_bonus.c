/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <oel-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:14:13 by oel-asri          #+#    #+#             */
/*   Updated: 2024/07/09 09:50:16 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	to_lower(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		++i;
	}
}

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src && src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
}

int	send_error(char *message, int err)
{
	int	i;

	i = 0;
	errno = err;
	while (message && message[i] != '\0')
	{
		write(2, message + i, 1);
		++i;
	}
	write(2, ": ", 2);
	perror(NULL);
	exit(err);
}

void	color_pixel(t_fractol *fractal, int x, int y, int color)
{
	char	*pixel_to_color;

	pixel_to_color = fractal->addr + (y * fractal->depth + \
		(x * fractal->bits_per_pixel / 8));
	*(unsigned int *)pixel_to_color = color;
}

int	destroy_display(t_fractol *fractal)
{
	if (fractal->img)
	{
		mlx_destroy_image(fractal->mlx_ptr, fractal->img);
		fractal->img = NULL;
	}
	if (fractal->win_ptr)
	{
		mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
		fractal->win_ptr = NULL;
	}
	if (fractal->mlx_ptr)
		fractal->mlx_ptr = NULL;
	exit(0);
}
