/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:56:47 by fcatteau          #+#    #+#             */
/*   Updated: 2023/03/14 10:58:42 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Includes/fractol.h"

int	nb_itterations_m(double x, double y, double max_iters)
{
	int		i;
	double	new_r;
	double	old_r;
	double	new_i;
	double	old_i;

	new_r = 0;
	old_r = 0;
	new_i = 0;
	old_r = 0;
	i = 0;
	while ((new_r * new_r + new_i * new_i) < 4.0 && i < max_iters)
	{
		old_r = new_r;
		old_i = new_i;
		new_r = old_r * old_r - old_i * old_i + x;
		new_i = 2.0 * old_r * old_i + y;
		++i;
	}
	return (i);
}

void	make_mandelbrot(t_vars *vars)
{
	int		x;
	int		y;
	int		i;

	x = 0;
	i = 0;
	while (x < WIDTH)
	{
		vars->cr = vars->min_re + (vars->max_re - vars->min_re) * x / WIDTH;
		y = 0;
		while (y < HEIGHT)
		{
			vars->ci = vars->min_im + (vars->max_im - vars->min_im)
				* y / WIDTH;
			i = nb_itterations_m(vars->cr, vars->ci, vars->itter);
			if (i == 0 || i > 250)
				vars->addr[(y * WIDTH) + x] = 0x000000;
			else
				vars->addr[(y * HEIGHT + x)] = vars->color * i;
			y++;
		}
		x++;
	}
}

void	configuration_for_mandelbrot(t_vars *vars)
{
	vars->nb_fract = 1;
	vars->zoom.corx = 0.8;
	vars->zoom.cory = 0.1;
	vars->min_re = -2;
	vars->min_im = -2;
	vars->max_re = 2;
	vars->max_im = 2;
	vars->itter = 250;
	vars->color = 0xE6E6FA;
	mlx_begin(vars);
	make_mandelbrot(vars);
}
