#include <stdlib.h>
#include "42sh.h"

void		free_tree(t_tree *tree)
{
  t_param	*tmp_param;
  t_cmd		*tmp_cmd;

  tmp_param = tree->param->next;
  while (tmp_param != tree->param)
    {
      if (tmp_param->tree)
	free_tree(tmp_param->tree);
      else
	{
	  tmp_cmd = tmp_param->cmd->next;
	  while (tmp_cmd != tmp_param->cmd)
	    {
	      tmp_cmd = tmp_cmd->next;
	      free(tmp_cmd->prev);
	    }
	  free(tmp_cmd);
	}
      tmp_param = tmp_param->next;
      free(tmp_param->prev);
    }
  free(tmp_param);
  free(tree);
}

void	free_cmd(t_cmd *cmd)
{
  t_cmd	*tmp;

  tmp = cmd->next;
  while (tmp != cmd)
    {
      tmp = tmp->next;
      free(tmp->prev);
    }
  free(tmp);
}

void	free_command(char *command, t_cmd *cmd_data)
{
  t_cmd	*tmp_cmd;

  tmp_cmd = cmd_data->next;
  while (tmp_cmd != cmd_data)
    {
      tmp_cmd = tmp_cmd->next;
      free(tmp_cmd->prev);
    }
  free(cmd_data);
  free(command);
}

void	free_data(t_data *data)
{
  int	i;
  t_env	*tmp;

  i = 0;
  while (data->path && data->path[i++])
    free(data->path[i - 1]);
  free(data->path);
  tmp = data->env->next;
  while (tmp != data->env)
    {
      tmp = tmp->next;
      free(tmp->prev->var);
      free(tmp->prev);
    }
  free(tmp);
  tmp = data->his->next;
  while (tmp != data->his)
    {
      tmp = tmp->next;
      free(tmp->prev->var);
      free(tmp->prev);
    }
  free(tmp);
  free(data);
}
