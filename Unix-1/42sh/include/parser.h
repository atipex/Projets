#ifndef PARSER_H_
# define PARSER_H_

# define PIPE			"|"
# define REDI_RIGHT		">"
# define REDI_D_RIGHT		">>"
# define REDI_LEFT		"<"
# define REDI_D_LEFT		"<<"
# define AND			"&&"
# define OR			"||"
# define CMD_SEP		";"
# define BGROUND		"&"

# define TYPE_PIPE	1
# define TYPE_RIGHT	2
# define TYPE_D_RIGHT	3
# define TYPE_LEFT	4
# define TYPE_D_LEFT	5
# define TYPE_AND	6
# define TYPE_OR	7
# define TYPE_CMD_SEP	8
# define TYPE_CMD	9
# define TYPE_ARG	10
# define TYPE_REDI_ARG	11
# define TYPE_BGROUND	12

typedef struct	s_identify
{
  char		*name;
  int		type;
}		t_identify;

struct	s_tree;
struct	s_param;

typedef struct		s_tree
{
  int			type;
  struct s_param	*param;
}			t_tree;

typedef struct		s_param
{
  struct s_cmd		*cmd;
  struct s_tree		*tree;
  struct s_param	*next;
  struct s_param	*prev;
}			t_param;

char	*add_some_space(char *command);
void	its_time_to_add_the_spaces(char *command, char *new_command);
int	gimme_nbr_sep(char *command);

int	check_redi_pipe(t_cmd *cmd);
int	check_null_cmd(t_cmd *cmd);
int	check_nbr_cmd(int nb_cmd, int previous, t_cmd **tmp, t_cmd *cmd);

int	new_tree(t_cmd **cmd, t_param *param, int *j);
int	add_param(t_tree *tree, t_cmd *cmd);
t_tree	*init_cmd_tree(int type);

void	lexer(t_cmd *cmd_data);

int	is_a_redi(t_cmd *root, t_cmd **cmd);
int	get_basic_cmd(t_cmd *root, t_cmd *cmd);
int	get_cmd(t_cmd *root, t_cmd *cmd);
int	parser(t_cmd *cmd);

void	init_redi(int redi[4]);
void	stock_redi(int redi[4], t_cmd *tmp);
int	check_and_verif_redi_pipe(int *start, int redi[4],
				  t_cmd *tmp, t_cmd *cmd);
t_cmd	*verif_redi_pipe(t_cmd *cmd, t_cmd *tmp);

void	clean_tree(t_tree *tree);
int	check_tree_or_cmd(t_param *param, int i);
int	clean_cmd(t_param *param, t_cmd *cmd, int i);
int	cut_cmd(t_tree *tree, t_cmd *cmd, int type);
t_tree	*gimme_tree(t_cmd *cmd_data);

#endif
