#include "ft_puissance4.h"
#include <stdlib.h>

int		diag_2_check(char **tab, int x, int y, int y_m)
{
	int		i;

	i = 0;
	if (y + 4 > y_m || x - 4 < 0 || tab[x][y] == '\0')
		return (0);
	while (i < 4 && tab[x - i][y + i] == tab[x][y])
		i++;
	if (i == 4)
		return (1);
	return (0);
}

int		ia_test(char **tab, int col, int j)
{
	int		i;

	if (col == 0 || col - 1 > glob_obj(0)->lines)
		return (0);
	i = 0;
	while (i + 1 < (int)ft_strlen(tab[0]) && tab[i + 1][col - 1] == '\0')
		i++;
	if (tab[i][col - 1] == '\0')
	{
		if (!j)
		tab[i][col - 1] = IA;
		else
		tab[i][col - 1] = PLAYER;
	}
	else
		return (0);
	return (1);
}

int		ia_check(char **tab)
{
	int		i;
	int		j;
	int		x_m;
	int		y_m;

	x_m = ft_strlen(tab[0]);
	y_m = glob_obj(0)->lines;
	i = -1;
	while (++i <= x_m - 1)
	{
		j = -1;
		while (++j <= y_m)
		{
			if (vert_check(tab, i, j, x_m) || hor_check(tab, i, j, y_m)
			|| diag_1_check(tab, i, j, x_m) || diag_1_check(tab, i, j, y_m))
			{
				if (tab[i][j] == IA)
					return (0);
				return (1);
			}
		}
	}
	return (-1);
}

int		ia_turn(char **tab)
{
	int		i;
	int		col;
	char	**cpy_tab_1;
	char	**cpy_tab_2;

	cpy_tab_1 = NULL;
	cpy_tab_2 = NULL;
	i = 0;
	col = glob_obj(0)->lines;
	while (i < col)
	{
		cpy_tab_1 = tab_cpy(tab);
		cpy_tab_2 = tab_cpy(tab);
		if (ia_test(cpy_tab_2, i, 0) && ia_check(cpy_tab_2) == 0)
				break ;
		if (ia_test(cpy_tab_1, i, 1) && ia_check(cpy_tab_1) == 1)
				break ;
		free_tab(&cpy_tab_1);
		free_tab(&cpy_tab_2);
		i++;
	}
	if (i == glob_obj(0)->lines)
		i = rand() % ((glob_obj(0)->lines + 1));
	return (i);
}
