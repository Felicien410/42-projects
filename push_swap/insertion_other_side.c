/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_other_side.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:07:09 by fcatteau          #+#    #+#             */
/*   Updated: 2023/03/23 13:03:30 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	act_if_value_on_top(long long tmp, t_stack **a, t_stack **b, int i)
{
	t_stack	*longuest;

	longuest = extrem (*b, 1);
	if (tmp == longuest->content)
		pa (a, b);
	else
	{
		pa (a, b);
		if (i == 1)
			put_down (longuest, b);
		else
			put_on_top (longuest, b);
		if (i == 1)
			rrb (b);
		pa (a, b);
		sa (a);
	}
}

t_stack	*up_actualise(t_stack **b, t_stack *tmp)
{
	rb (b);
	tmp = *b;
	return (tmp);
}

t_stack	*down_actualise(t_stack **b, t_stack *tmp)
{
	rrb (b);
	tmp = *b;
	return (tmp);
}

int	verif_other_side(t_stack **a, t_stack **b)
{
	if (ft_lstlen (*b) == 1)
	{
		pa (a, b);
		return (1);
	}
	if (ft_lstlen (*b) == 2)
	{
		if ((*b)->content > (*b)->next->content)
		{
			pa(a, b);
			pa(a, b);
		}
		else
		{
			sb(b);
			pa(a, b);
			pa(a, b);
		}
		return (1);
	}
	return (0);
}

void	other_side(t_stack **a, t_stack **b)
{
	t_stack	*longuest;
	t_stack	*pre_longuest;

	longuest = extrem (*b, 1);
	pre_longuest = next_extrem (*b, 1, longuest->content);
	while ((*b))
	{
		if (verif_other_side(a, b) == 1)
			return ;
		if (where_is_start ((*b), longuest->content) == 0)
		{
			while ((*b)->content != longuest->content
				&& (*b)->content != pre_longuest->content)
				(*b) = up_actualise (b, (*b));
			act_if_value_on_top ((*b)->content, a, b, 0);
		}
		else
		{
			while ((*b)->content != longuest->content
				&& (*b)->content != pre_longuest->content)
				(*b) = down_actualise (b, (*b));
			act_if_value_on_top ((*b)->content, a, b, 1);
		}
	pre_longuest = list_actualise(&longuest, b);
	}
}
