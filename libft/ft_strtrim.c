/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:54:42 by afanneau          #+#    #+#             */
/*   Updated: 2016/11/11 14:21:46 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char		*r;
	long int	i;
	long int	j;

	j = 0;
	i = 0;
	if (s)
	{
		j = ft_strlen(s) - 1;
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
			j--;
		j++;
		if (j > i)
			r = ft_strsub(s, i, j - i);
		else
		{
			if ((r = ft_strnew(0)) == NULL)
				return (0);
		}
		return (r);
	}
	return (0);
}
