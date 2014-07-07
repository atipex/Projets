#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void	fct(void)
{
	sleep(1);
	printf("Count ..\n");
}

void	sig(int sigint)
{
	struct winsize	mywin;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &mywin);
	printf("lignes : %d\n", mywin.ws_row);
	printf("colonnes : %d\n", mywin.ws_col);
}

int main (int argc, char **argv)
{
	while (1)
	{
		signal(SIGWINCH, &sig);
		fct();
	}
	return (0);
}

