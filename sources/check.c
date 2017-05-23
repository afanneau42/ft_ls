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

void	usage(char option)
{
	ft_putstr_fd("ft_ls : illegal option -- ", 2);
	ft_putchar_fd(option, 2);
	ft_putendl_fd("\nusage : ft_ls [-1lRart] [file ...]", 2);
	exit(1);
}

void	check_flag(char *str, t_flag *flag)
{
	int		i;

	i = 1;
	while (str[i] && (str[i] == 'l' || str[i] == 'R' || str[i] == 'a' || str[i] == 'r' || str[i] == 't' || str[i] == '1'))
	{
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

void	check_params(char **argv, t_ls *ls)
{
	int		i;

	i = 1;
	while (argv[i] && argv[i][0] == '-' && argv[i][1] != '\0')
	{
		if (argv[i][1] && argv[i][1] == '-' && !argv[i][2])
			break;
		check_flag(argv[i], &ls->flag);
		i++;
	}
	ls->first_dir = i;
	if (argv[i] && argv[i][0] && argv[i][1] && argv[i][0] == '-' && argv[i][1] == '-' && argv[i][2] == '\0')
		ls->first_dir++;
}
