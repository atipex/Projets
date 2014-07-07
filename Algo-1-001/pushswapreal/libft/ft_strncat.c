
#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*save;

	save = s1;
	while (*save)
		save++;
	while (n != 0 && *s2 != '\0')
	{
		*save = *s2++;
		n--;
		save++;
	}
	if (*save != '\0')
		*save = '\0';
	return (s1);
}
