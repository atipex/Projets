
#include "ft_puissance4.h"

int			ft_check_digit(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit((int)str[i]))
			return (1);
		i++;
	}
	return (0);
}

int			check_data(int ac, char **av)
{
	if (ac != 3)
	{
		ft_putendl_fd("Usage : puissance4 number_of_rows number_of_columns",
				2);
		return (1);
	}
	if (ft_atoi(av[1]) < 0 || ft_atoi(av[2]) < 0)
	{
		ft_putendl_fd("Number must be greater than 0", 2);
		return (1);
	}
	if (ft_check_digit(av[1]) || ft_check_digit(av[2]))
	{
		ft_putstr_fd("Argument must be a number ", 2);
		ft_putendl_fd("and must be greater than 0", 2);
		return (1);
	}
		if (ft_atoi(av[1]) < 6 || ft_atoi(av[2]) < 7)
	{
		ft_putendl_fd("6 rows and 7 columns minimum", 2);
		return (1);
	}
	return (0);
}
