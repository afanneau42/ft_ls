/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 16:51:00 by afanneau          #+#    #+#             */
/*   Updated: 2017/05/17 16:55:45 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	fill_perm_str(t_stat buf, t_file *file)
{
	buf.st_mode & S_IRUSR ? file->perm[1] = 'r' : 0;
	buf.st_mode & S_IWUSR ? file->perm[2] = 'w' : 0;
	buf.st_mode & S_IXUSR ? file->perm[3] = 'x' : 0;
	buf.st_mode & S_IRGRP ? file->perm[4] = 'r' : 0;
	buf.st_mode & S_IWGRP ? file->perm[5] = 'w' : 0;
	buf.st_mode & S_IXGRP ? file->perm[6] = 'x' : 0;
	buf.st_mode & S_IROTH ? file->perm[7] = 'r' : 0;
	buf.st_mode & S_IWOTH ? file->perm[8] = 'w' : 0;
	buf.st_mode & S_IXOTH ? file->perm[9] = 'x' : 0;
}

void	fill_perm_str_extended(t_stat buf, t_file *file)
{
	if (buf.st_mode & S_ISUID)
	{
		if (ft_strncmp(file->perm + 1, "---", 3) == 0)
			file->perm[3] = 'S';
		else
			file->perm[3] = 's';
	}
	if (buf.st_mode & S_ISGID)
	{
		if (ft_strncmp(file->perm + 4, "---", 3) == 0)
			file->perm[6] = 'S';
		else
			file->perm[6] = 's';
	}
	if (buf.st_mode & S_ISVTX)
	{
		if (ft_strncmp(file->perm + 7, "---", 3) == 0)
			file->perm[9] = 'T';
		else
			file->perm[9] = 't';
	}
}

void	perm(t_stat buf, t_file *file)
{
	acl_t	tmp;

	tmp = 0;
	if (file->dir == 1)
		file->perm[0] = 'd';
	else if (file->link == 1)
		file->perm[0] = 'l';
	else if (file->chr == 1)
		file->perm[0] = 'c';
	else if (file->blk == 1)
		file->perm[0] = 'b';
	else if (file->sock == 1)
		file->perm[0] = 's';
	else if (file->fifo == 1)
		file->perm[0] = 'p';
	fill_perm_str(buf, file);
	fill_perm_str_extended(buf, file);
}

void	dir_fail(t_file *file)
{
	file->dir_fail = 1;
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(file->name, 2);
	ft_putendl_fd(": No such file or directory", 2);
}

void	l_flag_info(t_file *file, t_stat buf)
{
	t_passwd	*pas;
	t_group		*grp;

	set_info_l_to_zero(file);
	perm(buf, file);
	file->nlink = buf.st_nlink;
	pas = getpwuid(buf.st_uid);
	if (pas == NULL)
		return (dir_fail(file));
	file->usr = pas->pw_name;
	grp = getgrgid(buf.st_gid);
	file->grp = grp->gr_name;
	file->size = (long)buf.st_size;
	file->n_blck = buf.st_blocks;
	if (file->blk == 1 || file->chr == 1)
	{
		file->maj_nb = major(buf.st_rdev);
		file->min_nb = minor(buf.st_rdev);
	}
}
