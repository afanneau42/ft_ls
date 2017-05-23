/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 16:25:29 by afanneau          #+#    #+#             */
/*   Updated: 2016/11/12 16:42:19 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *s)
{
	char		*tmp;
	int			i;
	size_t		j;

	j = 0;
	if (!s)
		return (0);
	i = ft_strlen(s);
	tmp = ft_strnew(i);
	i--;
	while (i >= 0)
	{
		tmp[i] = s[j];
		i--;
		j++;
	}
	s = tmp;
	return (s);
}
