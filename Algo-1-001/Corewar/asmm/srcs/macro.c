/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*   macro.c                                             :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*   by: mrebours <mrebours@student.42.fr>               +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2014/01/15 20:10:04 by mrebours             #+#    #+#            */
/*   Updated: 2014/01/15 20:18:14 by mrebours            ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"
#include <stdlib.h>

void	check_def(void)
{
	if (T_REG != 1
		|| T_DIR != 2
		|| T_IND != 4
		|| IND_SIZE != 2
		|| DIR_SIZE != 4
		|| REG_SIZE != 4)
	{
		ft_putendl_fd("Error wrong define", 2);
		exit(-1);
	}
}

