/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:05:19 by afanneau          #+#    #+#             */
/*   Updated: 2016/11/07 15:14:41 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char		c1;
	int			i;

	i = ft_strlen(s);
	c1 = c;
	while (s[i] != c1 && i > 0)
		i--;
	if (s[i] == c1)
		return ((char *)s + i);
	return (0);
}
