/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:07:09 by fcatteau          #+#    #+#             */
/*   Updated: 2023/03/22 19:43:05 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstlast_ps(t_stack *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (0);
}

int	verif_sort(t_stack *to_sort)
{	
	while (to_sort && to_sort->next)
	{
		if (to_sort->content > to_sort->next->content)
		{
			return (0);
		}
		to_sort = to_sort->next;
	}
	return (1);
}

int	how_many_chunck(t_stack *to_sort)
{
	int	len;

	len = ft_lstlen (to_sort);
	if (len < 100)
		return (7);
	if (len >= 100)
		return (11);
	return (0);
}

t_stack	*extrem(t_stack *to_sort, int i)
{
	t_stack	*small;

	if (to_sort == NULL || to_sort->next == NULL)
		return (to_sort);
	small = to_sort;
	while (to_sort)
	{
		if (cmp (to_sort->content, small->content) == i)
			small = to_sort;
		to_sort = to_sort->next;
	}
	return (small);
}

t_stack	*next_extrem(t_stack *to_sort, int i, long long val)
{
	t_stack	*small;

	if (to_sort == NULL || to_sort->next == NULL)
		return (to_sort);
	small = to_sort;
	while (to_sort)
	{
		if (cmp(to_sort->content, small->content) == i
			&& to_sort->content < val)
		{
			small = to_sort;
		}
		to_sort = to_sort->next;
	}
	return (small);
}
