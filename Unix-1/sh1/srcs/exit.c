/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 07:15:18 by agoomany          #+#    #+#             */
/*   Updated: 2013/12/29 14:23:22 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftminishell1.h"

void		ft_exit(char **cmd)
{
	int			i;

	i = 0;
	while (cmd[i] != NULL)
		i++;
	if (i == 2)
		exit(ft_atoi(cmd[1]));
	else
		exit(0);
}

