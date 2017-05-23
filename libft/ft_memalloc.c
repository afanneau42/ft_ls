/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:51:55 by afanneau          #+#    #+#             */
/*   Updated: 2016/11/21 15:09:09 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	int			i;
	void		*str;

	i = 0;
	if ((str = (void*)malloc(sizeof(char) * size)) != NULL)
	{
		while (i < size)
		{
			((char *)str)[i] = '\0';
			i++;
		}
		return (str);
	}
	return (0);
}
