/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 15:51:01 by afanneau          #+#    #+#             */
/*   Updated: 2017/05/18 17:38:26 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

/*int		if_file(char *namefile, t_ls ls)
{
	t_file	file;
	t_dir	dir;

	msize_to_zero(&dir.msize);
	errno = 0;
	opendir(namefile);
	if (errno != ENOTDIR)
		return (0);
	{
		if (ls.flag.l == 1)
		{
			set_info_to_zero(&file);
			set_info_l_to_zero(&file);
			file.name = ft_strdup(namefile);
			get_file_info(0, &file, ls);
			print_l(file, dir);
		}
		else
			ft_putendl(namefile);
	}
	return (1);
}*/

void	sort_argv_time(char ***argv, t_ls ls)
{
	int		i;
	int		time1;
	int		time2;
	t_stat	buf;
	char	*tmp;

	i = ls.first_dir;
	while (argv[0][i + 1])
	{
		lstat(argv[0][i], &buf);
		time1 = buf.st_mtimespec.tv_sec;
		lstat(argv[0][i + 1], &buf);
		time2 = buf.st_mtimespec.tv_sec;
		if (time1 < time2)
		{
			tmp = argv[0][i];
			argv[0][i] = argv[0][i + 1];
			argv[0][i + 1] = tmp;
			i = ls.first_dir;
		}
		else
			i++;
	}
}

void	sort_argv(char ***argv, t_ls ls)
{
	int		i;
	char	*tmp;

	i = ls.first_dir;
	while (argv[0][i + 1])
	{
		if (ft_strcmp(argv[0][i], argv[0][i + 1]) > 0)
		{
			tmp = argv[0][i];
			argv[0][i] = argv[0][i + 1];
			argv[0][i + 1] = tmp;
			i = ls.first_dir;
		}
		else
			i++;
	}
//	ls.flag.t == 1 ? sort_argv_time(argv, ls) : 0;
}

int		main(int argc, char **argv)
{
	t_ls	ls;
	int		i;
//	int		k;
	t_args	args;

	if (argc == 0)
		return (0);
	init(&ls, &args, argc);
//	sort_argv(&argv, ls);
	check_params(&argv, &ls, &args, argc);
	i = 0;
	if (ls.first_dir == argc)
		do_dir(".", ls, 0);
	ls.rand = 1;
	sort_files(&args.arg_error, ls);
	ls.rand = 0;
	sort_files(&args.arg_file, ls);
	sort_files(&args.arg_dir, ls);
	i = 0;
	while (i < args.arg_error.nb_files)
	{
		ft_putstr_fd("ft_ls: ", 2);
		ft_putstr_fd(args.arg_error.files[i].name, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(args.arg_error.files[i].nlink), 2);
		i++;
	}
	print(args.arg_file, ls);
	if (args.arg_dir.nb_files > 0 && args.arg_file.nb_files > 0)
		ft_putchar('\n');
	i = 0;
	while (i < args.arg_dir.nb_files)
	{
		if (argc - ls.first_dir != 1)
			do_dir(args.arg_dir.files[i].name, ls, 1);
		else
			do_dir(args.arg_dir.files[i].name, ls, 0);
		if (i + 1 < args.arg_dir.nb_files)
			ft_putchar('\n');
		i++;
	}
	/*ls.first_dir < argc ? sort_argv(&argv, ls) : 0;
	i = ls.first_dir;
	if (ls.flag.r == 1)
		i = argc - 1;
	k = i;
	if (ls.first_dir == argc || ls.first_dir + 1 == argc)
		if (argv[ls.first_dir])
			if_file(argv[ls.first_dir], ls) ? 0 : do_dir(argv[ls.first_dir], ls, 0);
		else
			do_dir(".", ls, 0);
	else
	{
		while (argv[k] && k >= ls.first_dir)
		{
			if (argv[k][0] != '\0')
			{
				errno = 0;
				opendir(argv[k]);
				if (errno == ENOTDIR)
				{
					bol = 1;
					ls.flag.l == 1 ? if_file(argv[k], ls) : ft_putendl(argv[k]);
					argv[k][0] = '\0';
				}
			}
			k += 1 - ls.flag.r * 2;
		}
		while (argv[i] && i >= ls.first_dir)
		{
			if (argv[i][0] != '\0')
			{
				if (bol == 1)
				{
					ft_putchar('\n');
					bol = 0;
				}
				ft_putstr(argv[i]);
				ft_putendl(":");
				if (do_dir(argv[i], ls, 0))
					bol = 1;
			}
			i += 1 - ls.flag.r * 2;
		}
	}*/
	return (0);
}

/*

-l, -R, -a, -r et -t.

*/
