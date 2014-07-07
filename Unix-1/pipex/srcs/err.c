#include <unistd.h>
#include "pipex.h"

void			err_cmd(char *cmd, char *msg)
{
	char	*str;

	str = ft_strnew(0);
	str = ft_strjoin(str, msg);
	str = ft_strjoin(str, cmd);
	ft_putendl_fd(str, 2);
	_exit(1);
}
