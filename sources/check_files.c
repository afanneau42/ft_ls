/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 16:09:44 by afanneau          #+#    #+#             */
/*   Updated: 2017/06/02 16:10:18 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	add_file(char *name, t_dir *dir, t_ls ls)
{
	set_info_to_zero(&dir->files[dir->nb_files]);
	set_info_l_to_zero(&dir->files[dir->nb_files]);
	dir->files[dir->nb_files].name = ft_strdup(name);
	get_file_info(0, &dir->files[dir->nb_files], ls);
	dir->nb_files++;
}

void	check_files_2(t_ls ls, char *argv, t_stat buf, t_args *args)
{
	if (ls.flag.l == 1)
		add_file(argv, &args->arg_file, ls);
	else
	{
		stat(argv, &buf);
		if (S_ISDIR(buf.st_mode))
			add_file(argv, &args->arg_dir, ls);
		else
			add_file(argv, &args->arg_file, ls);
	}
}

void	check_files_3(int error, char *argv, t_args *args)
{
	args->arg_error.files[args->arg_error.nb_files].name = ft_strdup(argv);
	args->arg_error.files[args->arg_error.nb_files].nlink = error;
	args->arg_error.nb_files++;
}

void	check_files(t_ls ls, char ***argv, t_args *args)
{
	int		i;
	DIR		*fd;
	int		error;
	t_stat	buf;

	i = ls.first_dir;
	while (argv[0][i] && argv[0][i][0])
	{
		errno = 0;
		fd = opendir(argv[0][i]);
		error = errno;
		lstat(argv[0][i], &buf);
		if (S_ISLNK(buf.st_mode))
			check_files_2(ls, argv[0][i], buf, args);
		else if (error != ENOTDIR && error != 0)
			check_files_3(error, argv[0][i], args);
		else if (error == ENOTDIR)
			add_file(argv[0][i], &args->arg_file, ls);
		else
		{
			add_file(argv[0][i], &args->arg_dir, ls);
			error == 0 ? closedir(fd) : 0;
		}
		i++;
	}
}
