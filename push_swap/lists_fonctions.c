/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_fonctions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:07:09 by fcatteau          #+#    #+#             */
/*   Updated: 2023/03/23 13:37:39 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freelist(t_stack *stack)
{
	t_stack	*tmp;

	tmp = NULL;
	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = NULL;
		stack = tmp;
	}
}

int	ft_lstlen(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		if (lst->next == NULL)
			return (i);
		lst = lst->next;
	}
	return (i);
}

t_stack	*list_actualise(t_stack **longuest, t_stack **b)
{
	t_stack	*pre_longuest;

	*longuest = extrem (*b, 1);
	pre_longuest = next_extrem (*b, 1, (*longuest)->content);
	return (pre_longuest);
}

void	where_is_best(t_stack **a, t_stack *first)
{
	if (where_is_start(*a, first->content) == 0)
		ra(a);
	else
		rra(a);
}

void	help_five(t_stack **a)
{
	rra (a);
	sa (a);
}
