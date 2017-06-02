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

void	do_params(t_args *args, int argc, t_ls ls)
{
	int		i;

	i = 0;
	if (ls.first_dir == argc)
		do_dir(".", ls, 0);
	ls.rand = 1;
	sort_files(&args->arg_error, ls);
	ls.rand = 0;
	sort_files(&args->arg_file, ls);
	sort_files(&args->arg_dir, ls);
	while (i < args->arg_error.nb_files)
	{
		ft_putstr_fd("ft_ls: ", 2);
		ft_putstr_fd(args->arg_error.files[i].name, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(args->arg_error.files[i].nlink), 2);
		i++;
	}
	print(args->arg_file, ls);
}

void	do_dir_params(t_args *args, int argc, t_ls ls)
{
	int		i;

	i = 0;
	if (args->arg_dir.nb_files > 0 && args->arg_file.nb_files > 0)
		ft_putchar('\n');
	while (i < args->arg_dir.nb_files)
	{
		if (argc - ls.first_dir != 1)
			do_dir(args->arg_dir.files[i].name, ls, 1);
		else
			do_dir(args->arg_dir.files[i].name, ls, 0);
		if (i + 1 < args->arg_dir.nb_files)
			ft_putchar('\n');
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_ls	ls;
	t_args	args;

	if (argc == 0)
		return (0);
	init(&ls, &args, argc);
	check_params(&argv, &ls, &args, argc);
	do_params(&args, argc, ls);
	do_dir_params(&args, argc, ls);
	return (0);
}
