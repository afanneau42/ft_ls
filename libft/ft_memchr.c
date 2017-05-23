/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 18:10:13 by afanneau          #+#    #+#             */
/*   Updated: 2016/11/12 15:05:35 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*tab1;

	tab1 = s;
	i = 0;
	while (i < n)
	{
		if (tab1[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (0);
}
