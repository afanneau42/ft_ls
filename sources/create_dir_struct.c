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

void	info_link(t_file *file)
{
	size_t	size;
//	char	*tmp;

	file->link_to = ft_strnew(1000);
	size = readlink(file->path, file->link_to, 1000);
/*	while (size % 1000 == 0)
	{
		tmp = ft_strnew(size + 1000);
		ft_strcpy(tmp, file->link_to);
		free(file->link_to);
		file->link_to = tmp;
		file->link_to = ft_strnew(size + 1000);
		size = readlink(file->path, file->link_to, size + 1000);
		free(tmp);
	}*/
	file->link = 1;
}


char	*create_path(char *dir_name, char *file_name)
{
	char	*path;

	path = ft_strnew(ft_strlen(dir_name) + ft_strlen(file_name) + 1);
	ft_strcat(path, dir_name);
	path[ft_strlen(dir_name)] = '/';
	ft_strcat(path, file_name);
	return (path);
}

void	get_file_info(char *name, t_file *file, t_ls ls)
{
	t_stat	buf;

	if (name)
		file->path = create_path(name, file->name);
	else
		file->path = ft_strdup(file->name);
	set_info_to_zero(file);
	lstat(file->path, &buf);
	if (S_ISLNK(buf.st_mode))
		info_link(file);
	else
	{
		stat(file->path, &buf);
		if (S_ISDIR(buf.st_mode))
			file->dir = 1;
	}
	if (S_ISCHR(buf.st_mode))
		file->chr = 1;
	else if (S_ISBLK(buf.st_mode))
		file->blk = 1;
	else if (S_ISFIFO(buf.st_mode))
		file->fifo = 1;
	else if (S_ISSOCK(buf.st_mode))
		file->sock = 1;
	if (file->name[0] == '.')
		file->hidden = 1;
	file->time = buf.st_mtimespec.tv_sec;
	if (ls.flag.l == 1)
		l_flag_info(file, ls, buf);
}

void	fill_files(char *name, t_dir *dir, t_ls ls)
{
	int			i;
	DIR			*fd_dir;
	t_dirent	*dirrent;

	i = 0;
	fd_dir = opendir(name);
	while (i < dir->nb_files)
	{
		dirrent = readdir(fd_dir);
		dir->files[i].name = ft_strdup(dirrent->d_name);
		get_file_info(name, &dir->files[i], ls);
		i++;
	}
	closedir(fd_dir);
	dir->msize.ms_link = 0;
	dir->msize.ms_usr = 0;
	dir->msize.ms_grp = 0;
	dir->msize.ms_blck = 0;
	dir->msize.ms_date = 0;
	dir->msize.ms_majn = 0;
	dir->msize.ms_minn = 0;
}

int	create_dir_struct(char *name, t_dir *dir, t_ls ls)
{
	DIR			*fd_dir;
	t_dirent	*dirrent;
	int			error;

	fd_dir = opendir(name);
	error = errno;
	if (fd_dir == NULL)
	{
		if (errno != ENOTDIR)
		{
			//ft_putstr(name);
			//ft_putendl(":");
			ft_putstr_fd("ft_ls : ", 2);
			ft_putendl_fd(strerror(error), 2);
		}
		return (1);
	}
	dir->nb_files = 0;
	dirrent = readdir(fd_dir);
	while (dirrent != NULL)
	{
		dirrent = readdir(fd_dir);
		dir->nb_files++;
	}
	dir->files = malloc(sizeof(t_file) * dir->nb_files);
	fill_files(name, dir, ls);
	closedir(fd_dir);
	if (ls.flag.r)
		return (0);
	return (0);
}
