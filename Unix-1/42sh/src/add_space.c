#include <stdlib.h>
#include "42sh.h"
#include "lib.h"

t_identify space_tab[] =
{
	{REDI_D_LEFT, TYPE_D_LEFT},
	{REDI_D_RIGHT, TYPE_D_RIGHT},
	{REDI_RIGHT, TYPE_RIGHT},
	{REDI_LEFT, TYPE_LEFT},
	{AND, TYPE_AND},
	{BGROUND, TYPE_BGROUND},
	{OR, TYPE_OR},
	{CMD_SEP, TYPE_CMD_SEP},
	{PIPE, TYPE_PIPE},
	{NULL, TYPE_ARG}
};

int		gimme_nbr_sep(char *command)
{
	int		i;
	int		j;
	int		nbr_sep;

	i = 0;
	nbr_sep = 0;
	while (command[i])
	{
		j = 0;
		while (space_tab[j].name
				&& !ft_strncmp(command + i,
					space_tab[j].name,
					ft_strlen(space_tab[j].name)))
			j++;
		if (space_tab[j].name)
		{
			i += ft_strlen(space_tab[j].name);
			nbr_sep++;
		}
		else
			i++;
	}
	return (nbr_sep);
}

void	its_time_to_add_the_spaces(char *command, char *new_command)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (command[i])
	{
		k = 0;
		new_command[j++] = ' ';
		while (space_tab[k].name
				&& !ft_strncmp(command + i, space_tab[k].name,
					ft_strlen(space_tab[k].name)))
			k++;
		if (space_tab[k].name && ft_strlen(space_tab[k].name) > 1)
			new_command[j++] = command[i++];
		else if (!space_tab[k].name)
			j--;
		new_command[j++] = command[i++];
		if (space_tab[k].name)
			new_command[j++] = ' ';
	}
	new_command[j] = '\0';
}

char	*add_some_space(char *command)
{
	char	*new_command;

	new_command = malloc(ft_strlen(command) + 2 * gimme_nbr_sep(command) + 1);
	if (new_command == NULL)
		return (NULL);
	its_time_to_add_the_spaces(command, new_command);
	free(command);
	return (new_command);
}
