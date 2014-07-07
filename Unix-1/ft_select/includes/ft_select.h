/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/02 17:47:39 by mrebours            #+#    #+#             */
/*   Updated: 2014/05/04 00:35:19 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "libft.h"
# define FD_STD_OUT		1
# define FD_STD_ERR		2
# define NOT_ARROW		0
# define UP				1
# define DOWN			2
# define LEFT			3
# define RIGHT			4
typedef struct s_lst	t_lst;
struct					s_lst
{
	char				*str;
	int					select;
	t_lst				*next;
	t_lst				*prev;
};

typedef struct s_data	t_data;
struct					s_data
{
	char				bp[1024];
	char				read_char[5];
	t_lst				**list;
	t_lst				*cursor;
	int					row;
	int					col;
	int					len;
	int					nb_elt;
	int					nb_col;
	int					pos_x;
	int					pos_y;
	int					merge;
	int					center;
	int					i;
};
t_lst					*ft_new_elt(char *str);
void					ft_add_list_last(t_lst **list, t_lst *new);
void					ft_add_list_first(t_lst **list, t_lst *new);
int						ft_del_elt(t_lst **list, t_lst *elt, t_data *d);
t_lst					**get_lst(char **av, t_data *d);
int						ft_putchari(int c);
int						ft_putchar_output(int c);
void					ft_clear_screen(t_data *d);
void					*ft_get_data(void);
void					ft_get_winsize(t_data *d);
void					ft_print(t_data *d);
int						ft_position(t_data *d, t_lst *tmp);
void					ft_print_checked(t_data *d);
void					ft_error(char *msg);
void					ft_putstr_term(char *str);
int						is_space(char *buf);
int						is_enter(char *buf);
int						is_del(char *buf);
int						is_delete(char *buf);
int						is_esc(char *buf);
int						is_arrow(char *buf);
void					ft_sig_resize(void);
void					ft_sig_clear(void);
void					ft_sig_fg(void);
void					ft_sig_action(int s);
void					ft_getsig(void);
struct termios			*ft_get_init_conf(void);
void					ft_init(void);
void					ft_close(void);
#endif
