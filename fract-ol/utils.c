/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:56:56 by fcatteau          #+#    #+#             */
/*   Updated: 2023/03/14 17:40:15 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Includes/fractol.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write (fd, &s[i], 1);
			i++;
		}
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(n *= -1, fd);
	}
	else if (n < 10)
	{
		ft_putchar_fd('0' + n, fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}

int	ft_strcmp(char	*s1, char	*s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
			i ++;
	}
	return (0);
}

int	error(void)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("you have to put the fractal you want\n", 2);
	ft_putstr_fd("Exemple: ./fractol Julia\n\n", 2);
	ft_putstr_fd("or with 4 params \nExemple : ./fractol Julia 0.8 0.5\n\n", 2);
	ft_putstr_fd("You can choose one of this ones :\n", 2);
	ft_putstr_fd("Julia\nMandelbrot\nSimplegroove\nBrain", 2);
	exit(1);
}
