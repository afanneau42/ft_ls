/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:17:19 by afanneau          #+#    #+#             */
/*   Updated: 2016/11/10 16:40:32 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *big, const char *little)
{
	int			i;
	size_t		lenght;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	lenght = ft_strlen(little);
	while (big[i])
	{
		if (ft_strncmp(big + i, little, lenght) == 0)
			return ((char *)big + i);
		i++;
	}
	return (0);
}
