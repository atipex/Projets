#include <stdlib.h>
#include "42sh.h"
#include "lib.h"

char	*sep_tab[] =
{
	PIPE,
	AND,
	OR,
	CMD_SEP,
	NULL,
	REDI_RIGHT,
	REDI_LEFT,
	REDI_D_RIGHT,
	REDI_D_LEFT,
	NULL
};

char	*gimme_last_cmd_bloc(char *cmd)
{
	int		i;
	int		j;

	i = ft_strlen(cmd) - 1;
	while (i > 0)
	{
		j = 0;
		while (sep_tab[j])
		{
			if (ft_strncmp(sep_tab[j], cmd + i, ft_strlen(sep_tab[j])))
			{
				i += ft_strlen(sep_tab[j]);
				while (cmd[i] == ' ' || cmd[i] == '\t')
					i++;
				return (cmd + i);
			}
			j++;
		}
		i--;
	}
	return (cmd);
}

int	gimme_nbr_words(char *cmd)
{
	int		i;
	int		nbr_words;

	i = 0;
	nbr_words = 0;
	while (cmd[i])
	{
		while (cmd[i] == ' ' || cmd[i] == '\t')
			++i;
		if (cmd[i])
		{
			nbr_words++;
			while (cmd[i] && cmd[i] != ' ' && cmd[i] != '\t')
				++i;
		}
	}
	return (nbr_words);
}

char	*gimme_last_word(char *cmd)
{
	int		i;

	i = ft_strlen(cmd) - 1;
	while (i > 0)
	{
		if (cmd[i] == ' ' || cmd[i] == '\t')
			return (cmd + i + 1);
		--i;
	}
	return (cmd);
}

int	auto_completation(char buf[3], char **cmd, int *i, t_data *data)
{
	int		ret;
	int		nbr_words;
	char	*cmd_bloc;

	(void)buf;
	cmd_bloc = gimme_last_cmd_bloc(*cmd);
	nbr_words = gimme_nbr_words(cmd_bloc);
	cmd_bloc = gimme_last_word(cmd_bloc);
	if (nbr_words == 0)
		ret = aff_current_directory();
	else if (nbr_words == 1)
		ret = aff_bin(cmd_bloc, data);
	else
		ret = aff_path(cmd_bloc);
	aff_prompt();
	ft_putstr(*cmd, 1);
	*i = ft_strlen(*cmd) + 1;
	return (ret);
}
