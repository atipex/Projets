
#include "lib.h"
#include "ft_printf.h"
#include "42sh.h"

int	is_a_redi(t_cmd *root, t_cmd **cmd)
{
  if ((*cmd)->type == TYPE_LEFT || (*cmd)->type == TYPE_D_LEFT
      || (*cmd)->type == TYPE_RIGHT || (*cmd)->type == TYPE_D_RIGHT)
    (*cmd) = (*cmd)->next;
  else
    return (0);
  if ((*cmd) != root && (*cmd)->type == TYPE_ARG)
    {
      (*cmd)->type = TYPE_REDI_ARG;
      (*cmd) = (*cmd)->next;
      return (1);
    }
  else
    {
      ft_printf("Missing name for redirect.\n");
      return (-1);
    }
}

int	get_basic_cmd(t_cmd *root, t_cmd *cmd)
{
  t_cmd	*tmp;
  int	ret;

  tmp = cmd;
  while (tmp != root && tmp->type != TYPE_AND
	 && tmp->type != TYPE_OR && tmp->type != TYPE_CMD_SEP)
    {
      ret = is_a_redi(root, &tmp);
      if (ret == -1)
	return (0);
      else if (ret == 0 && tmp->type != TYPE_PIPE)
	tmp->type = TYPE_CMD;
      if (ret == 0)
	tmp = tmp->next;
    }
  return (1);
}

int	get_cmd(t_cmd *root, t_cmd *cmd)
{
  t_cmd	*tmp;

  tmp = cmd;
  while (tmp != root && tmp->type != TYPE_CMD_SEP)
  {
    if (get_basic_cmd(root, tmp) == 0)
      return (0);
    while (tmp != root && tmp->type != TYPE_CMD_SEP
	   && tmp->type != TYPE_AND && tmp->type != TYPE_OR)
      tmp = tmp->next;
    if (tmp != root && tmp->type != TYPE_CMD_SEP)
      tmp = tmp->next;
  }
  return (1);
}

int	parser(t_cmd *cmd)
{
  t_cmd	*tmp;

  tmp = cmd->next;
  while (tmp != cmd)
    {
      if (get_cmd(cmd, tmp) == 0)
	return (0);
      while (tmp != cmd && tmp->type != TYPE_CMD_SEP)
	tmp = tmp->next;
      if (tmp != cmd)
	tmp = tmp->next;
    }
  if (check_null_cmd(cmd) == -1
      || check_redi_pipe(cmd) == -1)
    return (0);
  return (1);
}
