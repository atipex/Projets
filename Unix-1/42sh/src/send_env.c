#include <stdlib.h>
#include "lib.h"
#include "42sh.h"

t_env	*gimme_root(void)
{
  t_env	*root;

  root = malloc(sizeof(t_env));
  if (root == NULL)
    return ((t_env *)ft_error_ptr("Fail malloc()"));
  root->next = root;
  root->prev = root;
  root->var = NULL;
  root->pos = 1;
  root->num = 0;
  return (root);
}

t_env	*put_in_list(t_env *root, char *param)
{
  t_env	*new_elem;

  if ((new_elem = malloc(sizeof(t_env))) == NULL)
    return ((t_env *)ft_error_ptr("Fail malloc()"));
  new_elem->num = root->prev->num + 1;
  new_elem->prev = root->prev;
  new_elem->next = root;
  root->prev->next = new_elem;
  root->prev = new_elem;
  new_elem->var = ft_strdup(param);
  if (!new_elem->var)
    return ((t_env *)ft_error_ptr("Fail ft_strdup()."));
  new_elem->pos = -1;
  return (new_elem);
}

t_env	*gimme_env(char **env)
{
  int	i;
  t_env	*root;

  i = 0;
  if ((root = gimme_root()) == NULL)
    return (NULL);
  while (env[i])
    if (put_in_list(root, env[i++]) == NULL)
      return (NULL);
  return (root);
}
