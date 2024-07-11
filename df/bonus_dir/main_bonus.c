/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <oel-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:18:50 by oel-asri          #+#    #+#             */
/*   Updated: 2024/07/09 13:08:48 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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
	if (!ft_strcmp(fractal->name, "mandelbort"))
		fractal->shift_x = -100;
	else
		fractal->shift_x = -30;
	fractal->zoom = 1;
	fractal->shift_y = 0.0;
	fractal->blue = 100;
	fractal->green = 200;
	fractal->red = 250;
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

static void	set_fractal(t_fractol *fractol, char *name, \
	char *parm1, char *parm2)
{
	if (!ft_strcmp(name, "mandelbort"))
		ft_strcpy(fractol->name, "mandelbort");
	else if (!ft_strcmp(name, "julia"))
	{
		ft_strcpy(fractol->name, "julia");
		fractol->c.reel = ft_strtod(parm1);
		fractol->c.imaginary = ft_strtod(parm2);
	}
	else if (!ft_strcmp(name, "burningship"))
		ft_strcpy(fractol->name, "burningship");
	else
		send_error("Supported Argument: { \"mandelbort\" | \"\
julia nbr1 nbr2\"} \"burningship\"", EINVAL);
}

int	main(int argc, char *argv[])
{
	t_fractol	fractol;

	if (argc == 2 || argc == 4)
	{
		set_fractal(&fractol, argv[1], argv[2], argv[3]);
		window_init(&fractol);
		render(&fractol);
		mlx_key_hook(fractol.win_ptr, key_handler, &fractol);
		mlx_mouse_hook(fractol.win_ptr, mouse_handler, &fractol);
		mlx_hook(fractol.win_ptr, 17, 1L << 17, destroy_display, &fractol);
		mlx_loop(fractol.mlx_ptr);
	}
	else
		send_error("Usage: ./fractol mandelbort | ./fractol julia nbr1 \
nbr2 ./fractol burningship| ", EINVAL);
	return (0);
}
