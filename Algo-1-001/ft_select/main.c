#include "libft/includes/libft.h"
#include "includes/ft_select.h"
#include <termios.h>
#include <termcap.h>
#include <stdlib.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	char				buffer[2048];
//	struct  termios		term;
//	t_env				s;
//	char				read_char[4] = {0};
//	int					i = 2;

	/* TEST SI TON TERM SUX PAS */
	if (tgetent(buffer, getenv("TERM")) < 1)
	{
		ft_putendl("Wrong term");
		return (-1);
	}
	else
	{
		/* TEST SI TU AS DES ARGS BATARD */
		if (argc > 1)
		{
			ft_select(argc, argv);
/*			tcgetattr(0, &term); // SI TU SAIS PAS VA VOIR LE MAN
			term.c_lflag ^= ICANON; // MODE CANONIQUE SI TU CAPTES PAS GOOGLE
			term.c_lflag ^= ECHO; // PAS D'ECHO SINON CA FAIT CHIER
			s.lines = argc - 1;
			s.count_lines = 0;
			tcsetattr(0, 0, &term); // ON DONNE LES VLEURS AUX ATTRIBUES MOD
			tputs(tgetstr("ti", NULL), 1, tputs_putchar); //ON OPEN CUP
			tputs(tgetstr("mr", NULL), 1, tputs_putchar); //ON SELECTION PAR MR
			ft_putendl(argv[1]);// ON AFFICHE ARGV[1] QUI SERA SOUS MR 
			tputs(tgetstr("me", NULL), 1, tputs_putchar);// ON STOP MR ICI
	//		tputs(tgetstr("do", NULL), 1, tputs_putchar);// ON SAUTE UNE LIGNE
			while (i < argc) // ON LISTE LES ARGS D'ARGV
			{
				ft_putstr(argv[i++]); // ON AFFICHE ARGV[i]
				if (i - 1 < argc)
					tputs(tgetstr("do", NULL), 1, tputs_putchar);// ON SAUTE UNE LIGNE
			}
			tputs(tgetstr("ho", NULL), 1, tputs_putchar);
			//tputs(tgetstr("up", NULL), 1, tputs_putchar);
			while (!(read_char[0] == 27 && read_char[1] == 0 && read_char[2] == 0) && s.lines > 0) // ON BOUCLE POUR LIRE TON CLAVIER
			{
				read_char[1] = 0; // ON INITALISE CHAQUE TOUCHE A 0 SAUF char[0] PUISQU'OSEF SINON BOUCLE FAIL
				read_char[2] = 0;
				read(0, read_char, 3); // ON FAIT AVANCER LA BOUCLE EN MODIFIER LES VALERS DE CHAR
//				printf(" Lol : %d %d %d\n", read_char[0], read_char[1], read_char[2]);
				if ((read_char[0] == 27 && read_char[1] == 91 && read_char[2] == 65))
				{
					tputs(tgetstr("up", NULL), 1, tputs_putchar);
				}
				if ((read_char[0] == 27 && read_char[1] == 91 && read_char[2] == 67))
					tputs(tgetstr("nd", NULL), 1, tputs_putchar);
				if ((read_char[0] == 27 && read_char[1] == 91 && read_char[2] == 68))
					tputs(tgetstr("le", NULL), 1, tputs_putchar);
				if ((read_char[0] == 27 && read_char[1] == 91 && read_char[2] == 66))
				{
					tputs(tgetstr("do", NULL), 1, tputs_putchar);
				}
				if (((read_char[0] == 126 || read_char[0] == 127)  && read_char[1] == 0 && read_char[2] == 0))
				{
					tputs(tgetstr("dl", NULL), 1, tputs_putchar);
					s.lines--;
				}
				ft_putendl("Appuie sur tout sauf 'echap' GROS FDP"); // TU SAIS LIRE ?
				oprintf("Tu as appuye sur la touche qui a pour char[0] = %d char[1] = %d char[2] = %d\n", read_char[0], read_char[1], read_char[2]); // ON AFFICHE LES VALEURS POUR CHAQUE TOUCHE CA PEUT SERVIR
				*/
/*			}
			tputs(tgetstr("te", NULL), 1, tputs_putchar);// ON FERME LA CUP ICI
			term.c_lflag ^= ICANON;
			term.c_lflag ^= ECHO;
			tcsetattr(0, 0, &term); // ON RESET EN GROS LE TERMINAL DE BASE*/
		}
		else
			ft_putendl("Wrong number of arguments"); // SI TU CAPTES PAS T UN GROS CON
	}
	return (0);
}

