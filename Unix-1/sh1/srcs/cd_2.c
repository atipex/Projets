/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 00:00:05 by agoomany          #+#    #+#             */
/*   Updated: 2013/12/29 14:20:34 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ftminishell1.h"

char		*check_tilde(char *cmd, t_list *obj)
{
	char		*ret;
	int			len;

	len = (ft_strlen(cmd)) - 1;
	ret = ft_strnew(0);
	if (cmd[0] == '~')
	{
		while (obj->next != NULL)
		{
			if (ft_strcmp(obj->key_word, "HOME") == 0)
			{
				ret = ft_strjoin(ret, obj->value);
				ret = ft_strjoin(ret, ft_strsub(cmd, 1, len));
				return (ret);
			}
			obj = obj->next;
		}
		if (obj->next == NULL && (ft_strcmp(obj->key_word, cmd) == 0))
		{
			ret = ft_strjoin(ret, obj->value);
			ret = ft_strjoin(ret, ft_strsub(cmd, 1, len));
			return (ret);
		}
	}
	return (cmd);
}

char		*pure_wd(char *direc)
{
	int		len;
	char	*ret;

	len = 0;
	if (ft_strncmp(direc, "/Volumes/DATA", 13) == 0)
	{
		len = ft_strlen(direc);
		len = len - 13;
		ret = ft_strnew(0);
		ret = ft_strjoin(ret, ft_strsub(direc, 13, len));
		return (ret);
	}
	return (direc);
}

t_list		*ft_cd_reverse(t_list *obj)
{
	char		*swap;
	char		*swap2;

	obj = search_in_obj(start_obj(obj), "PWD");
	swap = ft_strnew(0);
	swap = ft_strjoin(swap, obj->value);
	obj = search_in_obj(start_obj(obj), "OLDPWD");
	swap2 = ft_strnew(0);
	swap2 = ft_strjoin(swap2, obj->value);
	obj->value = swap;
	obj = search_in_obj(start_obj(obj), "PWD");
	obj->value = swap2;
	chdir(swap2);
	return (obj);
}
