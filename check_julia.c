/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaba <tobaba@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-17 08:04:55 by tobaba            #+#    #+#             */
/*   Updated: 2024-08-17 08:04:55 by tobaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	set_c(t_param *param, double re, double im)
{
	param->c_re = re;
	param->c_im = im;
	return (1);
}

int	check_julia_key(char *argv, t_param *param)
{
	int	res;

	res = 0;
	if (ft_strcmp(argv, "-0.4") == 0)
		res = set_c(param, -0.4, 0.6);
	else if (ft_strcmp(argv, "0.28") == 0)
		res = set_c(param, 0.285, 0.01);
	else if (ft_strcmp(argv, "0.45") == 0)
		res = set_c(param, 0.45, 0.1428);
	else if (ft_strcmp(argv, "-0.70") == 0)
		res = set_c(param, -0.70176, -0.3842);
	else if (ft_strcmp(argv, "-0.8") == 0)
		res = set_c(param, -0.8, 0.156);
	else if (ft_strcmp(argv, "-0.72") == 0)
		res = set_c(param, -0.7269, 0.1889);
	else if (ft_strcmp(argv, "0.35") == 0)
		res = set_c(param, 0.35, 0.35);
	return (res);
}

int	check_julia(char **argv, t_param *param)
{
	if (ft_strcmp(argv[1], "julia") == 0)
	{
		if (check_julia_key(argv[2], param))
			return (0);
	}
	return (1);
}
