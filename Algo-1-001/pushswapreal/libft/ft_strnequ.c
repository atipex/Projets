
#include <string.h>

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	i;

	i = 0;
	if (s1 == NULL && s2 == NULL)
		return (1);
	if ((s1 == NULL && s2 != NULL) || (s2 == NULL && s1 != NULL))
		return (0);
	while (n > 0)
	{
		if (s1[i] != s2[i])
			return (0);
		else if ((s1[i] == '\0' && s2[i] == '\0'))
			return (1);
		i++;
		n--;
	}
	if (s1[i - 1] == s2[i - 1])
		return (1);
	else
		return (0);
}
