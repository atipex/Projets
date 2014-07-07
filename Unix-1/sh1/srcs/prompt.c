/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 16:54:53 by agoomany          #+#    #+#             */
/*   Updated: 2013/12/29 14:16:17 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftminishell1.h"

char		*ft_wd(t_list *obj)
{
	while (obj->next != NULL && ft_strcmp(obj->key_word, "PWD") != 0)
		obj = obj->next;
	if (obj->next == NULL && ft_strcmp(obj->key_word, "PWD") != 0)
		return ("");
	return (obj->value);
}

char		*check_wd(char *wd, t_list *obj)
{
	char	*swap;
	char	*ret;
	int		i;

	i = 0;
	ret = ft_strnew(0);
	while (obj->next != NULL && ft_strcmp(obj->key_word, "HOME") != 0)
		obj = obj->next;
	if (obj->next == NULL && ft_strcmp(obj->key_word, "HOME") != 0)
		return (wd);
	swap = ft_strnew(ft_strlen(obj->value));
	swap = ft_strcpy(swap, obj->value);
	i = (int) ft_strlen(swap);
	if (ft_strncmp(swap, wd, i) == 0)
	{
		wd += i;
		ret = ft_strjoin(ret, "~");
		ret = ft_strjoin(ret, wd);
		return (ret);
	}
	return (wd);
}

char		*ft_username(t_list *obj)
{
	while (obj->next != NULL && ft_strcmp(obj->key_word, "LOGNAME") != 0)
		obj = obj->next;
	if (obj->next == NULL && ft_strcmp(obj->key_word, "LOGNAME") != 0)
		return ("");
	return (obj->value);
}

char		*ft_prompt(t_list *obj)
{
	char	*username;
	char	*wd;
	char	*ret;

	username = ft_strnew(0);
	wd = ft_strnew(0);
	ret = ft_strnew(0);
	username = ft_strjoin(username, ft_username(obj));
	obj = start_obj(obj);
	wd = ft_strjoin(wd, ft_wd(obj));
	obj = start_obj(obj);
	wd = check_wd(wd, obj);
	obj = start_obj(obj);
	ret = ft_strjoin(ret, username);
	ret = ft_strjoin(ret, ":");
	ret = ft_strjoin(ret, wd);
	ret = ft_strjoin(ret, "$ ");
	return (ret);
}

