#include "lib.h"

int	obtain_nbr(char *str, int nbr)
{
  if (!(*str >= '0' && *str <= '9'))
    return (nbr);
  nbr = nbr * 10 + (*str - '0');
  return (obtain_nbr(str + 1, nbr));
}

int	ft_getnbr(char *str)
{
  int	nbr_sign;

  nbr_sign = 1;
  while (*str == '-' || *str == '+')
    {
      if (*str == '-')
	nbr_sign *= -1;
      str = str + 1;
    }
  return (obtain_nbr(str, 0) * nbr_sign);
}
