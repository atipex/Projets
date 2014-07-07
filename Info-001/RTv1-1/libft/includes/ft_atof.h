/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 16:26:32 by mrebours            #+#    #+#             */
/*   Updated: 2014/06/26 16:26:34 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ATOF_H
# define FT_ATOF_H

typedef struct	s_atof
{
	double	integer_part;
	double	fraction_part;
	int		divisor;
	int		sign;
	int		fraction;
}				t_atof;

#endif
