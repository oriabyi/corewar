#include "../includes/corewar_header.h"

void			game(t_corewar *core)
{
	unsigned 		i;
	core->cycle_to_die = CYCLE_TO_DIE;
	core->max_checks = 0;

	visual_init(core);
	if (core->flags.visual)
	{
		visual_start(core);
		display_windows(core, 1);
	}
	i = 1;
	while (i < 15000)
	{
		if (!core->flags.visual && i == core->flags.dump)
		{
			print_memory(core);
			exit_message(core, 0, NULL);
		}
		if (i && core->cycle_to_die && i % core->cycle_to_die == 0)
			core->cycle_to_die = check_cycle_to_die(core);


		if (i >= core->flags.dump && core->flags.visual)
		{
			i = (unsigned)draw(core, i);
		}
		else
		{
			i++;
		}
		do_process(core, core->qua_bots);
		bigmother++;
	}
	if (core->flags.visual)
		visual_end(core);

}


int				main(int ac, char **av)
{
	t_corewar	core;

	bigmother = 0;
	core = (t_corewar){NULL, 0};
	check_arguments(&core.flags, ac, av);

	parse(&core, av);
//	if (core.flags.visual)
		game(&core);
//	else
//		printf("novs\n");
	clean_all(&core);
    return (0);
}
