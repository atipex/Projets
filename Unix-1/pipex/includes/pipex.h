
#ifndef PIPEX_H
# define PIPEX_H
# include <string.h>

typedef struct	s_struct
{
	char		**file1;
	char		**file2;
	char		**cmd1;
	char		**cmd2;
}				t_struct;

int				main(int ac, char **av, char **env);
void			ft_putendl_fd(char const *s, int fd);
void			fill_and_check(char **av, char **env);
void			init_fill_obj(t_struct *obj, char **av);
char			**ft_strsplit(char const *s, char c);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *str);
char			*ft_strnew(size_t size);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			check_file2(char **file2);
void			check_cmd1(t_struct *obj, char **path);
void			check_file1(char **file1);
void			check_cmd2(t_struct *obj, char **path);
void			pipex(t_struct obj, char **env);
void			creat_tab_1(t_struct *obj);
void			err_cmd(char *cmd, char *msg);
char			*where_is_the_cat(char **env);
void			no_path(void);
void			pipex2(int *pfd, t_struct obj, char **env);
void			pipex3(int *pfda, int *pfd, t_struct obj, char **env);
#endif
