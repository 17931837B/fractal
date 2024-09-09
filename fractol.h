/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaba <tobaba@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-19 03:06:22 by tobaba            #+#    #+#             */
/*   Updated: 2024-08-19 03:06:22 by tobaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRACTOL_H
# define FRACTOL_H

# include "./minilibx-linux/mlx.h"
# include <X11/X.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 900
# define HEIGHT 900
# define UPDOWN 1.0e-2

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_param
{
	void				*mlx;
	void				*win;
	t_img				img;
	char				*drawer;
	double				min_re;
	double				min_im;
	double				center_re;
	double				center_im;
	double				max_re;
	double				max_im;
	int					max_rota;
	double				z_re;
	double				z_im;
	double				c_re;
	double				c_im;
}	t_param;

int				exit_param(t_param *param);
void			create_param(t_param *param);
void			paint_color_man(t_img *img, int x, int y, int color);
void			paint_color_julia(t_img *img, int x, int y, int color);
int				key_press_hook(int keycode, t_param *param);
int				mouse_hook(int button, int x, int y, t_param *param);
int				draw_julia(t_param *param);
int				draw_mandelbrot(t_param *param);
unsigned int	rgb_num(int r, int g, int b);
int				check_julia(char **argv, t_param *param);
int				ft_strcmp(const char *s1, const char *s2);

#endif
