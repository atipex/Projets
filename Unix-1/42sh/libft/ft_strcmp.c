#include "lib.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (s1[i] && s2[i] && i < n)
    {
      if (s1[i] != s2[i])
	return (0);
      i++;
    }
  if (i == n)
    return (1);
  return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] && s2[i])
    {
      if (s1[i] != s2[i])
	return (0);
      i = i + 1;
    }
  if (!s1[i] && !s2[i])
    return (1);
  return (0);
}
