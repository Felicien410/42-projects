/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_one_side.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:07:09 by fcatteau          #+#    #+#             */
/*   Updated: 2023/03/23 16:02:09 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	where_the_next_nb_for_chunk(t_stack **a, long long chunk_t)
{
	t_stack		*last;
	t_stack		*first;
	long long	iter_last;
	long long	iter_min;

	iter_last = 0;
	iter_min = 0;
	last = ft_lstlast_ps (*a);
	first = *a;
	while (first->content > chunk_t && first->next)
	{
		first = first->next;
		iter_min++;
	}
	while (last->content > chunk_t && last->prec)
	{
		last = last->prec;
		iter_last++;
	}
	if (iter_min >= iter_last)
	{
		return (1);
	}
	else
		return (2);
}

void	ft_sorting(t_stack **a, t_stack **b, long long chunk, int nb_chunks)
{
	long long	chunk_total;

	chunk_total = chunk;
	while (nb_chunks)
	{
		while (*a)
		{
			if (nb_chunks == 1)
				chunk_total = extrem (*a, 1)->content;
			if ((*a)->content > chunk_total)
			{
				if (verif_if_any_chunk (a, chunk_total) == 0)
					break ;
				if (where_the_next_nb_for_chunk (a, chunk_total) == 0)
					help_ft_sorting(a, 0, chunk_total);
				else
					help_ft_sorting(a, 1, chunk_total);
				pb (a, b);
			}
			else
				pb(a, b);
		}
		chunk_total = chunk_total + chunk;
		nb_chunks--;
	}
}

void	help_ft_sorting(t_stack **a, int i, long long chunk_total)
{
	if (i == 0)
	{
		while ((*a)->content > chunk_total)
			ra (a);
		return ;
	}
	else
	{
		while ((*a)->content > chunk_total)
			rra(a);
		return ;
	}
}
