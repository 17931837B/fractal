/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaba <tobaba@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-17 08:05:16 by tobaba            #+#    #+#             */
/*   Updated: 2024-08-17 08:05:16 by tobaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

static unsigned int	choice_color(t_param *param)
{
	int		i;
	int		color;
	double	tmp;

	i = 0;
	while (param->z_re * param->z_re + param->z_im * param->z_im <= 4
		&& i < param->max_rota)
	{
		tmp = param->z_re * param->z_re - param->z_im
			* param->z_im + param->c_re;
		param->z_im = 2 * param->z_re * param->z_im + param->c_im;
		param->z_re = tmp;
		i++;
	}
	if (i == param->max_rota)
		color = rgb_num(255, 160, 16);
	else
		color = rgb_num((255 * i) / param->max_rota, 0, 0);
	return (color);
}

int	draw_mandelbrot(t_param *param)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			param->c_re = param->min_re + x * (param->max_re - param->min_re)
				/ (WIDTH - 1);
			param->c_im = param->min_im + y * (param->max_im - param->min_im)
				/ (HEIGHT - 1);
			param->z_re = 0;
			param->z_im = 0;
			paint_color_man(&param->img, x, y, choice_color(param));
			x++;
		}
		y++;
	}
	return (0);
}

int	draw_julia(t_param *param)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			param->z_re = param->min_re + x * (param->max_re - param->min_re)
				/ (WIDTH - 1);
			param->z_im = param->min_im + y * (param->max_im - param->min_im)
				/ (HEIGHT - 1);
			paint_color_julia(&param->img, x, y, choice_color(param));
			x++;
		}
		y++;
	}
	return (0);
}
