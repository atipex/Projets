/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrebours <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 11:49:43 by mrebours            #+#    #+#             */
/*   Updated: 2014/04/19 12:15:17 by mrebours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft.h"
# include <sys/stat.h>
typedef struct stat		t_strlol;
typedef struct s_option	t_option;
struct					s_option
{
	char				rec;
	char				l;
	char				a;
	char				r;
	char				t;
	char				end;
};
typedef struct s_data	t_data;
struct					s_data
{
	t_strlol			*stat;
	char				*path;
};

typedef struct s_list	t_list;
struct					s_list
{
	void				*content;
	size_t				content_size;
	t_list				*next;
};

void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_parse(char *str, t_option *opt, t_list **files);
void					ft_parse_opt(char *str, t_option *opt);
int						ft_is_endopt(char *str, t_option *opt);
void					ft_enable_opt(char *str, t_option *opt);
void					ft_list_files(char *str, t_list **files);
void					ft_lstdir(t_list **lst, t_option *opt, char *path);
void					ft_init_opt(t_option *opt);
void					ft_lstswap(t_list *elem1, t_list *elem2);
void					ft_lstsort_asc(t_list *files);
void					ft_lststat(t_list *elem);
char					*ft_strfjoin(char *str1, char *str2);
void					ft_printfiles(t_list *file, t_option *opt);
void					ft_lstsort_time(t_list *file);
void					ft_printl(t_data *data);
void					ft_printdir(t_list *lst, t_option *opt);
void					ft_printlst(t_list *file, t_option *opt);
void					ft_callsort(t_list *files, t_option *opt);
void					ft_changepath(t_list *elem);
#endif
