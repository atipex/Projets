/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 12:59:47 by mrebours            #+#    #+#             */
/*   Updated: 2014/05/16 12:59:48 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUF_SIZE	42

typedef struct		s_fd
{
	char			*str;
	int				fd;
	struct s_fd		*next;
}					t_fd;

# define CHECK_GNL(x)   ((x == 0) ? (x) : (x - 1))

char				*get_next_line(const int fd);

#endif
