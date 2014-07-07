/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 15:16:00 by mrebours            #+#    #+#             */
/*   Updated: 2013/12/08 15:37:57 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strcat(char *s1, const char *s2)
{
	ft_strcpy(&s1[ft_strlen(s1)], s2);
	return (s1);
}

