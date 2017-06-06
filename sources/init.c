/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 16:51:00 by afanneau          #+#    #+#             */
/*   Updated: 2017/05/17 16:55:43 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	msize_to_zero(t_msize *s)
{
	s->ms_link = 0;
	s->ms_usr = 0;
	s->ms_grp = 0;
	s->ms_blck = 0;
	s->ms_date = 0;
	s->ms_majn = 0;
	s->ms_minn = 0;
}

void	set_info_l_to_zero(t_file *file)
{
	int		i;

	i = 0;
	while (i < 10)
	{
		file->perm[i] = '-';
		i++;
	}
	file->perm[10] = ' ';
	file->perm[11] = '\0';
	file->nlink = 0;
	file->size = 0;
	file->n_blck = 0;
}

void	set_info_to_zero(t_file *file)
{
	file->dir = 0;
	file->link = 0;
	file->chr = 0;
	file->blk = 0;
	file->fifo = 0;
	file->sock = 0;
	file->hidden = 0;
	file->time = 0;
	file->dir_fail = 0;
	msize_to_zero(&file->f_size);
}

void	init(t_ls *ls, t_args *args, int argc)
{
	ls->flag.l = 0;
	ls->flag.rec = 0;
	ls->flag.a = 0;
	ls->flag.r = 0;
	ls->flag.t = 0;
	ls->rand = 0;
	ls->first_dir = 0;
	args->arg_file.nb_files = 0;
	args->arg_dir.nb_files = 0;
	args->arg_error.nb_files = 0;
	args->arg_file.files = malloc(sizeof(t_file) * argc);
	args->arg_dir.files = malloc(sizeof(t_file) * argc);
	args->arg_error.files = malloc(sizeof(t_file) * argc);
	msize_to_zero(&args->arg_file.msize);
	msize_to_zero(&args->arg_file.msize);
}
