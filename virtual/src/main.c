#include "../includes/corewar_header.h"

int 			is_anychamp_alive(t_champ *champs, unsigned qua_champs)
{
	int 		counter;

	counter = 0;
	while (counter < qua_champs)
	{
		if (champs[counter].carriage)
			return (1);
		counter++;
	}
	return (0);
}

void			war(t_corewar *core)
{
	unsigned 		i;
	core->cycle_to_die = CYCLE_TO_DIE;
	core->max_checks = 0;

	visual_init(core);
	if (F_VISUAL)
	{
		visual_start(core);
		display_windows(core, 1);
	}
	i = 1;
	while (i < 150000 && core->cycle_to_die > 0 && is_anychamp_alive(core->champs, core->qua_champs))
	{
		if (F_VISUAL == false && i == F_DUMP)
		{
			print_memory(core);
			break ;
		}
		if (i && core->cycle_to_die && i % core->cycle_to_die == 0)
			core->cycle_to_die = check_cycle_to_die(core);


		if (i >= F_DUMP && F_VISUAL)
		{
			i = (unsigned)draw(core, i);
		}
		else
		{
			i++;
		}

		do_process(core, core->qua_champs);

		bigmother++;
	}
	if (F_VISUAL)
		visual_end(core);

}


int				main(int ac, char **av)
{
	t_corewar	core;

	bigmother = 0;
	core = (t_corewar){NULL, 0};
	check_arguments(&core.flags, ac, av);

	parse(&core, av);
	war(&core);
	clean_all(&core);
//	system("leaks -q corewar");
	return (0);
}
