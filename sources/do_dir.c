/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 16:16:55 by afanneau          #+#    #+#             */
/*   Updated: 2017/05/18 17:45:15 by afanneau         ###   ########.fr       */
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
		return;
}

void	print_block(t_dir dir, t_ls ls)
{
	int		i;
	long	blck;

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

void	print_l(t_file file, t_dir dir)
{
	int		i;


//	ft_putnbr(dir.msize.ms_link);
	ft_putstr(file.perm);
	while (file.f_size.ms_link <= dir.msize.ms_link)
	{
		ft_putchar(' ');
		file.f_size.ms_link++;
	}
	ft_putnbr(file.nlink);
	ft_putchar(' ');
	ft_putstr(file.usr);
	while (file.f_size.ms_usr <= dir.msize.ms_usr + 1)
	{
		ft_putchar(' ');
		file.f_size.ms_usr++;
	}
	ft_putstr(file.grp);
	while (file.f_size.ms_grp <= dir.msize.ms_grp + 1)
	{
		ft_putchar(' ');
		file.f_size.ms_grp++;
	}
	if (file.blk == 1 || file.chr == 1)
		print_bc(file, dir);
	else
	{
		while (file.f_size.ms_blck < dir.msize.ms_blck)
		{
			ft_putchar(' ');
			file.f_size.ms_blck++;
		}
		ft_putnbr(file.size);
	}
	ft_putchar(' ');
	file.date = ctime(&file.time);
	if (file.date[23] != '7')
	{
		i = 20;
		file.date[10] = '\0';
		ft_putstr(file.date + 4);
		ft_putchar(' ');
		while (file.date[i] == ' ')
			i++;
		ft_putchar(' ');
		while (file.date[i] && file.date[i] != ' ' && file.date[i] != '\n')
		{
			ft_putchar(file.date[i]);
			i++;
		}
	}
	else
	{
		file.date[16] = '\0';
		ft_putstr(file.date + 4);
	}
	ft_putchar(' ');
	ft_putstr(file.name);
	file.link == 1 ? ft_putstr(" -> ") : 0;
	file.link == 1 ? ft_putendl(file.link_to) : ft_putchar('\n');
}

void	check_size(t_file *file, t_msize *msize)
{
	while (file->nlink / ft_pow(10, file->f_size.ms_link) >= 1)
		file->f_size.ms_link++;
	file->f_size.ms_usr = ft_strlen(file->usr);
	file->f_size.ms_grp = ft_strlen(file->grp);
	while (file->size / ft_pow(10, file->f_size.ms_blck) >= 1)
				file->f_size.ms_blck++;
	file->size == 0 ? file->f_size.ms_blck++ : 0;
	while (file->maj_nb / ft_pow(10, file->f_size.ms_majn) >= 1)
		file->f_size.ms_majn++;
	while (file->min_nb / ft_pow(10, file->f_size.ms_minn) >= 1)
		file->f_size.ms_minn++;
	if (file->f_size.ms_link > msize->ms_link)
		msize->ms_link = file->f_size.ms_link;
	if (file->f_size.ms_usr > msize->ms_usr)
		msize->ms_usr = file->f_size.ms_usr;
	if (file->f_size.ms_grp > msize->ms_grp)
		msize->ms_grp = file->f_size.ms_grp;
	if (msize->ms_majn < file->f_size.ms_majn)
		msize->ms_majn = file->f_size.ms_majn;
	if (msize->ms_minn < file->f_size.ms_minn)
		msize->ms_minn = file->f_size.ms_minn;
	if (file->f_size.ms_blck > msize->ms_blck)
		msize->ms_blck = file->f_size.ms_blck;
	if (file->f_size.ms_majn + file->f_size.ms_minn + 2 > msize->ms_blck && (file->blk == 1 || file->chr == 1))
		msize->ms_blck = file->f_size.ms_majn + file->f_size.ms_minn + 2;
}

void	print(t_dir dir, t_ls ls)
{
	int		i;

	i = 0;
	while (i < dir.nb_files)
	{
		if (ls.flag.a == 0 && dir.files[i].hidden == 1);
		else
			ls.flag.l == 1 ? check_size(&dir.files[i], &dir.msize) : 0;
		i++;
	}
	i = 0;
	while (i < dir.nb_files)
	{
		if (ls.flag.a == 0 && dir.files[i].hidden == 0)
			ls.flag.l == 1 ? print_l(dir.files[i], dir) : ft_putendl(dir.files[i].name);
		else if (ls.flag.a == 1)
			ls.flag.l == 1 ? print_l(dir.files[i], dir) : ft_putendl(dir.files[i].name);
		i++;
	}
}

void	recur(t_dir dir, t_ls ls)
{
	int		i;

	i = 0;
	while (i < dir.nb_files && ls.flag.R == 1)
	{
		if (ft_strcmp(dir.files[i].name, ".") != 0 && ft_strcmp(dir.files[i].name, "..") != 0)
		{
			if (dir.files[i].dir == 1 && ((ls.flag.a == 0 && dir.files[i].hidden == 0) || (ls.flag.a == 1)))
			{
				ft_putchar('\n');
			}
			if (ls.flag.a == 0 && dir.files[i].hidden == 0 && dir.files[i].dir == 1)
				do_dir(dir.files[i].path, ls, 1);
			else if (ls.flag.a == 1 && dir.files[i].dir == 1)
				do_dir(dir.files[i].path, ls, 1);
		}
		i++;
	}
}

int		do_dir(char *name, t_ls ls, int printable)
{
	t_dir	dir;
	int		i;

	i = 0;
	if (create_dir_struct(name, &dir, ls) == 1)
		return (0);
	if (printable)
	{
		ft_putstr(name);		
		ft_putendl(":");
	}
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
