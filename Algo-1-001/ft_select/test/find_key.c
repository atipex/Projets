#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <term.h>
static char term_buffer[2048];
#define term_buffer 0
int		my_outc(int c);
int		main(/*int ac, char **av, char **env*/void)
{
	char *tt = getenv("TERM");
	int		succes;
	char	*res;
	char	*te;
	char	buffer[30];
	char	*ap = buffer;
	struct termios term;

	if (tt == 0)
		printf("Fail\n");
	succes = tgetent(term_buffer, tt);
	if (succes < 0)
		printf("Fail \n");
	if (succes == 0)
		printf("TypeTerm : %s no reconnu",tt);
	else /* SUCCES == 1 */
		printf("TypeTerm: %s", tt);
//	try();
//	Cl = clear screen;
	if ((res = tgetstr("so", &ap)) == NULL)
			return (-1);
	tputs(res, 1, my_outc);/*
	res = xtgetstr("cm", &area);
	tputs(tgoto(res, 100, 100), 1, my_outc);*/
	return (0);
}

int		my_outc(int c)
{
	putchar(c);
	return (0);
}

int		try(void)
{
	char buffer[3];

	while (1)
	{
		read(0, buffer, 3);
		if (buffer[0] == 27)
			printf("C'est une fleche : Buffer: %d %d\n", buffer[0],buffer[1]);
		else{
			printf("Buffer = %d\n", buffer[0]);
		}
	}
	return (0);
}
