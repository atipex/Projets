
#include "corewar.h"

t_charu		*new_add(t_charu *w, t_charu *a)
{
	t_charu		*new;

	new = w;
	if ((long)new >= (long)a + MEM_SIZE)
	{
		new = (t_charu *)((long)new - (long)a);
		new = (t_charu *)((long)new % (long)MEM_SIZE);
		new = (t_charu *)((long)new + (long)a);
	}
	else if ((long)new < (long)a)
	{
		new = (t_charu *)((long)new % (long)MEM_SIZE);
		new = (t_charu *)((long)new + (long)a);
	}
	return (new);
}

int		giv_reg_nbr(int reg)
{
	reg -= 1;
	reg = ((reg >= 0) ? reg : -reg);
	reg = reg % REG_NUMBER;
	return (reg);
}

int		giv_para_val(t_chp *chp, t_cmd *cmd, int arg, t_charu *a)
{
	int			i;
	int			place;
	t_charu		*tmp;

	i = 0;
	place = 0;
	while (i < arg)
		place += cmd->type_args[i++];
	if (cmd->type_args[arg] == 1)
		return (cmd->args[place]);
	else if (cmd->type_args[arg] == 4)
		return (convert_int(cmd->args + place, cmd->type_args[arg]));
	else
	{
		i = convert_int(cmd->args + place, cmd->type_args[arg]);
		if (cmd->fct > 12)
			tmp = chp->PC + i;
		else
			tmp = chp->PC + (i % IDX_MOD);
		tmp = new_add(tmp, a);
		return (convert_int_instr(tmp, 4, a));
	}
}

