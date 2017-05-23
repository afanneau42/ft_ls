/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:59:24 by afanneau          #+#    #+#             */
/*   Updated: 2016/11/08 15:18:11 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	int			i;
	size_t		lenght;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	lenght = ft_strlen(little);
	while (big[i] && i + lenght <= len)
	{
		if (ft_strncmp(big + i, little, lenght) == 0)
			return ((char *)big + i);
		i++;
	}
	return (0);
}
