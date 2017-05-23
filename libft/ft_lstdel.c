/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 16:27:26 by afanneau          #+#    #+#             */
/*   Updated: 2016/11/11 17:28:14 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*tmp;
	t_list		*second;

	second = (*alst)->next;
	tmp = second;
	while (second != NULL)
	{
		tmp = second->next;
		ft_lstdelone(&second, del);
		second = tmp;
	}
	ft_lstdelone(alst, del);
}
