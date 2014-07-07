#include <libft.h>

int		ft_init_player(char *line)
{
	if (ft_strstr(line, "p1"))
		return (1);
	else
		return (2);
}
