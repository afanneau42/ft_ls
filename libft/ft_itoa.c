/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:38:41 by afanneau          #+#    #+#             */
/*   Updated: 2016/11/11 14:33:06 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_itoa(int n)
{
	int		i;

	i = 0;
	if (n < 0)
		i++;
	while (n > 9 || n < -9)
	{
		n /= 10;
		i++;
	}
	i++;
	return (i);
}

char		*ft_itoa(int n)
{
	char		*r;
	int			i;
	int			sign;

	sign = 1;
	i = ft_count_itoa(n);
	if ((r = malloc(i + 1)) == NULL)
		return (NULL);
	r[i] = '\0';
	if (n < 0)
		sign = -1;
	while (n > 9 || n < -9)
	{
		i--;
		r[i] = (n % 10 * sign) + '0';
		n /= 10;
	}
	i--;
	r[i] = n * sign + '0';
	if (sign == -1)
		r[0] = '-';
	return (r);
}
