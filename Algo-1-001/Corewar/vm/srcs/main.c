#include "corewar.h"

void	corewar(int argc, char **argv)
{
	int			d;
	t_charu		*arena;
	t_cycle		*cycles;
	t_chp		*chp;

	g_pid = 5;
	g_winner_id = 0;
	g_winner_name = NULL;
	arena = init_arena();
	cycles = init_cycle();
	d = check_cmd(argc, argv);
	chp = mchp(argc, argv, arena);
	battle_start(d, arena, chp, cycles);
}

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		check_def();
		corewar(argc, argv);
	}
	else
	{
		ft_putstr_fd("./corewar [-dumb nbr-cycle] ", 2);
		ft_putendl_fd("[[-n prog_number] [-a lad address] [prog_name]]", 2);
	}
	return (0);
}

