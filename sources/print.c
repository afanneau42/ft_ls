/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 17:46:27 by afanneau          #+#    #+#             */
/*   Updated: 2017/06/02 17:46:43 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	check_maxsize(t_file *file, t_msize *msize)
{
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
	if (file->f_size.ms_majn + file->f_size.ms_minn + 2 >
			msize->ms_blck && (file->blk == 1 || file->chr == 1))
		msize->ms_blck = file->f_size.ms_majn + file->f_size.ms_minn + 2;
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
	check_maxsize(file, msize);
}

void	print(t_dir dir, t_ls ls)
{
	int		i;

	i = 0;
	while (i < dir.nb_files)
	{
		if (!(ls.flag.a == 0 && dir.files[i].hidden == 1))
			ls.flag.l == 1 ? check_size(&dir.files[i], &dir.msize) : 0;
		i++;
	}
	i = 0;
	while (i < dir.nb_files)
	{
		if (ls.flag.a == 0 && dir.files[i].hidden == 0)
			ls.flag.l == 1 ? print_l(dir.files[i], dir) :
				ft_putendl(dir.files[i].name);
		else if (ls.flag.a == 1)
			ls.flag.l == 1 ? print_l(dir.files[i], dir) :
				ft_putendl(dir.files[i].name);
		i++;
	}
}
