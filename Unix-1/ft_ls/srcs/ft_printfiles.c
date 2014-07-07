/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 11:44:22 by mrebours            #+#    #+#             */
/*   Updated: 2014/04/19 11:46:51 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <pwd.h>
#include <stdlib.h>
#include <grp.h>
#include "ft_ls.h"

static void			ft_printmode(mode_t m)
{
	if (S_ISDIR(m))
		ft_putchar('d');
	else if (S_ISREG(m))
		ft_putchar('-');
	else if (S_ISBLK(m))
		ft_putchar('b');
	else if (S_ISCHR(m))
		ft_putchar('c');
	else if (S_ISFIFO(m))
		ft_putchar('p');
	else if (S_ISLNK(m))
		ft_putchar('l');
	else if (S_ISSOCK(m))
		ft_putchar('s');
}

static void			ft_printperm(mode_t m)
{
	char			perm[10];

	perm[0] = (S_IRUSR & m ? 'r' : '-');
	perm[1] = (S_IWUSR & m ? 'w' : '-');
	perm[2] = (S_IXUSR & m ? 'x' : '-');
	perm[3] = (S_IRGRP & m ? 'r' : '-');
	perm[4] = (S_IWGRP & m ? 'w' : '-');
	perm[5] = (S_IWGRP & m ? 'x' : '-');
	perm[6] = (S_IROTH & m ? 'r' : '-');
	perm[7] = (S_IWOTH & m ? 'w' : '-');
	perm[8] = (S_IXOTH & m ? 'x' : '-');
	perm[9] = '\0';
	if (S_ISUID & m)
		perm[2] = (perm[2] == 'x' ? 's' : 'S');
	if (S_ISGID & m)
		perm[5] = (perm[5] == 'x' ? 's' : 'S');
	if (S_ISVTX & m)
		perm[8] = (perm[8] == 'x' ? 't' : 'T');
	ft_putstr(perm);
	ft_putstr("  ");
}

static void			ft_printid(struct stat *file)
{
	struct passwd	*upwd;
	struct group	*gpwd;

	upwd = malloc(sizeof(struct passwd));
	gpwd = malloc(sizeof(struct group));
	upwd = getpwuid(file->st_uid);
	gpwd = getgrgid(file->st_gid);
	ft_putstr(upwd->pw_name);
	ft_putstr("  ");
	ft_putstr(gpwd->gr_name);
	ft_putstr("  ");
}

void				ft_printfiles(t_list *file, t_option *opt)
{
	if ((opt->r == '1') && (file->next))
		ft_printfiles(file->next, opt);
	while (file)
	{
		if (file->content
			&& !S_ISDIR(((t_data *)(file->content))->stat->st_mode))
		{
			if (opt->l == '1')
				ft_printl(((t_data *)(file->content)));
			else
				ft_putendl(((t_data *)(file->content))->path);
		}
		if (opt->r == '1')
			return ;
		file = file->next;
	}
}

void				ft_printl(t_data *data)
{
	ft_printmode(data->stat->st_mode);
	ft_printperm(data->stat->st_mode);
	ft_putnbr(data->stat->st_nlink);
	ft_putstr("  ");
	ft_printid(data->stat);
	ft_putendl(data->path);
	return ;
}
