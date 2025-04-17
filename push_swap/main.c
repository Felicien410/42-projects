/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:13:45 by fcatteau          #+#    #+#             */
/*   Updated: 2023/03/23 16:02:56 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	few_params(t_stack **a, t_stack **b)
{
	if (ft_lstlen (*a) == 2)
		two_params (a);
	if (ft_lstlen (*a) == 3)
		three_params (a);
	if (ft_lstlen (*a) == 4)
		sort_four_elements(a, b);
	if (ft_lstlen (*a) == 5)
		sort_five_elements(a, b);
	freelist(*a);
	exit(1);
}

void	if_sorted(t_stack **a)
{
	freelist (*a);
	exit (1);
}

int	main(int argc, char **argv)
{
	size_t	i;
	t_stack	*a;
	t_stack	*b;

	i = 1;
	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		while (argv[i])
		{
			if (ft_count_words(argv[i], ' ') == 1)
				add_to_list(&a, ft_atoi_ps(argv[i], &a));
			else if (ft_count_words(argv[i], ' ') > 1)
				split_and_replace(argv[i], &a);
			i++;
		}
		if (verif_sort (a) == 1)
			if_sorted(&a);
		if (ft_lstlen (a) <= 5)
			few_params(&a, &b);
		ft_insertion(&a, &b);
		printf("liste a after \n\n");
		ft_print_list(a);
		printf("liste b after \n\n");
		ft_print_list(b);
		freelist(a);
	}
	return (0);
}
