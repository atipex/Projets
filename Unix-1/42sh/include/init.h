#ifndef INIT_H_
# define INIT_H_

char	*gimme_home(t_env *env);
char	*gimme_cd_path(t_cmd *cmd, t_data *data);
void	swap_char(char **old_pwd, char **pwd);

int	init_term(char **env);
char	*gimme_pwd(char **env);
t_data	*init(char **env, t_bool *tty);
int	save_fd(t_data *data);

t_env	*gimme_root(void);
t_env	*put_in_list(t_env *root, char *param);
t_env	*gimme_env(char **env);

char	*search_path(char **env);
int	count_path(char *path);
int	ft_strlen_path(char *path);
char	**cpy_path(char *path_line);
char	**gimme_path(char **env);

#endif
