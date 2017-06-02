/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 17:44:53 by afanneau          #+#    #+#             */
/*   Updated: 2017/06/02 17:44:55 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_bc(t_file file, t_dir dir)
{
	while (file.f_size.ms_majn < dir.msize.ms_majn)
	{
		ft_putchar(' ');
		file.f_size.ms_majn++;
	}
	file.maj_nb != 0 ? ft_putchar(' ') : 0;
	ft_putnbr(file.maj_nb);
	ft_putstr(",");
	while (file.f_size.ms_minn < dir.msize.ms_minn)
	{
		ft_putchar(' ');
		file.f_size.ms_minn++;
	}
	file.min_nb != 0 ? ft_putchar(' ') : 0;
	ft_putnbr(file.min_nb);
	if (file.dir == 1)
		return ;
}

void	print_block(t_dir dir, t_ls ls)
{
	int		i;
	long	blck;

	if (dir.nb_files == 2 && ls.flag.a == 0)
		return ;
	i = 0;
	blck = 0;
	while (i < dir.nb_files)
	{
		if ((ls.flag.a == 0 && dir.files[i].name[0] != '.') || ls.flag.a == 1)
			blck += dir.files[i].n_blck;
		i++;
	}
	ft_putstr("total ");
	ft_putnbr(blck);
	ft_putchar('\n');
}

void	print_l_3(t_file *file)
{
	int		i;

	i = 20;
	file->date = ctime(&file->time);
	if (file->time <= time(NULL) - 31536000 / 2 || file->time > time(NULL))
	{
		file->date[10] = '\0';
		ft_putstr(file->date + 4);
		ft_putchar(' ');
		while (file->date[i] == ' ')
			i++;
		ft_putchar(' ');
		while (file->date[i] && file->date[i] != ' ' && file->date[i] != '\n')
		{
			ft_putchar(file->date[i]);
			i++;
		}
	}
	else
	{
		file->date[16] = '\0';
		ft_putstr(file->date + 4);
	}
}

void	print_l_2(t_file *file, t_dir *dir)
{
	while (file->f_size.ms_usr <= dir->msize.ms_usr + 1)
	{
		ft_putchar(' ');
		file->f_size.ms_usr++;
	}
	ft_putstr(file->grp);
	while (file->f_size.ms_grp <= dir->msize.ms_grp + 1)
	{
		ft_putchar(' ');
		file->f_size.ms_grp++;
	}
	if (file->blk == 1 || file->chr == 1)
		print_bc(*file, *dir);
	else
	{
		while (file->f_size.ms_blck < dir->msize.ms_blck)
		{
			ft_putchar(' ');
			file->f_size.ms_blck++;
		}
		ft_putnbr(file->size);
	}
	ft_putchar(' ');
}

void	print_l(t_file file, t_dir dir)
{
	ft_putstr(file.perm);
	while (file.f_size.ms_link <= dir.msize.ms_link)
	{
		ft_putchar(' ');
		file.f_size.ms_link++;
	}
	ft_putnbr(file.nlink);
	ft_putchar(' ');
	ft_putstr(file.usr);
	print_l_2(&file, &dir);
	print_l_3(&file);
	ft_putchar(' ');
	ft_putstr(file.name);
	file.link == 1 ? ft_putstr(" -> ") : 0;
	file.link == 1 ? ft_putendl(file.link_to) : ft_putchar('\n');
}
