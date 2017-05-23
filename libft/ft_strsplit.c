/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:21:15 by afanneau          #+#    #+#             */
/*   Updated: 2016/11/12 16:09:48 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char const *str, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[j] != '\0')
	{
		while (str[j] != '\0' && str[j] == c)
			j++;
		if (str[j] != '\0')
			i++;
		while (str[j] != '\0' && str[j] != c)
			j++;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		n;

	i = 0;
	j = 0;
	n = 0;
	if (s == 0)
		return (0);
	if ((tab = (char**)malloc(sizeof(*tab) * ft_countwords(s, c) + 1)) == 0)
		return (0);
	while (s[i] != '\0' && s[n] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		n = i;
		while (s[n] != '\0' && s[n] != c)
			n++;
		tab[j] = ft_strsub(s, i, n - i);
		j++;
		i = n;
	}
	tab[ft_countwords(s, c)] = NULL;
	return (tab);
}
