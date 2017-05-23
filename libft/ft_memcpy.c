/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:44:31 by afanneau          #+#    #+#             */
/*   Updated: 2016/11/05 16:06:00 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*tab1;
	unsigned char		*tab2;

	tab1 = src;
	tab2 = dst;
	i = 0;
	while (i < n)
	{
		tab2[i] = tab1[i];
		i++;
	}
	return (dst);
}
