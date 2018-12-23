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
	unsigned 	cycles;

	cycles = 0;
	core->cycle_to_die = CYCLE_TO_DIE;
	core->max_checks = 0;
	visual_init(core);
	if (F_VISUAL)
	{
		visual_start(core);
		display_windows(core, 1);
	}
	while (core->cycle_to_die > 0 && is_anychamp_alive(core->champs, core->qua_champs))
	{
		if (F_VISUAL == false && cycles == F_DUMP)
		{
			print_memory(core);
			break ;
		}
		if (cycles && core->cycle_to_die && cycles % core->cycle_to_die == 0)
			core->cycle_to_die = check_cycle_to_die(core);


		if (cycles >= F_DUMP && F_VISUAL)
		{
			cycles = (unsigned)draw(core, cycles);
		}
		else
		{
			cycles++;
		}

		do_process(core, core->qua_champs);

		bigmother++;
	}
	if (F_VISUAL)
		visual_end(core);

}

void 			reset_core(t_corewar *core)
{
	*core->field = (t_field){'\0', {'\0', '\0', '\0'}, 0, 0, 0, 0};
	core->ncur = (t_ncurses){0, {0, 0}, {0, 0}, 0, 0, 0, 0};
	ft_bzero(core->ncur.cycle_to_go, 7);
	ft_bzero(core->ncur.champ_id, 7);
	ft_bzero(core->ncur.carriage_id, 7);
	core->ncur.current_field = NULL;
	core->ncur.memory_window = NULL;
	core->ncur.score_window = NULL;
	core->champs = NULL;
	core->flags = (t_flags){0, 0, 0, 0, 0};
	core->cycle_to_die = 0;
	core->max_checks = 0;
	core->qua_champs = 0;
}

int				main(int ac, char **av)
{
	t_corewar	core;

	bigmother = 0;
	reset_core(&core);
	check_arguments(&core.flags, ac, av);
	parse(&core, av);
	war(&core);
	clean_all(&core);
//	system("leaks -q corewar");
	return (0);
}
