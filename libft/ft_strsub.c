/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:38:16 by afanneau          #+#    #+#             */
/*   Updated: 2016/11/12 15:11:46 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*r;
	int			i;

	i = 0;
	if (((r = ft_strnew(len)) != NULL) && s)
	{
		while (i < len)
		{
			r[i] = s[start];
			i++;
			start++;
		}
		return (r);
	}
	return (0);
}
