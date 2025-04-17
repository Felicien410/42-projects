/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:55:37 by fcatteau          #+#    #+#             */
/*   Updated: 2023/03/15 11:33:54 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Includes/fractol.h"

int	nb_itterations_julia(double x, double y, double max_iters, t_vars *fra)
{
	double	tmp;
	int		i;

	i = 0;
	while (i <= max_iters && (x * x + y * y) <= 4)
	{
		tmp = x;
		x = x * x - y * y - fra->zoom.corx;
		y = 2 * y * tmp - fra->zoom.cory;
		i++;
	}
	return (i);
}

void	make_julia(t_vars *vars)
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
			i = nb_itterations_julia (vars->cr, vars->ci, vars->itter, vars);
			if (i == 0 || i > vars->itter)
				vars->addr[(y * WIDTH) + x] = 0x000000;
			else
				vars->addr[(y * HEIGHT + x)] = vars->color * i;
			y++;
		}
		x++;
	}
}

void	configuration_for_julia(t_vars *vars, char *argv1, char *argv2)
{
	vars->nb_fract = 0;
	vars->zoom.corx = ft_atoi_f(argv1);
	vars->zoom.cory = ft_atoi_f(argv2);
	vars->min_re = -2;
	vars->min_im = -2;
	vars->max_re = 2;
	vars->max_im = 2;
	vars->itter = 250;
	vars->color = 0xFFD700;
	mlx_begin(vars);
	make_julia(vars);
}
