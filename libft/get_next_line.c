/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 15:15:31 by afanneau          #+#    #+#             */
/*   Updated: 2017/01/06 14:58:13 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	realloc_str(t_gnl *gnl)
{
	char	*tmp;

	tmp = ft_strnew(gnl->lenght + BUFF_SIZE);
	tmp = ft_strcpy(tmp, gnl->str);
	tmp[gnl->lenght + BUFF_SIZE] = '\0';
	gnl->eol = tmp + (gnl->eol - gnl->str);
	free(gnl->str);
	gnl->str = tmp;
	gnl->lenght += BUFF_SIZE;
}

void	init_struct(t_gnl **gnl)
{
	*gnl = malloc(sizeof(t_gnl));
	(*gnl)->lenght = BUFF_SIZE;
	(*gnl)->str = malloc(((*gnl)->lenght + 1) * sizeof(char));
	(*gnl)->str[(*gnl)->lenght] = '\0';
	(*gnl)->eol = (*gnl)->str;
	(*gnl)->ret = 1;
	(*gnl)->char_lu = 0;
}

int		is_newline(t_gnl *gnl)
{
	while (gnl->eol - gnl->str < gnl->char_lu && *(gnl->eol) != '\n')
		gnl->eol++;
	if (*(gnl->eol) == '\n' && gnl->char_lu > gnl->eol - gnl->str)
		return (1);
	return (0);
}

int		return_line(t_gnl **ptr_gnl, t_gnl *gnl, char **line)
{
	if (gnl->ret < 0)
		return (-1);
	*line = ft_strsub(gnl->str, 0, gnl->eol - gnl->str);
	if (gnl->ret <= 0 && gnl->char_lu <= 0)
	{
		if (gnl->str)
			free(gnl->str);
		free(gnl);
		*ptr_gnl = NULL;
		return (0);
	}
	gnl->char_lu += gnl->str - gnl->eol
		- (*(gnl->eol) == '\n' && gnl->ret > 0
			&& gnl->char_lu != gnl->eol - gnl->str);
	ft_memcpy(gnl->str, gnl->eol + 1, gnl->char_lu);
	gnl->eol = gnl->str;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*gnl[4096];

	if (!line || BUFF_SIZE <= 0 || fd < 0 || fd > 4096)
		return (-1);
	if (!gnl[fd])
		init_struct(&gnl[fd]);
	if (gnl[fd]->ret == 0)
		return (0);
	if (gnl[fd]->ret == -1)
		return (-1);
	while (gnl[fd]->ret > 0 && is_newline(gnl[fd]) == 0)
	{
		while (gnl[fd]->lenght < gnl[fd]->char_lu + BUFF_SIZE)
			realloc_str(gnl[fd]);
		gnl[fd]->ret = read(fd, gnl[fd]->str + gnl[fd]->char_lu, BUFF_SIZE);
		gnl[fd]->char_lu += gnl[fd]->ret;
	}
	return (return_line(&gnl[fd], gnl[fd], line));
}
