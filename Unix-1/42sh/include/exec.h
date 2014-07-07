
#ifndef EXEC_H_
# define EXEC_H_

typedef struct	s_builtin
{
  char		*name;
  int		(*fct_builtin)(t_cmd *, t_data *);
}		t_builtin;

typedef struct	s_exec
{
  int		type;
  int		(*fct)(t_tree *, t_param *, t_data *);
}		t_exec;

int	back_ground(t_cmd *cmd, t_data *data);

int	exe_alias(t_alias *alias, t_cmd *cmd, t_data *data);
int	exe_cmd(t_cmd *cmd, t_data *data);

int	exec_tree(t_tree *tree, t_data *data);
int	should_i_exec_other_cmd(t_tree *tree, t_param *param, t_data *data);
int	find_redi_and_exec(t_cmd *cmd, t_data *data);
void	remove_redi(t_cmd *cmd);

int	pipe_exec(t_tree *tree, t_param *param, t_data *data);
int	or_exec(t_tree *tree, t_param *param, t_data *data);
int	and_exec(t_tree *tree, t_param *param, t_data *data);

char	*globing_for_setenv(t_cmd *cmd);
int	globing_for_echo(t_cmd *cmd);
char	*globing_for_cd(t_cmd *cmd);
t_cmd	*globing(t_cmd *tmp);

int	ft_exec(t_cmd *cmd, t_data *data);
int	exec_path(char **cmd_tab, char	**env_tab, t_data *data);
int	father_exec(int pid, t_data *data);

char	**cmd_in_tab(t_cmd *cmd);
char	**env_in_tab(t_env *env);
char	*gimme_good_path(char *cmd, t_data *data, char **env_tab);

int	mid_pipe(int pipe_fd[2][2], int *k, t_data *data);
int	end_pipe(int pipe_fd[2][2], int *k, t_data *data);
int	start_pipe(int pipe_fd[2][2], int *k, t_data *data);
void	pipe_exit(t_tree *tree, t_param *param);

int	redi_right(char *file, t_data *data);
int	redi_d_right(char *file, t_data *data);
int	redi_left(char *file, t_data *data);
int	redi_d_left(char *key_word, t_data *data);
int	write_and_read_redi_d_left(char *buffer);

#endif
