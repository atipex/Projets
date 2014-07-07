#ifndef COMMAND_H_
# define COMMAND_H_

typedef struct	s_char
{
  int		value;
  int		(*fct_ptr)(char buf[3], char **, int *, t_data *);
}		t_char;

int	aff_path(char *word);
int	aff_bin(char *word, t_data *data);
int	aff_current_directory(void);

int	aff_pglob(glob_t *pglob);
int	check_nbr_aff(glob_t *pglob);
void	aff_beautiful_pglob(glob_t *pglob, t_win_size *win_size);
int	gimme_max_cols(char **path, int nb);
int	remove_path_name(char *str);

int	auto_completation(char buf[3], char **cmd, int *i, t_data *data);
char	*gimme_last_word(char *cmd);
int	gimme_nbr_words(char *cmd);
char	*gimme_last_cmd_bloc(char *cmd);

t_cmd	*gimme_cmd_data(char *command);
t_cmd	*add_to_list(t_cmd *cmd_data, char *word);
t_cmd	*init_cmd_data(void);

char	*gimme_command(t_data *data, t_bool tty);
void	reset_pos(t_data *data);
int	raw_mode(void);
int	exit_raw_mode(void);

void	history_prompt(char buf[3], int *i, char **cmd, t_data *data);
void	aff_nicely(t_his *tmp, char **cmd, int *i);

int	replace_var(t_cmd *cmd, t_data *data);
int	replace_tild(t_cmd *tmp, t_env *env, char *home);
int	find_and_replace(t_cmd *tmp, t_env *env, t_var *var);
int	find_and_replace_var(t_cmd *tmp, t_var *var, int len);
int	replace_cmd(t_cmd *tmp, t_his *tmp_his, t_his *his, t_cmd *replace);

int	replace_history(t_cmd *tmp, t_his *his);
int	last_event(t_cmd *tmp, t_his *his);
int	find_by_name(t_cmd *tmp, t_his *his);
int	find_by_num(t_cmd *tmp, t_his *his);
int	find_by_num_reverse(t_cmd *tmp, t_his *his);

t_cmd	*str_to_linked_list(char *str, t_cmd *cmd);
int	manage_quote(char *str, t_cmd *cmd, int i);
int	manage_other(char *str, t_cmd *cmd, int i);
int	manage_double_quote(char *str, t_cmd *cmd, int i);
int	manage_space_and_tab(char *str, int i);

int	check_cmd(char buf[3], char **cmd, int *i, t_data *data);
int	check_for_realloc(char **cmd, int size);
char	*termcaps_prompt(t_data *data);

int	check_arrow(char buf[3], char **cmd, int *i, t_data *data);
int	ctrl_termcaps(char buf[3], char **cmd, int *i, t_data *data);
int	backspace_termcaps(char buf[3], char **cmd, int *i, t_data *data);
int	add_char(char buf[3], char **cmd, int *i, t_data *data);

int	auto_complete(glob_t *pglob);
int	find_word_complete(glob_t *pglob, char *prompt);
int	add_to_cmd(char *result);

#endif
