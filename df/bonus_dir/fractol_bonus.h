/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-asri <oel-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:08:06 by oel-asri          #+#    #+#             */
/*   Updated: 2024/07/09 11:44:27 by oel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <math.h>
//#include <X11/keysym.h>

# define HEIGHT 800
# define WIDTH 800
# define MAX_ITERATION 100
# define REEL_LOWER_LIMIT -2.0
# define REEL_UPPER_LIMIT 2.0 
# define IMAGINARY_LOWER_LIMIT -2.0
# define IMAGINARY_UPPER_LIMIT 2.0

typedef struct complex
{
	double	reel;
	double	imaginary;
}	t_complex;

typedef struct fractal
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*addr;
	int			depth;
	int			bits_per_pixel;
	int			endian;
	t_complex	z;
	t_complex	c;
	char		name[13];
	double		shift_x;
	double		shift_y;
	double		zoom;
	int			red;
	int			blue;
	int			green;
}	t_fractol;

int		ft_strcmp(char *str1, char *str2);
void	to_lower(char *str);
void	ft_strcpy(char *dest, char *src);
int		send_error(char *message, int err);
void	render(t_fractol *fractal);
void	image_initializer(t_fractol *fractal);
void	create_mandelboart(int x, int y, t_fractol *fractal);
void	color_pixel(t_fractol *fractal, int x, int y, int color);
int		destroy_display(t_fractol *fractal);
int		key_handler(int keysym, t_fractol *fractal);
int		mouse_handler(int keysym, int x, int y, t_fractol *fractal);
void	create_julia(int x, int y, t_fractol *fractal);
void	create_burning_ship(int x, int y, t_fractol *fr);
double	ft_strtod(char *str);
double	map(double x, double out_min, double out_max);
#endif
