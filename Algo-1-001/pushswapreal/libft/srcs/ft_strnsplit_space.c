
#include <stdlib.h>

static int	ft_count_word(char *str, int n)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	while (str[i] && i < n)
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (str[i])
		{
			word++;
			while (str[i] && str[i] != ' ' && str[i] != '\t' && i < n)
				i++;
		}
	}
	return (word);
}

static int	ft_len_word(char *str)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
	{
		i++;
		k++;
	}
	return (k);
}

static char	*ft_get_str(char *str)
{
	char	*tmp;
	int		i;

	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	i = ft_len_word(str);
	tmp = (char *)malloc(sizeof(*tmp) * (i + 1));
	i = 0;
	while (*str && *str != ' ' && *str != '\t')
	{
		tmp[i] = *str;
		i++;
		str++;
	}
	tmp[i] = '\0';
	return (tmp);
}

static int	ft_next_word(char *str)
{
	int		i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
		i++;
	return (i);
}

char		**ft_strnsplit_space(char *str, int n)
{
	int		nb_word;
	int		i;
	char	**tab;

	i = -1;
	nb_word = ft_count_word(str, n);
	tab = (char **)malloc(sizeof(char *) * nb_word + 1);
	while (++i < nb_word)
	{
		tab[i] = ft_get_str(str);
		str += ft_next_word(str);
	}
	tab[i] = NULL;
	return (tab);
}
