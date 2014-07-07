#include "pipex.h"

void			creat_tab_1(t_struct *obj)
{
	char		*swap;
	int			i;
	char		**ret;

	ret = NULL;
	i = 0;
	swap = ft_strnew(0);
	swap = ft_strjoin(swap, "cat");
	swap = ft_strjoin(swap, " ");
	while (obj->file1[i] != NULL)
	{
		swap = ft_strjoin(swap, obj->file1[i]);
		swap = ft_strjoin(swap, " ");
		i++;
	}
	ret = ft_strsplit(swap, ' ');
	obj->file1 = NULL;
	obj->file1 = ret;
}
