#include <stdlib.h>
#include "42sh.h"
#include "lib.h"
#include "ft_printf.h"

void	*ft_error_ptr(char *error)
{
	ft_putstr("error: ", 2);
	ft_putstr(error, 2);
	ft_putstr("\n", 2);
	g_exit_value = -1;
	return (NULL);
}

int		ft_error(char *error)
{
	ft_putstr("error: ", 2);
	ft_putstr(error, 2);
	ft_putstr("\n", 2);
	g_exit_value = -1;
	return (-1);
}

int		ft_error_parse(char *error)
{
	ft_putstr(error, 2);
	ft_putstr("\n", 2);
	return (-1);
}
