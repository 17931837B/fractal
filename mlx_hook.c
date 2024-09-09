/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaba <tobaba@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-17 08:06:40 by tobaba            #+#    #+#             */
/*   Updated: 2024-08-17 08:06:40 by tobaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	key_press_hook(int keycode, t_param *param)
{
	if (keycode == 65307)
		exit_param(param);
	if (keycode == 65363 && param->c_re < 100)
		param->c_re += UPDOWN;
	if (keycode == 65361 && param->c_re > -100)
		param->c_re -= UPDOWN;
	if (keycode == 65362 && param->c_im < 100)
		param->c_im += UPDOWN;
	if (keycode == 65364 && param->c_im > -100)
		param->c_im -= UPDOWN;
	return (0);
}

static void	scaling_calculate(t_param *param, double scale)
{
	double	re;
	double	im;

	re = param->center_re;
	im = param->center_im;
	param->min_re = re - ((re - param->min_re) * scale);
	param->max_re = re + ((param->max_re - re) * scale);
	param->min_im = im - ((im - param->min_im) * scale);
	param->max_im = im + ((param->max_im - im) * scale);
}

static void	zoom_param(t_param *param, int button, int x, int y)
{
	double	scale;

	if (button == 5)
		scale = 1.05;
	else if (button == 4)
		scale = 0.95;
	scaling_calculate(param, scale);
}

static void	set_senter(t_param *param, int x, int y)
{
	param->center_re = (double)x
		/ (WIDTH / (param->max_re - param->min_re)) + param->min_re;
	param->center_im = (double)y
		/ (HEIGHT / (param->max_im - param->min_im)) + param->min_im;
}

int	mouse_hook(int button, int x, int y, t_param *param)
{
	if (button == 1)
		set_senter(param, x, y);
	if (button == 4 || button == 5)
		zoom_param(param, button, x, y);
	return (0);
}
