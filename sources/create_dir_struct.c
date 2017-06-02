/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 16:51:00 by afanneau          #+#    #+#             */
/*   Updated: 2017/05/18 17:40:47 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	path_to_name(char *name)
{
	int	i;

	i = ft_strlen(name);
	while (i > 0 && name[i] != '/')
		i--;
	ft_putstr_fd(name + i + 1, 2);
}

void	create_dir_struct_2(t_dir *dir, DIR *fd_dir)
{
	t_dirent	*dirrent;

	dir->nb_files = 0;
	dirrent = readdir(fd_dir);
	while (dirrent != NULL)
	{
		dirrent = readdir(fd_dir);
		dir->nb_files++;
	}
	dir->files = malloc(sizeof(t_file) * dir->nb_files);
}

int		create_dir_struct(char *name, t_dir *dir, t_ls ls)
{
	DIR			*fd_dir;
	int			error;

	fd_dir = opendir(name);
	error = errno;
	if (fd_dir == NULL)
	{
		if (errno != ENOTDIR)
		{
			ft_putstr_fd("ft_ls: ", 2);
			path_to_name(name);
			ft_putstr_fd(": ", 2);
			ft_putendl_fd(strerror(error), 2);
		}
		return (1);
	}
	create_dir_struct_2(dir, fd_dir);
	fill_files(name, dir, ls);
	closedir(fd_dir);
	return (0);
}
