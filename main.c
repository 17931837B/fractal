/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaba <tobaba@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-17 08:05:21 by tobaba            #+#    #+#             */
/*   Updated: 2024-08-17 08:05:21 by tobaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

static int	main_loop(t_param *param)
{
	if (ft_strcmp(param->drawer, "mandelbrot") == 0)
		draw_mandelbrot(param);
	else if (ft_strcmp(param->drawer, "julia") == 0)
		draw_julia(param);
	mlx_put_image_to_window(param->mlx, param->win, param->img.img, 0, 0);
	return (0);
}

static int	check_mandelbrot(char *argv)
{
	if (ft_strcmp(argv, "mandelbrot") == 0)
		return (0);
	return (1);
}

static void	set_viewer(char *argv, t_param *param)
{
	if (ft_strcmp(argv, "mandelbrot") == 0)
		param->drawer = "mandelbrot";
	else if (ft_strcmp(argv, "julia") == 0)
		param->drawer = "julia";
}

int	main(int argc, char **argv)
{
	t_param	param;

	if (argc != 2 || check_mandelbrot(argv[1]))
	{
		if (argc != 3 || check_julia(argv, &param))
		{
			write(1, "Please select either\n", 21);
			write(1, "<mandelbrot>\n", 13);
			write(1, "<julia> <key num>\n", 19);
			write(1, "---Julia Key List---\n", 21);
			write(1, "   -0.8		-0.72		-0.70\n", 22);
			write(1, "   -0.4		0.28		0.35		0.45\n", 26);
			return (1);
		}
	}
	create_param(&param);
	set_viewer(argv[1], &param);
	mlx_hook(param.win, KeyPress, KeyPressMask, key_press_hook, &param);
	mlx_hook(param.win, ClientMessage, StructureNotifyMask, exit_param, &param);
	mlx_mouse_hook(param.win, mouse_hook, &param);
	mlx_loop_hook(param.mlx, &main_loop, &param);
	mlx_loop(param.mlx);
}
