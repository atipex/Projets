#include "lem_in.h"
#include <stdlib.h>

t_path		*path_made(void)
{
	t_path		*path;

	path = (t_path *)malloc(sizeof(t_path));
	path->lab = NULL;
	path->nxt = NULL;
	return (path);
}

t_path		*path_add(t_path *path, t_lab *lab)
{
	t_path		*new;

	new = path_made();
	new->lab = lab;
	new->nxt = path;
	return (new);
}

void		path_del(t_path *path)
{
	t_path		*tmp;

	while (path)
	{
		tmp = path;
		path = path->nxt;
		free(tmp);
	}
}

