/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 15:41:35 by agoomany          #+#    #+#             */
/*   Updated: 2013/12/29 14:23:51 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include "ftminishell1.h"

void		ft_minishell_2(t_list *obj, char *prompt, char *cmd)
{
	char		**split_cmd;

	signal(SIGINT, ctrl_c);
	while (ft_putstr(prompt), get_next_line(0, &cmd))
	{
		signal(SIGINT, ctrl_c);
		split_cmd = NULL;
		split_cmd = ft_strsplit(cmd, ' ');
		if (test_internal(split_cmd[0]) == 1 && cmd[0] != '\0')
			obj = start_obj(verif_b_in_cmd(obj, split_cmd));
		else if (test_internal(split_cmd[0]) == 0 && cmd[0] != '\0')
			verif_ext_com(obj, split_cmd);
		free(prompt);
		prompt = NULL;
		prompt = ft_strnew(0);
		prompt = ft_strjoin(prompt, ft_prompt(obj));
	}
}

void		ft_minishell(char **environ, t_list *obj)
{
	int			i;
	char		*cmd;
	char		*prompt;

	i = 0;
	prompt = NULL;
	cmd = NULL;
	while (environ[i] != NULL)
	{
		if ((obj = fill_obj(obj, environ[i])) == NULL)
			return ;
		i++;
	}
	obj = start_obj(obj);
	prompt = ft_strnew(0);
	prompt = ft_strjoin(prompt, ft_prompt(obj));
	cmd = ft_strnew(0);
	ft_minishell_2(obj, prompt, cmd);
}

int			main(int ac, char **av, char **environ)
{
	t_list		*obj;

	obj = NULL;
	if (ac || av || !ac || !av)
		ft_minishell(environ, obj);
	return (0);
}

