
#include <string.h>

int	ft_strequ(char const *s1, char const *s2)
{
	if (s1 == NULL && s2 == NULL)
		return (1);
	if ((s1 == NULL && s2 != NULL) || (s2 == NULL && s1 != NULL))
		return (0);
	while (*s1 != '\0' && *s1 == *s2 && *s2 != '\0')
	{
		s1++;
		s2++;
	}
	if (*s2 == '\0' && *s1 == '\0')
		return (1);
	else
		return (0);
}
