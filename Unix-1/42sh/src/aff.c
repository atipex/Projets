#include <stdlib.h>
#include "lib.h"
#include "ft_printf.h"
#include "42sh.h"

int		aff_current_directory(void)
{
	int			ret;
	glob_t		pglob;

	if ((ret = glob("*", GLOB_NOMAGIC | GLOB_TILDE, NULL, &pglob))
			&& ret != GLOB_NOMATCH)
		return (ft_error("fail glob"));
	ft_putchar('\n');
	if (pglob.gl_pathc == 0)
		return (0);
	if (aff_pglob(&pglob) == -1)
		return (-1);
	return (0);
}

int		aff_bin(char *word, t_data *data)
{
	int			i;
	int			ret;
	glob_t		pglob;
	char		*pattern;

	i = 0;
	if ((pattern = ft_strcat(word, "*")) == NULL
			|| ((ret = glob(pattern, GLOB_NOMAGIC | GLOB_TILDE, NULL, &pglob))
				&& ret != GLOB_NOMATCH))
		return (ft_error("fail glob"));
	ft_putchar('\n');
	while (data->path && data->path[i])
	{
		free(pattern);
		if ((pattern = ft_strcat(data->path[i], word)) == NULL
				|| (pattern = ft_strcat(pattern, "*")) == NULL
				|| ((ret = glob(pattern, GLOB_NOMAGIC | GLOB_TILDE | GLOB_APPEND,
							NULL, &pglob)) && ret != GLOB_NOMATCH))
			return (ft_error("fail glob"));
		++i;
	}
	if (pglob.gl_pathc && aff_pglob(&pglob) == -1)
		return (-1);
	free(pattern);
	return (0);
}

int		aff_path(char *word)
{
	int			ret;
	glob_t		pglob;
	char		*pattern;

	if ((pattern = ft_strcat(word, "*")) == NULL
			|| ((ret = glob(pattern, GLOB_NOMAGIC | GLOB_TILDE, NULL, &pglob))
				&& ret != GLOB_NOMATCH))
		return (ft_error("fail glob"));
	ft_putchar('\n');
	if (pglob.gl_pathc == 0)
		return (0);
	if (aff_pglob(&pglob) == -1)
		return (-1);
	free(pattern);
	return (0);
}
