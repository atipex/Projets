#include "libft/includes/libft.h"
#include "includes/ft_select.h"
#include <termios.h>
#include <termcap.h>
#include <unistd.h>
#include <stdio.h>

static void	ft_show(int n);

int		ft_select(int argc, char **argv)
{
	struct termios	term;
	int				i;
	t_env			s;

	i = 2;
	s.lines = argc - 1;
	s.count_lines = 0;
	tcgetattr(0, &term);
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(0, 0, &term);
	tputs(tgetstr("ti", NULL), 1, tputs_putchar);
	ft_putstr(argv[1]);
	tputs(tgetstr("do", NULL), 1, tputs_putchar);
	while(i < argc)
	{
		ft_putstr(argv[i++]);
		if (i - 1 < argc)
			tputs(tgetstr("do", NULL), 1, tputs_putchar);
	}
	tputs(tgetstr("ho", NULL), 1, tputs_putchar);
	tputs(tgetstr("vs", NULL), 1, tputs_putchar);
	ft_show(s.lines);
	tputs(tgetstr("ve", NULL), 1, tputs_putchar);
	tputs(tgetstr("te", NULL), 1, tputs_putchar);
	term.c_lflag |= ICANON;
	term.c_lflag |= ECHO;
	tcsetattr(0, 0, &term);
	return (0);
}

static void	ft_show(int		n)
{
	char	nc[4];
	t_env	s;

	while (!(nc[0] == 27 && nc[1] == 0 && nc[2] == 0) && n > 0)
	{
		tputs(tgetstr("uc", NULL), 1, tputs_putchar);
		nc[1] = 0;
		nc[2] = 0;
		read(0, nc, 3);
		if ((nc[0] == 27 && nc[1] == 91 && nc[2] == 65))
			tputs(tgetstr("up", NULL), 1, tputs_putchar);
		if ((nc[0] == 27 && nc[1] == 91 && nc[2] == 68))
			tputs(tgetstr("le", NULL), 1, tputs_putchar);
		if ((nc[0] == 27 && nc[1] == 91 && nc[2] == 67))
			tputs(tgetstr("nd", NULL), 1, tputs_putchar);
		if ((nc[0] == 27 && nc[1] == 91 && nc[2] == 66))
			tputs(tgetstr("do", NULL), 1, tputs_putchar);
		if (((nc[0] == 127 || nc[0] == 126) && nc[1] == 0 && nc[2] == 0))
		{
			tputs(tgetstr("dl", NULL), 1, tputs_putchar);
			n--;
		}
	}
}

