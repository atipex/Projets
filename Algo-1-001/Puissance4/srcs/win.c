#include "ft_puissance4.h"

static int	is_in(char *tab, char c, int n)
{
	int		i;

	i = n;
	while (tab[i])
	{
		if (tab[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static int	is_you_win(t_tab *obj, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (obj->tab[i])
	{
		k = 0;
		while (obj->tab[i][k])
		{
			if ((j = is_in(obj->tab[i], c, k)) != -1)
			{
				if (try_ww(c, obj, i, j))
					return (1);
			}
			k++;
		}
		i++;
	}
	return (0);
}

static int	is_ia_win(t_tab *obj, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (obj->tab[i])
	{
		k = 0;
		while (obj->tab[i][k])
		{
			if ((j = is_in(obj->tab[i], c, k)) != -1)
			{
				if (try_ww(c, obj, i, j))
					return (1);
			}
			k++;
		}
		i++;
	}
	return (0);
}

int			is_win(t_tab *obj)
{
	if (is_you_win(obj, PLAYER))
	{
		ft_putchar('\n');
		aff_tab(glob_obj(0)->tab);
		ft_putendl("\n\033[036mYou win !!\033[0m\n");
		return (1);
	}
	else if (is_ia_win(obj, IA))
	{
		ft_putchar('\n');
		aff_tab(glob_obj(0)->tab);
		ft_putendl("\n\033[036mComputer win !!\033[0m\n");
		return (1);
	}
	else if (obj->count_max == 0)
	{
		ft_putchar('\n');
		aff_tab(glob_obj(0)->tab);
		ft_putendl("\n\033[036mTie !!\033[0m\n");
		return (1);
	}
	return (0);
}

