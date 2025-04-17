/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:07:09 by fcatteau          #+#    #+#             */
/*   Updated: 2023/03/23 14:42:11 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_put_error(t_stack **a)
{
	ft_putstr_fd("Error\n", 2);
	if (ft_lstlen (*a) >= 1)
		freelist(*a);
	exit(1);
}

long long	help_atoi(const char *str, int i, long long result, t_stack **a)
{
	if (ft_isdigit (str[i]) == 1)
	{
		result = result * 10 + str[i] - '0';
		i ++;
	}
	else
		ft_put_error(a);
	return (result);
}

long long	ft_atoi_ps(const char *str, t_stack **a)
{
	int			i;
	int			neg;
	long long	result;

	i = 0;
	neg = 1;
	result = 0;
	while (str[i] != '\0' && (str[i] == 32 || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] != '\0' && str[i] == '-')
	{
		neg *= -1;
		i ++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		result = help_atoi(str, i, result, a);
		i++;
	}
	return (result * neg);
}

t_stack	*split_and_replace(char *str, t_stack **a)
{
	char		**tab;
	size_t		i;
	long long	content;

	i = 0;
	tab = ft_split(str, ' ');
	while (tab[i])
	{
		content = ft_atoi_ps(tab[i], a);
		add_to_list(a, content);
		i++;
	}
	return (*a);
}
