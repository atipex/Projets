
char	*ft_strcpy(char *s1, const char *s2)
{
	char	*save;

	save = s1;
	while (*s2)
		*s1++ = *s2++;
	*s1 = '\0';
	return (save);
}
