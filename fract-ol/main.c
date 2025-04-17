/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:55:53 by fcatteau          #+#    #+#             */
/*   Updated: 2023/03/14 12:27:19 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Includes/fractol.h"

void	mlx_begin(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "FRACTALL PTNNN");
	vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->addr = (int *)
		mlx_get_data_addr(vars->img, &vars->bits_per_pixel, &vars->line_length,
			&vars->endian);
}

int	exit_close(void)
{
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc == 2)
	{
		set_fractal_config(&vars, argv[1], "0.2", "0.8");
	}
	else if (argc == 4)
	{
		if (ft_strcmp(argv[2], ".") == 0 || ft_strcmp(argv[3], ".") == 0)
		{
			ft_putstr_fd ("please use floats as params for the fractal", 2);
			exit (1);
		}
		set_fractal_config(&vars, argv[1], argv[2], argv[3]);
	}
	else
		error();
	run_fractal(&vars);
}

void	set_fractal_config(t_vars *vars, char *f_type, char *p1, char *p2)
{
	if (ft_strcmp(f_type, "Julia") == 0)
		configuration_for_julia(vars, p1, p2);
	else if (ft_strcmp(f_type, "Mandelbrot") == 0)
		configuration_for_mandelbrot(vars);
	else if (ft_strcmp(f_type, "Simplegroove") == 0)
		configuration_for_bonus(vars);
	else if (ft_strcmp(f_type, "Brain") == 0)
		configuration_for_bonus2(vars);
	else
		error();
}

void	run_fractal(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	mlx_hook(vars->win, 2, 0, key_press, vars);
	mlx_hook(vars->win, 4, 0, &mouse, vars);
	mlx_hook(vars->win, 17, 0, exit_close, vars);
	mlx_loop(vars->mlx);
}
