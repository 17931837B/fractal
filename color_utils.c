/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaba <tobaba@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-17 08:05:04 by tobaba            #+#    #+#             */
/*   Updated: 2024-08-17 08:05:04 by tobaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	paint_color_julia(t_img *img, int x, int y, int color)
{
	char	*pos;
	int		mirror_x;

	mirror_x = WIDTH - x - 1;
	pos = img->addr + (y * img->size_line
			+ mirror_x * (img->bits_per_pixel / 8));
	*(unsigned int *)pos = color;
}

void	paint_color_man(t_img *img, int x, int y, int color)
{
	char	*pos;

	pos = img->addr + (y * img->size_line
			+ x * (img->bits_per_pixel / 8));
	*(unsigned int *)pos = color;
}

unsigned int	rgb_num(int r, int g, int b)
{
	unsigned int	res;

	res = r * 65536 + g * 256 + b;
	return (res);
}
