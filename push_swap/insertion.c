/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:07:09 by fcatteau          #+#    #+#             */
/*   Updated: 2023/03/22 19:26:58 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_insertion(t_stack **a, t_stack **b)
{
	t_stack		*to_sort;
	t_stack		*small;
	t_stack		*big;
	long long	chunk;
	int			nb_chunks;

	if (!*a)
		return ;
	to_sort = (*a)->next;
	if (ft_lstlen (*a) == 2)
		two_params (a);
	small = extrem (to_sort, 0);
	big = extrem (to_sort, 1);
	nb_chunks = how_many_chunck(to_sort);
	chunk = small->content
		+ (big->content - small->content) / nb_chunks;
	if (ft_lstlen (*a) > 5 && ft_lstlen (*a) < 100)
	{
		ft_sorting(a, b, chunk, nb_chunks);
	}
	if (ft_lstlen (*a) >= 100)
		ft_sorting(a, b, chunk, nb_chunks);
	other_side (a, b);
}
