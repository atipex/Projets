
int	ft_getnbr(char *str)
{
  int	res;
  int	counter;
  int	sign;

  counter = 0;
  sign = 1;
  res = 0;
  while (str[counter])
    {
      if (str[counter] == '-')
	sign *= -1;
      else if (ft_char_isnum(str[counter]) == 1)
	res = res * 10 + (str[counter] - 48);
      else if (str[counter] != '+')
	return (res * sign);
      counter += 1;
    }
  return (res * sign);
}
