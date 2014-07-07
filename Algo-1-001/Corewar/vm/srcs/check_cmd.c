#include "corewar.h"
#include <stdlib.h>


static int		check_n(int argc, char **argv, int i)
{
	int				num_champ;
	static char		champion_state[] = "0000";

	if (ft_strcmp(argv[i], "-n"))
		return (i);
	if (i + 2 < argc)
	{
		num_champ = ft_atoi(argv[i + 1]);
		if (num_champ <= 0 || num_champ > 4)
			ft_er("Numero of champ must be between 1 and 4");
		if (champion_state[num_champ - 1] == '1')
			ft_er("Can't use twice number of champions");
		champion_state[num_champ - 1] = 1;
		i += 2;
	}
	else
		ft_er("Wrong number of arguments");
	return (i);
}

static int		check_a(int argc, char **argv, int i)
{
	int		adress;

	if (ft_strcmp(argv[i], "-a"))
		return (i);
	if (i + 2 < argc)
	{
		adress = ft_atoi(argv[i + 1]);
		if (adress < 0 || adress > MEM_SIZE - 1)
			ft_er("Invalide adress position in memory");
		i += 2;
	}
	else
		ft_er("Wrong number of arguments");
	return (i);
}

int				check_c(char **argv, int i)
{
	static int		nb_champ;
	int				size;

	size = ft_strlen(argv[i]);
	if (size < 4)
		ft_er("Invalid file format");
	else if (ft_strcmp(&(argv[i][size - 4]), ".cor"))
		ft_er("Invalid file format");
	nb_champ++;
	if (nb_champ > 4)
		ft_er("Can't play with more than 4 players");
	return (++i);
}

int				check_cmd(int argc, char **argv)
{
	int		i;
	int		cycles;

	i = 1;
	cycles = -1;
	if (!ft_strcmp(argv[i], "-dump"))
	{
		if (i + 2 < argc)
		{
			if ((cycles = ft_atoi(argv[i + 1])) <= 0)
				ft_er("Cycle must be positiv");
			i += 2;
		}
		else
			ft_er("Wrong number of arguments");
	}
		while (i < argc)
		{
			i = check_n(argc, argv, i);
			i = check_a(argc, argv, i);
			i = check_c(argv, i);
		}
	return (cycles);
}

