#include <stdlib.h>
#include "42sh.h"
#include "lib.h"

int		add_to_cmd(char *result)
{
	int		i;
	int		j;

	i = ft_strlen(g_prompt.cmd);
	j = 0;
	while (i + ft_strlen(result) + 2 > g_prompt.size)
	{
		if ((g_prompt.cmd = ft_realloc(g_prompt.cmd,
						g_prompt.size + SIZE_MALLOC)) == NULL)
			return (ft_error("Fail malloc"));
		g_prompt.size += 1024;
	}
	while (result[j])
		g_prompt.cmd[i++] = result[j++];
	g_prompt.cmd[i++] = ' ';
	g_prompt.cmd[i] = '\0';
	return (0);
}

int		find_word_complete(glob_t *pglob, char *prompt)
{
	int		i;
	int		j;

	i = ft_strlen(pglob->gl_pathv[0]) - 1;
	j = ft_strlen(g_prompt.cmd) - 1;
	while (i > 0 && pglob->gl_pathv[0][i - 1] != '/')
		i--;
	while (j > 0 && prompt[j - 1] != ' '
			&& prompt[j - 1] != '\t'
			&& prompt[j - 1] != '/')
		j--;
	while (pglob->gl_pathv[0][i] == prompt[j]
			&& prompt[j] && pglob->gl_pathv[0][i])
	{
		i++;
		j++;
	}
	if (add_to_cmd(pglob->gl_pathv[0] + i) == -1)
		return (-1);
	return (0);
}

int		auto_complete(glob_t *pglob)
{
	char	*prompt;

	prompt = g_prompt.cmd;
	if (g_prompt.i == 1
			|| prompt[ft_strlen(prompt) - 1] == ' '
			|| prompt[ft_strlen(prompt) - 1] == '\t')
	{
		if (add_to_cmd(pglob->gl_pathv[0]) == -1)
			return (-1);
		return (0);
	}
	return (find_word_complete(pglob, prompt));
}
