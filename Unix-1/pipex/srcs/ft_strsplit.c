#include <stdlib.h>
#include "pipex.h"

static int	ft_nb_word(char const *s, char c)
{
	int		i;
	int		is_word;

	i = 0;
	is_word = 0;
	while (*s)
	{
		if ((is_word == 0) && (*s != c))
		{
			is_word = 1;
			i++;
		}
		else if (is_word == 1 && *s == c)
			is_word = 0;
		s++;
	}
	return (i);
}

static int	ft_word_len(char const *s, char c)
{
	int		length;

	length = 0;
	while (*s != c && *s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}

char		**ft_strsplit(char const *s, char c)
{
	char		**array;
	int			nb_word;
	int			index;

	if (s)
	{
		index = 0;
		nb_word = ft_nb_word(s, c);
		array = (char **)malloc(sizeof(char *) * (ft_nb_word(s, c) + 1));
		if (!array)
			return (NULL);
		while (nb_word--)
		{
			while (*s == c && *s != '\0')
				s++;
			array[index] = ft_strsub(s, 0, ft_word_len(s, c));
			if (array[index] == NULL)
				return (NULL);
			s = s + ft_word_len(s, c);
			index++;
		}
		array[index] = NULL;
		return (array);
	}
	return (NULL);
}
