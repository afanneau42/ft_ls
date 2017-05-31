/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 16:01:40 by afanneau          #+#    #+#             */
/*   Updated: 2017/05/18 17:27:00 by afanneau         ###   ########.fr       */
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

void	check_files(t_ls ls, char ***argv, t_args *args)
{
	int		i;
	DIR 	*fd;
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
		{
			if (ls.flag.l == 1)
				add_file(argv[0][i], &args->arg_file, ls);
			else
			{
				stat(argv[0][i], &buf);
				if (S_ISDIR(buf.st_mode))
					add_file(argv[0][i], &args->arg_dir, ls);
				else
					add_file(argv[0][i], &args->arg_file, ls);
			}
		}
		else if (error != ENOTDIR && error != 0)
		{
				ft_putnbr(error);
				args->arg_error.files[args->arg_error.nb_files].name = ft_strdup(argv[0][i]);
				args->arg_error.files[args->arg_error.nb_files].nlink = error;
				args->arg_error.nb_files++;
		}
		else
		{
			if (error == ENOTDIR)
				add_file(argv[0][i], &args->arg_file, ls);
			else
			{
				add_file(argv[0][i], &args->arg_dir, ls);
				error == 0 ? closedir(fd) : 0;
			}
		}
		i++;
	}
}

void	usage(char option)
{
	ft_putstr_fd("ft_ls : illegal option -- ", 2);
	ft_putchar_fd(option, 2);
	ft_putendl_fd("\nusage : ft_ls [-Ralrt1] [file ...]", 2);
	exit(1);
}

void	check_flag(char *str, t_flag *flag)
{
	int		i;

	i = 1;
	while (str[i] && (str[i] == 'l' || str[i] == 'R' || str[i] == 'a' || str[i] == 'r' || str[i] == 't' || str[i] == '1'))
	{
		if (str[i] == '1' && flag->l == 1)
			flag->l--;
		if (str[i] == 'l')
			flag->l = 1;
		if (str[i] == 'R')
			flag->R = 1;
		if (str[i] == 'a')
			flag->a = 1;
		if (str[i] == 'r')
			flag->r = 1;
		if (str[i] == 't')
			flag->t = 1;
		i++;
	}
	if (str[i] != '\0')
		usage(str[i]);
}

void	check_input(char **argv, int argc)
{
	int		i;

	i = 0;
	while (argv[i] && argv[i][0])
		i++;
	if (argc != i)
	{
		ft_putendl_fd("ft_ls: fts_open: No such file or directory", 2);
		exit(1);
	}
}

void	check_params(char ***argv, t_ls *ls, t_args *args, int argc)
{
	int		i;

	i = 1;
	while (argv[0][i] && argv[0][i][0] == '-' && argv[0][i][1] != '\0')
	{
		if (argv[0][i][1] && argv[0][i][1] == '-' && !argv[0][i][2])
			break;
		check_flag(argv[0][i], &ls->flag);
		i++;
	}
	ls->first_dir = i;
	if (argv[0][i] && argv[0][i][0] && argv[0][i][1] && argv[0][i][0] == '-' && argv[0][i][1] == '-' && argv[0][i][2] == '\0')
		ls->first_dir++;
	check_input(*argv, argc);
	check_files(*ls, argv, args);
}
