/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 12:27:46 by afanneau          #+#    #+#             */
/*   Updated: 2016/11/08 14:48:15 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned int	r;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	r = (unsigned char)s1[i] - ((unsigned char)s2[i]);
	return (r);
}
