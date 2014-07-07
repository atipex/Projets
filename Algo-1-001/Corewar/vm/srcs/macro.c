#include "corewar.h"
#include <stdlib.h>

void	check_def(void)
{
	if (T_REG != 1
		|| T_DIR != 2
		|| T_IND != 4
		|| IND_SIZE != 2
		|| DIR_SIZE != 4
		|| REG_SIZE != 4)
		ft_er("Error wrong define");
}

int		ret_tab_i(int val, int value)
{
	if (val >= 0)
		return (value % 256);
	else
	{
		if (value)
			return (255 + value % 256 + 1);
		else
			return (255 + value % 256);
	}
}

