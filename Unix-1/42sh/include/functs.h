#ifndef FUNCTS_H_
# define FUNCTS_H_

void	remove_elem(t_cmd *elem);

void	init_buf(char buf[3]);
char	*ft_strndup(char *str, int n);
char	*ft_malloc(int size);
char	*ft_realloc(char *cmd, int size);
void	aff_prompt(void);

int	ft_error(char *error);
void	*ft_error_ptr(char *error);
int	ft_error_parse(char *error);

void	free_command(char *command, t_cmd *cmd_data);
void	free_cmd(t_cmd *cmd);
void	free_tree(t_tree *tree);
void	free_data(t_data *data);

#endif
