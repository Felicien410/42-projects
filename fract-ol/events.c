/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:55:25 by fcatteau          #+#    #+#             */
/*   Updated: 2023/03/14 19:02:39 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Includes/fractol.h"

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == 123)
		vars->zoom.corx = vars->zoom.corx - 0.01;
	if (keycode == 124)
		vars->zoom.corx = vars->zoom.corx + 0.01;
	if (keycode == 126)
		vars->itter = vars->itter + 10;
	if (keycode == 125)
		vars->itter = vars->itter - 10;
	if (keycode == 18)
		vars->color = 0x880808;
	if (keycode == 19)
		vars->color = 0x062b16;
	remake (vars);
	if (keycode == ESC)
	{
		mlx_destroy_window (vars->mlx, vars->win);
		system("leaks fractol");
		exit (0);
	}
	return (0);
}

int	mouse(int keycode, int x, int y, t_vars *vars)
{
	double	im_range;
	double	re_range;

	re_range = vars->min_re
		+ ((double)x * (vars->max_re - vars->min_re)) / WIDTH;
	im_range = vars->min_im
		+ ((double)y * (vars->max_im - vars->min_im)) / HEIGHT;
	if (keycode == MOUSE_UP)
	{
		vars->itter += 2;
		vars->min_re = re_range + (vars->min_re - re_range) * 0.8;
		vars->min_im = im_range + (vars->min_im - im_range) * 0.8;
		vars->max_re = re_range + (vars->max_re - re_range) * 0.8;
		vars->max_im = im_range + (vars->max_im - im_range) * 0.8;
	}
	if (keycode == MOUSE_DOWN)
	{
		vars->min_re = re_range + (vars->min_re - re_range) * 1.2;
		vars->min_im = im_range + (vars->min_im - im_range) * 1.2;
		vars->max_re = re_range + (vars->max_re - re_range) * 1.2;
		vars->max_im = im_range + (vars->max_im - im_range) * 1.2;
		vars->itter -= 2;
	}
	remake (vars);
	return (0);
}

void	remake(t_vars *vars)
{
	mlx_destroy_image (vars->mlx, vars->img);
	vars->img = mlx_new_image (vars->mlx, WIDTH, HEIGHT);
	mlx_clear_window (vars->mlx, vars->win);
	if (vars->nb_fract == 0)
		make_julia (vars);
	else if (vars->nb_fract == 1)
		make_mandelbrot (vars);
	else if (vars->nb_fract == 2)
		make_bonus (vars);
	else if (vars->nb_fract == 3)
		make_bonus2 (vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
