#include <stdlib.h>
#include "lib.h"

char	*ft_strcat_redi(char *str1, char *str2)
{
  int	i;
  int	j;
  char	*new_str;

  i = 0;
  j = 0;
  new_str = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
  if (new_str == NULL)
    return (NULL);
  while (str1 && str1[i])
    {
      new_str[i] = str1[i];
      i++;
    }
  while (str2[j])
    new_str[i++] = str2[j++];
  new_str[i] = '\0';
  free(str1);
  return (new_str);
}

char	*ft_strcat(char *str1, char *str2)
{
  int	i;
  int	j;
  char	*new_str;

  i = 0;
  j = 0;
  new_str = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
  if (new_str == NULL)
    return (NULL);
  while (str1 && str1[i])
    {
      new_str[i] = str1[i];
      i++;
    }
  while (str2[j])
    new_str[i++] = str2[j++];
  new_str[i] = '\0';
  return (new_str);
}
