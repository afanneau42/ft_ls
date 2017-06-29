/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 13:41:11 by afanneau          #+#    #+#             */
/*   Updated: 2017/06/05 17:51:20 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_swap_t(t_file *f1, t_file *f2)
{
	t_file tmp;

	tmp = *f1;
	*f1 = *f2;
	*f2 = tmp;
}

void	sort_rev(t_dir *dir)
{
	int		i;

	i = 0;
	if (dir->nb_files == 2)
	{
		ft_swap_t(&dir->files[0], &dir->files[1]);
		return ;
	}
	else
	{
		while (i < dir->nb_files / 2)
		{
			ft_swap_t(&dir->files[i], &dir->files[dir->nb_files - i - 1]);
			i++;
		}
	}
}

void	sort_time(t_dir *dir)
{
	int		i;

	i = 1;
	while (i < dir->nb_files)
	{
		if (dir->files[i].time > dir->files[i - 1].time)
		{
			while (i >= 1 && dir->files[i].time > dir->files[i - 1].time)
			{
				ft_swap_t(&dir->files[i - 1], &dir->files[i]);
				i--;
			}
			if (i == 0)
				i++;
		}
		else
			i++;
	}
}

void	sort_norm(t_dir *dir)
{
	int		i;

	i = 1;
	while (i < dir->nb_files)
	{
		if (ft_strcmp(dir->files[i - 1].name, dir->files[i].name) > 0)
		{
			while (i >= 1 && ft_strcmp(dir->files[i - 1].name,
				dir->files[i].name) > 0)
			{
				ft_swap_t(&dir->files[i - 1], &dir->files[i]);
				i--;
			}
			if (i == 0)
				i++;
		}
		else
			i++;
	}
}

void	sort_files(t_dir *dir, t_ls ls)
{
	sort_norm(dir);
	if (ls.rand == 0)
	{
		ls.flag.t == 1 ? sort_time(dir) : 0;
		ls.flag.r == 1 ? sort_rev(dir) : 0;
	}
}
