#include <stdlib.h>
#include "42sh.h"
#include "lib.h"

char	*gimme_home(t_env *env)
{
  t_env	*tmp;

  tmp = env->next;
  while (tmp != env)
    {
      if (ft_strncmp(tmp->var, "HOME=", 5))
	return (tmp->var + 5);
      tmp = tmp->next;
    }
  return (NULL);
}

char	*gimme_cd_path(t_cmd *cmd, t_data *data)
{
  char	*path;

  (void)data;
  cmd = cmd->next;
  path = cmd->word;
  return (path);
}

void	swap_char(char **old_pwd, char **pwd)
{
  char	*swap;

  swap = *old_pwd;
  *old_pwd = *pwd;
  *pwd = swap;
}
