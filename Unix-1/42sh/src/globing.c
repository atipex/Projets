#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "42sh.h"
#include "lib.h"
#include "ft_printf.h"

t_cmd		*globing(t_cmd *tmp)
{
  glob_t	gb;
  int		flags;
  unsigned int	i;
  char		*word;
  t_cmd		*new_elem;

  flags = GLOB_NOMAGIC;
  i = 0;
  if ((glob(tmp->word, flags, NULL, &gb)) != 0)
    ft_printf("%s: No match.\n", tmp->word);
  if (gb.gl_pathc == 0)
    return (tmp->next);
  while (i < gb.gl_pathc)
    {
      if ((word = ft_strdup(gb.gl_pathv[i++])) == NULL)
	return (ft_error_ptr("Fail strdup"));
      new_elem = add_to_list(tmp, word);
    }
  remove_elem(tmp);
  globfree(&gb);
  return (new_elem->next);
}

char		*globing_for_cd(t_cmd *cmd)
{
  glob_t	gb;
  int		flags;

  flags = GLOB_NOMAGIC | GLOB_TILDE;
  cmd = cmd->next;
  if ((glob(cmd->word, flags, NULL, &gb)) != 0)
    {
      ft_printf("%s: No match.\n", cmd->word);
      return (NULL);
    }
  if (gb.gl_pathc == 0)
    ft_printf("%s: No match.\n", cmd->word);
  else if (gb.gl_pathc > 1)
    ft_printf("%s: Ambiguous.\n", cmd->word);
  else
    return (ft_strdup(gb.gl_pathv[0]));
  globfree(&gb);
  return (NULL);
}

int		globing_for_echo(t_cmd *cmd)
{
  glob_t	gb;
  int		flags;
  unsigned int	i;

  flags = GLOB_NOMAGIC;
  i = 0;
  if ((glob(cmd->word, flags, NULL, &gb)) != 0)
    ft_printf("%s: No match.\n", cmd->word);
  while (i < gb.gl_pathc)
    ft_printf("%s ", gb.gl_pathv[i++]);
  globfree(&gb);
  return (0);
}

char		*globing_for_setenv(t_cmd *cmd)
{
  glob_t	gb;
  int		flags;
  char		*value;
  unsigned int	i;

  flags = GLOB_NOMAGIC;
  if ((glob(cmd->next->word, flags, NULL, &gb)) != 0)
    {
      ft_printf("%s: No match.\n", cmd->word);
      return ("");
    }
  i = 0;
  value = NULL;
  while (i < gb.gl_pathc)
    {
      if ((value = ft_strcat(value, gb.gl_pathv[i++])) == NULL)
	return (NULL);
      if (i < gb.gl_pathc)
	if ((value = ft_strcat(value, " ")) == NULL)
	  return (NULL);
    }
  globfree(&gb);
  return (value);
}
