/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaba <tobaba@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-17 08:05:35 by tobaba            #+#    #+#             */
/*   Updated: 2024-08-17 08:05:35 by tobaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	exit_param(t_param *param)
{
	mlx_destroy_window(param->mlx, param->win);
	exit(0);
}

void	create_param(t_param *param)
{
	param->mlx = mlx_init();
	if (param->mlx == NULL)
		exit(1);
	param->win = mlx_new_window(param->mlx, WIDTH, HEIGHT, "fract-ol");
	param->img.img = mlx_new_image(param->mlx, WIDTH, HEIGHT);
	param->img.addr = mlx_get_data_addr(param->img.img,
			&param->img.bits_per_pixel,
			&param->img.size_line, &param->img.endian);
	param->center_re = 0;
	param->center_im = 0;
	param->max_re = 2;
	param->max_im = 2;
	param->min_re = -2;
	param->min_im = -2;
	param->max_rota = 300;
}
