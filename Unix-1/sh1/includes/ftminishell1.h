#ifndef FTMINISHELL1_H
# define FTMINISHELL1_H
# include "libft.h"

typedef struct		s_list		t_list;

struct				s_list
{
	char			*key_word;
	char			*value;
	t_list			*prev;
	t_list			*next;
};

int				main(int ac, char **av, char **environ);
void			ft_minishell(char **environ, t_list *obj);
t_list			*fill_obj(t_list *obj_old, char *environ);
t_list			*start_obj(t_list *obj);
char			*ft_prompt(t_list *obj);
char			*ft_username(t_list *obj);
char			*check_wd(char *wd, t_list *obj);
char			*ft_wd(t_list *obj);
void			ft_minishell_2(t_list *obj, char *prompt, char *cmd);
char			**ft_array_internal(void);
int				test_internal(char *cmd);
char			*ret_path(t_list *obj);
char			**recup_path(t_list *obj);
void			verif_ext_com(t_list *obj, char **comm);
void			verif_ext_com_2(t_list *obj, char **comm);
char			*select_path(t_list *obj, char *comm);
t_list			*verif_b_in_cmd(t_list *obj, char **split_cmd);
void			ft_print_env(t_list *obj);
t_list			*ft_setenv(t_list *obj, char **cmd);
t_list			*ft_bzero_env(t_list *obj, char **cmd);
t_list			*new_ins_ev(t_list *obj, char **cmd);
t_list			*ft_unsetenv(t_list *obj, char **cmd);
t_list			*ft_lets_unsetenv(t_list *obj, char *cmd);
t_list			*ft_del_one_env(t_list *obj);
t_list			*ft_cd(t_list *obj, char **cmd);
t_list			*ft_cd_home(t_list *obj, char *dest);
t_list			*search_in_obj(t_list *obj, char *srch);
t_list			*ft_cd_dir(t_list *obj, char *cmd);
t_list			*ft_cd_change(t_list *obj, char *cmd);
char			*pure_wd(char *direc);
char			*check_tilde(char *cmd, t_list *obj);
void			ctrl_c(int i);
t_list			*ft_env(t_list *obj, char **cmd);
char			**cl_to_tab(t_list *obj);
void			ft_exit(char **cmd);
void			ft_print_tmp_env(char **ev);
t_list			*ft_cd_reverse(t_list *obj);
#endif
