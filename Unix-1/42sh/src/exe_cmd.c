#include <stdlib.h>
#include "lib.h"
#include "42sh.h"

t_builtin	builtin[] =
{
	{"history", ft_history},
	{"set", ft_set},
	{"unset", ft_unset},
	{"setenv", ft_setenv},
	{"unsetenv", ft_unsetenv},
	{"env", ft_env},
	{"echo", ft_echo},
	{"exit", ft_exit},
	{"cd", ft_cd},
	{"alias", ft_alias},
	{"unalias", ft_unalias},
	{NULL, NULL}
};

int		exe_alias(t_alias *alias, t_cmd *cmd, t_data *data)
{
	char		*cmd_full;
	t_cmd		*root;

	root = cmd;
	cmd = cmd->next->next;
	if ((cmd_full = ft_strdup(alias->cmd)) == NULL)
		return (-1);
	while (cmd != root)
	{
		if ((cmd_full = ft_strcat_redi(cmd_full, " ")) == NULL
				|| (cmd_full = ft_strcat_redi(cmd_full, cmd->word)) == NULL)
			return (-1);
		cmd = cmd->next;
	}
	return (create_and_exec(cmd_full, data));
}

int	check_alias(t_cmd *cmd, t_data *data)
{
	t_alias	*alias;

	alias = data->alias;
	while (alias != NULL)
	{
		if (ft_strcmp(alias->name, cmd->next->word) == 1)
			return (exe_alias(alias, cmd, data));
		alias = alias->next;
	}
	return (2);
}

int	check_builtin(t_cmd *cmd, t_data *data)
{
	int	i;

	i = 0;
	while (builtin[i].name != NULL)
	{
		if (ft_strcmp(builtin[i].name, cmd->next->word) == 1)
		{
			g_last_exit = builtin[i].fct_builtin(cmd, data);
			return (g_last_exit);
		}
		i++;
	}
	return (2);
}

int	exe_cmd(t_cmd *cmd, t_data *data)
{
	int		ret;
	t_cmd		*tmp;

	if (cmd->next == cmd)
		return (0);
	if ((ret = check_alias(cmd, data)) != 2)
		return (ret);
	if ((ret = back_ground(cmd, data)) == -1)
		return (-1);
	else if (ret == 0)
	{
		if ((ret = check_builtin(cmd, data)) != 2)
			return (ret);
		tmp = cmd->next->next;
		while (tmp != cmd)
			tmp = globing(tmp);
		return (ft_exec(cmd, data));
	}
	return (1);
}
