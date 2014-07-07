#include "ft_puissance4.h"

int		vert_check(char **tab, int x, int y, int x_m)
{
	int		i;

	i = 0;
	if (x + 4 > x_m || tab[x][y] == '\0')
		return (0);
	while (i < 4 && tab[x + i][y] == tab[x][y])
		i++;
	if (i == 4)
		return (1);
	return (0);
}

int		hor_check(char **tab, int x, int y, int y_m)
{
	int		i;

	i = 0;
	if (y + 4 > y_m || tab[x][y] == '\0')
		return (0);
	while (i < 4 && tab[x][y + i] == tab[x][y])
		i++;
	if (i == 4)
		return (1);
	return (0);
}

int		diag_1_check(char **tab, int x, int y, int x_m)
{
	int		i;

	i = 0;
	if (y + 4 > glob_obj(0)->lines || x + 4 > x_m ||
		tab[x][y] == '\0')
		return (0);
	while (i < 4 && tab[x + i][y + i] == tab[x][y])
		i++;
	if (i == 4)
		return (1);
	return (0);
}

