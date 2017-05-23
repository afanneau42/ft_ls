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
	ls.flag.t == 1 ? sort_argv_time(argv, ls) : 0;
}

int		main(int argc, char **argv)
{
	t_ls	ls;
	int		i;
	int		k;

	if (argc == 0)
		return (0);
	init(&ls);
	check_params(argv, &ls);
	ls.first_dir < argc ? sort_argv(&argv, ls) : 0;
	//print_file_arg();
	i = ls.first_dir;
	if (ls.flag.r == 1)
		i = argc - 1;
	k = i;
	if (ls.first_dir == argc || ls.first_dir + 1 == argc)
		argv[ls.first_dir] ? do_dir(argv[ls.first_dir], ls, 0) : do_dir(".", ls, 0);
	else
	{
		while (argv[k] && k >= ls.first_dir)
		{
			opendir(argv[k]);
			if (errno == ENOTDIR)
				ft_putendl(argv[k]);
			k += 1 - ls.flag.r * 2;
		}
		while (argv[i] && i >= ls.first_dir)
		{
			ft_putstr(argv[i]);
			ft_putendl(":");
			if (do_dir(argv[i], ls, 0))
			{
				if (argv[i + 1 - ls.flag.r * 2] && i + 1 - ls.flag.r * 2 >= ls.first_dir)
					ft_putchar('\n');
			}
			else if (errno == ENOTDIR)
				ft_putendl(argv[i]);
			i += 1 - ls.flag.r * 2;
		}
	}
//	while(1){};
	return (0);
}

/*

-l, -R, -a, -r et -t.

*/
