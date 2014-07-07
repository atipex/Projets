#include <unistd.h>
#include "42sh.h"

int	(*redi_ptr[4])(char *, t_data *) =
{
  redi_right,
  redi_d_right,
  redi_left,
  redi_d_left
};

t_exec	type_tree_sep[3] =
  {
    {TYPE_AND, and_exec},
    {TYPE_OR, or_exec},
    {TYPE_PIPE, pipe_exec}
  };

void	remove_redi(t_cmd *cmd)
{
  t_cmd	*tmp;

  tmp = cmd->next;
  while (tmp != cmd)
    {
      if (tmp->type == TYPE_LEFT
	  || tmp->type == TYPE_RIGHT
	  || tmp->type == TYPE_D_LEFT
	  || tmp->type == TYPE_D_RIGHT)
	{
	  tmp = tmp->next->next;
	  remove_elem(tmp->prev);
	  remove_elem(tmp->prev);
	}
      else
	tmp = tmp->next;
    }
}

int	find_redi_and_exec(t_cmd *cmd, t_data *data)
{
  int	ret;
  t_cmd	*tmp;

  tmp = cmd->next;
  while (tmp != cmd)
    {
      while (tmp != cmd
	     && tmp->type != TYPE_LEFT
	     && tmp->type != TYPE_D_LEFT
	     && tmp->type != TYPE_RIGHT
	     && tmp->type != TYPE_D_RIGHT)
	tmp = tmp->next;
      if (tmp != cmd)
	{
	  if ((ret = redi_ptr[tmp->type - 2](tmp->next->word, data)) == -1
	      || ret == -2)
	    return (ret);
	  tmp = tmp->next->next;
	}
    }
  remove_redi(cmd);
  return (exe_cmd(cmd, data));
}

int	should_i_exec_other_cmd(t_tree *tree, t_param *param, t_data *data)
{
  int	i;

  i = 0;
  if ((param == tree->param->next && tree->type != TYPE_PIPE)
      || tree->type == TYPE_CMD_SEP)
    return (1);
  while (type_tree_sep[i].type != tree->type)
    i++;
  return (type_tree_sep[i].fct(tree, param, data));
}

int		exec_tree(t_tree *tree, t_data *data)
{
  int		ret;
  t_param	*param;

  data->pipe = 0;
  param = tree->param->next;
  while (param != tree->param)
    {
      if (dup2(data->save_fd[0], 0) == -1
	  || dup2(data->save_fd[1], 1) == -1)
	return (ft_error("Fail dup2"));
      if ((ret = should_i_exec_other_cmd(tree, param, data)) == -1 || ret == 0)
	return (ret);
      if (param->tree && exec_tree(param->tree, data) == -1)
	return (-1);
      else if (!param->tree)
	if (find_redi_and_exec(param->cmd, data) == -1)
	  return (-1);
      if (tree->type == TYPE_PIPE)
	pipe_exit(tree, param);
      param = param->next;
    }
  return (0);
}
