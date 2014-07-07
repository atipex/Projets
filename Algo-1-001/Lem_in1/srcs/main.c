#include "lem_in.h"
#include <unistd.h>
#include <stdlib.h>

static void		ex(t_lab *lab, t_f *f)
{
	if (lab)
		lab_del(lab);
	if (f)
		del_f(f);
	exit(-1);
}

static void		startlol(t_f *f, t_lab *lab)
{
	if ((f = nb_f()) == NULL)
		ex(lab, f);
	if ((lab = build_lab(lab)) == NULL)
		ex(lab, f);
	if (error_start(lab) || error_end(lab))
		ex(lab, f);
	start_f(lab, f);
	if (solv_g(lab))
		ex(lab, f);
	solv(f);
	ex(lab, f);
}

int				main(void)
{
	t_f			*f;
	t_lab		*lab;

	lab = NULL;
	f = NULL;
	startlol(f, lab);
	return (0);
}

