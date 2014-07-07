#include "ft_puissance4.h"

static int	try_h(int c, t_tab *obj, int i, int j)
{
	if (j + 3 <= obj->cols)
	{
		if (obj->tab[i][j + 1] == c && obj->tab[i][j + 2] == c &&
			obj->tab[i][j + 3] == c)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

static int	try_v(int c, t_tab *obj, int i, int j)
{
	if (i + 3 <= obj->lines)
	{
		if (obj->tab[i + 1][j] == c && obj->tab[i + 2][j] == c &&
				obj->tab[i + 3][j] == c)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

static int	try_hh(int c, t_tab *obj, int i, int j)
{
	if (i + 3 <= obj->lines && j + 3 <= obj->cols)
	{
		if (obj->tab[i + 1][j + 1] == c && obj->tab[i + 2][j + 2] == c &&
			obj->tab[i + 3][j + 3] == c)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

static int	try_hhl(int c, t_tab *obj, int i, int j)
{
	if (i + 3 <= obj->lines && j - 3 >= 0)
	{
		if (obj->tab[i + 1][j - 1] == c && obj->tab[i + 2][j - 2] == c &&
			obj->tab[i + 3][j - 3] == c)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

int		try_ww(int c, t_tab *obj, int i, int j)
{
	if (try_h(c, obj, i, j) || try_hh(c, obj, i, j) || try_v(c, obj, i, j)
			|| try_hhl(c, obj, i, j))
		return (1);
	return (0);
}

