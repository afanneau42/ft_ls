/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 15:54:15 by afanneau          #+#    #+#             */
/*   Updated: 2017/05/18 17:37:05 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include "../libft/libft.h"
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/xattr.h>
#include <sys/stat.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <grp.h>
#include <sys/acl.h>
#include <time.h>
#include <errno.h>
#include <string.h>

#define MINORBITS       20
#define MINORMASK       ((1U << MINORBITS) - 1)
#define MAJOR(dev)      ((unsigned int) ((dev) >> MINORBITS))
#define MINOR(dev)      ((unsigned int) ((dev) & MINORMASK))

typedef struct	dirent	t_dirent;
typedef struct	stat	t_stat;
typedef struct	passwd	t_passwd;
typedef struct	group		t_group;

typedef struct		s_msize
{
	int				ms_link;
	int				ms_usr;
	int				ms_grp;
	int				ms_blck;
	int				ms_date;
	int				ms_majn;
	int				ms_minn;
}					t_msize;

typedef struct		s_flag
{
	int				l;
	int				R;
	int				a;
	int				r;
	int				t;
}					t_flag;

typedef struct		s_ls
{
	t_flag			flag;
	int				first_dir;

}					t_ls;


typedef	struct		s_file
{
	char			*name;
	char			*path;

	int				dir;
	int				link;
	int				chr;
	int				blk;
	int				sock;
	int				fifo;

	int				hidden;
	time_t			time;

	char			*link_to;

	int				maj_nb;
	int				min_nb;
	char			perm[12];
	int				nlink;
	char			*usr;
	char			*grp;
	long			size;
	char			*date;
	long			n_blck;

	t_msize			f_size;
}					t_file;

typedef struct		s_dir
{
	char			*name;
	t_file			*files;
	int				nb_files;
	t_msize			msize;
}					t_dir;

typedef	struct		s_args
{
	t_dir			arg_file;
	t_dir			arg_dir;
}					t_args;
/*
**					INITIALISATION
*/
void				init(t_ls *ls, t_args *args, int argc);
void				set_info_to_zero(t_file *file);
void				set_info_l_to_zero(t_file *file);
void				msize_to_zero(t_msize *s);

void				check_params(char ***argv, t_ls *ls, t_args *args);
int					do_dir(char *name, t_ls ls, int printable);
void				print(t_dir dir, t_ls ls);
void				print_l(t_file file, t_dir dir);
int					create_dir_struct(char *name, t_dir *dir, t_ls ls);
void				fill_files(char *name, t_dir *dir, t_ls);

void				get_file_info(char *namefile, t_file *file, t_ls ls);
void				l_flag_info(t_file *file, t_ls ls, t_stat buf);
void				sort_files(t_dir *dir, t_ls ls);

void				err(void);
#endif
