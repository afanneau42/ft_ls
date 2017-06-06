/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 16:16:55 by afanneau          #+#    #+#             */
/*   Updated: 2017/06/06 14:38:14 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	recur(t_dir dir, t_ls ls)
{
	int		i;

	i = 0;
	while (i < dir.nb_files && ls.flag.rec == 1)
	{
		if (ft_strcmp(dir.files[i].name, ".") != 0 &&
			ft_strcmp(dir.files[i].name, "..") != 0)
		{
			if (dir.files[i].dir == 1 && ((ls.flag.a == 0 &&
				dir.files[i].hidden == 0) || (ls.flag.a == 1)))
			{
				ft_putchar('\n');
			}
			if (ls.flag.a == 0 && dir.files[i].hidden == 0
				&& dir.files[i].dir == 1)
				do_dir(dir.files[i].path, ls, 1);
			else if (ls.flag.a == 1 && dir.files[i].dir == 1)
				do_dir(dir.files[i].path, ls, 1);
		}
		i++;
	}
}

void	print_name(char *name)
{
	if (name[0] && name[1] && name[0] == '/' && name[1] == '/')
		ft_putstr(name + 1);
	else
		ft_putstr(name);
	ft_putendl(":");
}
int		do_dir(char *name, t_ls ls, int printable)
{
	t_dir	dir;
	int		i;

	i = 0;
	if (printable)
		print_name(name);
	if (create_dir_struct(name, &dir, ls) == 1)
		return (0);
	sort_files(&dir, ls);
	if (ls.flag.l == 1)
		print_block(dir, ls);
	print(dir, ls);
	recur(dir, ls);
	while (i < dir.nb_files)
	{
		free(dir.files[i].name);
		free(dir.files[i].path);
		dir.files[i].link == 1 ? free(dir.files[i].link_to) : 0;
		i++;
	}
	free(dir.files);
	return (1);
}
