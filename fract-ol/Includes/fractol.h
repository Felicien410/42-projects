/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:03:22 by fcatteau          #+#    #+#             */
/*   Updated: 2023/03/14 12:27:29 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include<stdlib.h>
# include<stdio.h>
# include<string.h>
# include<unistd.h>
# include<mlx.h>
# include"buttons.h"
# include<math.h>

typedef struct cor
{
	float	corx;
	float	cory;
}	t_cor;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		*addr;
	void	*img;
	int		bits_per_pixel;
	int		endian;
	int		line_length;
	double	cr;
	double	ci;
	double	max_re;
	double	max_im;
	double	min_re;
	double	min_im;
	int		itter;
	int		nb_fract;
	int		color;
	t_cor	zoom;
}	t_vars;

void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_strcmp(char	*s1, char	*s2);
int		error(void);
void	mlx_begin(t_vars *vars);
void	my_mlx_pixel_put(t_vars *data, int x, int y, int color);
int		key_press(int keycode, t_vars *vars);
void	remake(t_vars *vars);
int		mouse(int keycode, int x, int y, t_vars *fractol);
void	configuration_for_julia(t_vars *vars, char *argv1, char *argv2);
void	make_julia(t_vars *fractol);
int		nb_itterations_julia(double x, double y, double max_iters, t_vars *fra);
int		nb_itterations_m(double x, double y, double max_iters);
void	make_mandelbrot(t_vars *fractol);
void	configuration_for_mandelbrot(t_vars *data);
void	configuration_for_bonus(t_vars *data);
void	make_bonus(t_vars *fractol);
int		nb_itterations_bonus(double x, double y, double max_iters, t_vars *fra);
int		nb_itterations_bonus2(double x, double y, double maxiters, t_vars *fra);
void	make_bonus2(t_vars *fractol);
void	configuration_for_bonus2(t_vars *data);
float	ft_atoi_f(const char *str);
int		ft_isdigit(int c);
float	to_float(float nb, const char *str);
void	set_fractal_config(t_vars *vars, char *f_type, char *p1, char *p2);
void	run_fractal(t_vars *vars);
void	floats_error(void);
void	verif_str(char *str);
int		ft_atoi_verif(const char *str, size_t *i);

#endif