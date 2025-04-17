/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertions_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:07:09 by fcatteau          #+#    #+#             */
/*   Updated: 2023/03/21 19:20:29 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cmp(long long first, long long second)
{
	if (first > second)
		return (1);
	else
		return (0);
}

int	verif_if_any_chunk(t_stack **a, long long chunk)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		if ((tmp)->content < chunk)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	where_is_start(t_stack *b, long long to_find)
{
	size_t	len_list;
	size_t	i;
	t_stack	*tmp;

	tmp = b;
	len_list = ft_lstlen(tmp);
	i = 0;
	while (i < (len_list / 2) && tmp)
	{
		if (tmp->content == to_find && tmp)
		{
			return (0);
		}
		i++;
		tmp = tmp->next;
	}
	return (1);
}

void	put_on_top(t_stack *longuest, t_stack **b)
{
	while ((*b)->content != longuest->content)
	{
		rb (b);
	}
}

void	put_down(t_stack *longuest, t_stack **b)
{
	while (ft_lstlast_ps (*b)->content != longuest->content)
	{
		rrb (b);
	}
}
