/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:50:30 by afanneau          #+#    #+#             */
/*   Updated: 2016/11/12 16:21:16 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*r;
	t_list		*tmp;

	if (lst == NULL)
		return (NULL);
	if ((r = f(lst)) == NULL)
		return (NULL);
	tmp = f(lst);
	r = tmp;
	while (lst->next != NULL)
	{
		lst = lst->next;
		tmp->next = f(lst);
		tmp = tmp->next;
	}
	tmp->next = NULL;
	return (r);
}
