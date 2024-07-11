/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <oel-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 06:59:54 by oel-asri          #+#    #+#             */
/*   Updated: 2024/07/09 11:52:36 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	window_init(t_fractol *fractal)
{
	fractal->mlx_ptr = mlx_init();
	if (!fractal->mlx_ptr)
		send_error("Can't Allocate", ENOMEM);
	fractal->win_ptr = mlx_new_window(fractal->mlx_ptr, WIDTH, \
		HEIGHT, fractal->name);
	if (!fractal->win_ptr)
	{
		free(fractal->mlx_ptr);
		send_error("Can't Allocate", ENOMEM);
	}
	fractal->zoom = 1;
}

double	map(double x, double out_min, double out_max)
{
	return (x * (out_max - out_min) / 800 + out_min);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	to_lower(str1);
	while (str1 && str2 && str1[i] == str2[i] && str1[i] && str2[i])
	{
		++i;
	}
	return (str1[i] - str2[i]);
}

int	main(int argc, char *argv[])
{
	t_fractol	fractol;

	if (argc >= 2)
	{
		if (!ft_strcmp(argv[1], "mandelbort"))
			ft_strcpy(fractol.name, argv[1]);
		else if (!ft_strcmp(argv[1], "julia") && argc == 4)
		{
			ft_strcpy(fractol.name, argv[1]);
			fractol.c.reel = ft_strtod(argv[2]);
			fractol.c.imaginary = ft_strtod(argv[3]);
		}
		else
			send_error("Supported Argument: { \"mandelbort\" | \"\
julia nbr1 nbr2\"}", EINVAL);
		window_init(&fractol);
		render(&fractol);
		mlx_key_hook(fractol.win_ptr, key_handler, &fractol);
		mlx_mouse_hook(fractol.win_ptr, mouse_handler, &fractol);
		mlx_hook(fractol.win_ptr, 17, 1L << 17, destroy_display, &fractol);
		mlx_loop(fractol.mlx_ptr);
	}
	else
		send_error("Usage: ./fractol mandelbort | ./fractol julia nbr1 \
nbr2", EINVAL);
	return (0);
}
