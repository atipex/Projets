
#include "ft_puissance4.h"

void		ins_col(int i)
{
	int		j;
	char	c;

	if (!glob_obj(0)->player)
		c = PLAYER;
	else
		c = IA;
	j = 0;
	while (glob_obj(0)->tab[j][i] != EMPTY)
		j++;
	glob_obj(0)->tab[j][i] = c;
	change_player();
	return ;
}

int			check_col(int i)
{
	if (glob_obj(0)->tab[glob_obj(0)->lines - 1][i] != EMPTY)
	{
		ft_putendl("\n\tThis column is FULL. Please select another");
		return (1);
	}
	return (0);
}
