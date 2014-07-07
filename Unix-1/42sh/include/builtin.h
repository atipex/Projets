#ifndef BUILTIN_H_
# define BUILTIN_H_

int	verif_var(t_cmd	*tmp);
int	is_there_a_star(char *word);
int	gimme_nb_arg(t_cmd *cmd);

int	ft_alias(t_cmd *cmd, t_data *data);
t_alias	*put_alias_in_list(t_alias *alias, char *name, char *cmd);
int	find_word(char *word, char *str);
void	check_loop(t_alias *name, t_alias *cmd, t_alias **root);

int	ft_cd(t_cmd *cmd, t_data *data);
int	dash_cd(t_data *data);
int	cd_path(t_cmd *cmd, t_data *data);
int	cd_home(t_data	*data);
int	new_env_pwd(t_data *data, char *path);

int	ft_echo(t_cmd *cmd, t_data *data);
void	check_option(t_cmd *tmp);

int	ft_env(t_cmd *cmd, t_data *data);

int	ft_exit(t_cmd *cmd, t_data *data);

int	ft_history(t_cmd *cmd, t_data *data);
void	history_dash_c(t_data *data);
void	aff_history(t_data *data);

int	ft_set(t_cmd *cmd, t_data *data);
int	create_var(t_cmd *tmp, t_var *var);
int	update_var(t_cmd *tmp, t_var *exist);
void	aff_var(t_var	*var);

int	ft_setenv(t_cmd *cmd, t_data *data);
int	add_to_env_glob(t_cmd *cmd, t_env *env);
int	add_to_env(t_cmd *cmd, t_env *env);
t_env	*find_var(t_env *env, char *var);

int	ft_unset(t_cmd *cmd, t_data *data);
void	remove_var_builtin(t_var *exist);
t_var	*already_exist_var(t_cmd *tmp, t_var *var);

int	remove_var(char *var_name, t_env *env);
int	option_star(t_data *data);
int	ft_unsetenv(t_cmd *cmd, t_data *data);

int	ft_exe_sh(char *file, t_data *data);

int	ft_unalias(t_cmd *cmd, t_data *data);
void	put_alias_off_list(t_alias **alias, t_alias *focus);

#endif
