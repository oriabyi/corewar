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
	while (i < 15000 && core->cycle_to_die > 0)
	{
		if (!core->flags.visual && i == core->flags.dump)
		{
			print_memory(core);
			break ;
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
		if (core->flags.a_visual)
		{
			write(1, "It is now cycle ", 16);
			ft_putnbr_fd(i, 1);
			write(1, "\n", 1);
		}

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
	game(&core);
	clean_all(&core);
//	system("leaks -q corewar");
	return (0);
}
