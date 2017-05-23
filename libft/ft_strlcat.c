/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:15:34 by afanneau          #+#    #+#             */
/*   Updated: 2016/11/11 19:49:05 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		lendst;

	lendst = ft_strlen(dst);
	if (size <= lendst)
		return (size + ft_strlen(src));
	ft_strncat(dst, src, size - ft_strlen(dst) - 1);
	return (lendst + ft_strlen(src));
}
