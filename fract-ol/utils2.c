/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:56:56 by fcatteau          #+#    #+#             */
/*   Updated: 2023/03/14 12:31:12 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Includes/fractol.h"

void	floats_error(void)
{
	ft_putstr_fd ("please use floats as params for the fractal", 2);
	exit (1);
}

void	verif_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.' || !(str[i] >= '0' && str[i] <= '9' ))
			floats_error();
		i++;
	}
}

float	to_float(float nb, const char *str)
{
	int	power;
	int	i;

	power = -1;
	i = 0;
	if (!(str + 1))
		return ((float)nb);
	i++;
	verif_str ((char *)(str + i));
	while (str[i] && ft_isdigit (str[i]) == 1)
	{
		if (ft_isdigit (str[i]) == 0)
			floats_error();
		nb = nb + (float)(str[i] - '0')*pow(10, power);
		power --;
		i ++;
	}
	return (nb);
}

int	ft_atoi_verif(const char *str, size_t *i)
{
	int	neg;

	neg = 1;
	while (str[*i] != '\0' && (str[*i] == 32
			|| str[*i] == '\t' || str[*i] == '\n'
			|| str[*i] == '\r' || str[*i] == '\v' || str[*i] == '\f'))
	*i = *i + 1;
	if ((str[*i] != '\0' && str[*i] == '-')
		|| (str[*i] != '\0' && str[*i] == '+'))
	{
		if (str[*i] == '-')
			neg *= -1;
		*i = *i + 1;
	}
	return (neg);
}

float	ft_atoi_f(const char *str)
{
	size_t	i;
	int		neg;
	float	result;

	i = 0;
	result = 0;
	neg = ft_atoi_verif(str, &i);
	while (str[i])
	{
		if (ft_isdigit (str[i]) == 0)
			floats_error();
		if (str[i] != '.')
			result = result * 10 + str[i++] - '0';
		else
			break ;
	}
	if (str[i] == '.')
	{	
		result = to_float ((float)(result), str + i);
		return (result * neg);
	}
	return (result * neg);
}
