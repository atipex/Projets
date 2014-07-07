
char	*ft_strrchr(const char *s, int c)
{
	char	*save;

	save = 0;
	while (1)
	{
		if (*s == c)
			save = (char *)s;
		if (!*s)
			return (save);
		s++;
	}
}
