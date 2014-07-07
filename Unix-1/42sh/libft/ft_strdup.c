#include <stdlib.h>
#include "lib.h"

char	*ft_strdup(char *str)
{
  int	i;
  char	*new_str;

  i = 0;
  new_str = malloc(ft_strlen(str) + 1);
  if (new_str == NULL)
    return (NULL);
  while (str[i])
    {
      new_str[i] = str[i];
      i++;
    }
  new_str[i] = '\0';
  return (new_str);
}
