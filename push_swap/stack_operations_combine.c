/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_combine.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:17:23 by fcatteau          #+#    #+#             */
/*   Updated: 2023/03/21 17:35:07 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack **a, t_stack **b)
{
	t_stack		*elem1;
	t_stack		*elem2;
	long long	tmp;

	if (ft_lstlen(*a) < 2 || ft_lstlen(*b) < 2)
		return ;
	elem1 = *a;
	elem2 = elem1->next;
	tmp = elem1->content;
	elem1->content = elem2->content;
	elem2->content = tmp;
	elem1 = *b;
	elem2 = elem1->next;
	tmp = elem1->content;
	elem1->content = elem2->content;
	elem2->content = tmp;
	ft_putstr_fd ("ss\n", 1);
}

void	rr(t_stack **a, t_stack **b)
{
	t_stack	*elem1;
	t_stack	*tmp;

	if (!*a || !*b)
		return ;
	elem1 = *a;
	*a = (*a)->next;
	tmp = *a;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = elem1;
	elem1->next = NULL;
	elem1 = *b;
	*b = (*b)->next;
	tmp = *b;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = elem1;
	elem1->next = NULL;
	ft_putstr_fd ("rr\n", 1);
}

void	rrr(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*bflast;

	if (ft_lstlen(*a) <= 1 || ft_lstlen(*b) <= 1)
		return ;
	tmp = *a;
	while (tmp && tmp->next)
	{
		bflast = tmp;
		tmp = tmp->next;
	}
	bflast->next = NULL;
	tmp->next = *a;
	*a = tmp;
	while (tmp && tmp->next)
	{
		bflast = tmp;
		tmp = tmp->next;
	}
	bflast->next = NULL;
	tmp->next = *b;
	*b = tmp;
	ft_putstr_fd ("rrr\n", 1);
}
