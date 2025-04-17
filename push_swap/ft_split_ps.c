/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_ps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:02:34 by fcatteau          #+#    #+#             */
/*   Updated: 2023/03/22 17:03:22 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	*ft_freearray(char **s, long long i)
{
	while (i-- > 0)
	{
		free(s[i]);
	}
	free(s);
	return (NULL);
}

long long	ft_len_split(const char *s, char c)
{
	unsigned int		i;
	long long			lenght;

	i = 0;
	lenght = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i++])
		lenght++;
	return (lenght);
}

long long	ft_count_words(const char *str, char c)
{
	unsigned int		i;
	long long			t;

	i = 0;
	t = 0;
	while (str[i])
	{
		if (str[i] != c)
			t++;
		while (str[i] != c && str[i + 1])
			i++;
		i++;
	}
	return (t);
}

long long	ft_count(char const *s, char c, long long t)
{
	while (s[t] == c)
		t++;
	return (t);
}

char	**ft_split_ps(char const *s, char c)
{
	long long	i;
	size_t		j;
	size_t		t;
	char		**tab;

	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	i = -1;
	t = 0;
	while (++i < ft_count_words(s, c))
	{
		tab[i] = (char *) malloc(sizeof(char) * (ft_len_split(s + t, c) + 1));
		if (!tab[i])
			return (ft_freearray(tab, i));
		j = 0;
		t = ft_count(s, c, t);
		while (s[t] != c && s[t])
			tab[i][j++] = s[t++];
		tab[i][j] = '\0';
	}
	tab[i] = NULL;
	return (tab);
}
