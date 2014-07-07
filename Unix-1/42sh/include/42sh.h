#ifndef SHELL_H_
# define SHELL_H_

# include <glob.h>
# define SIZE_MALLOC	1024
# define BACKSPACE	127
# define ARROW		27
# define LEFT		68
# define RIGHT		67
# define UP		65
# define DOWN		66
# define CTRLC		3
# define CTRLD		4
# define CTRLL		12
# define TAB		'\t'

int	g_exit_value;
int	g_last_exit;
int	g_tty;

typedef struct	s_win_size
{
  int		cols;
  int		max_cols;
  int		current_cols;
  int		current_line_cols;
}		t_win_size;

typedef struct	s_env
{
  struct s_env	*next;
  struct s_env	*prev;
  char		*var;
  char		*content;
  int		pos;
  int		num;
}		t_env;

typedef t_env	t_his;
typedef t_env	t_var;

typedef char	t_bool;

typedef struct		s_alias
{
  char			*name;
  char			*cmd;
  struct s_alias	*next;
}			t_alias;

typedef struct	s_data
{
  int		pipe;
  int		save_fd[2];
  t_his		*his;
  t_env		*env;
  t_var		*var;
  char		**path;
  char		*pwd;
  char		*old_pwd;
  char		**options;
  char		*home;
  t_alias	*alias;
}		t_data;

typedef struct	s_cmd
{
  char		*word;
  int		type;
  struct s_cmd	*next;
  struct s_cmd	*prev;
}		t_cmd;

typedef struct	s_prompt
{
  int		i;
  int		size;
  char		*cmd;
}		t_prompt;

t_prompt	g_prompt;

# include "init.h"
# include "command.h"
# include "builtin.h"
# include "parser.h"
# include "functs.h"
# include "exec.h"

void	gere_signal(int sig);
int	create_and_exec(char *command, t_data *data);
int	ftsh(t_data *data, t_bool tty);

#endif
