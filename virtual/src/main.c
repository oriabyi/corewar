#include "../includes/corewar_header.h"
#include "stdio.h"

//codage - считываем ли мы первое число после команды

int				reveal_memory_space(t_corewar *core, int cycle);

static void			oversight_key(t_corewar *core)
{
	uint64_t		key_code;

	key_code = 0;
	read(1, &key_code, 8);

	if (key_code == ESC)
		exit_message(core, EXIT_COMMAND, "Corewar is closed!\n");
	// bonuses need to do
}


void			game(t_corewar *core) // delete flag
{
	int 		i;
	int 		flag = 0;

	vs_init(core);
	if (core->flags.visual)
	{
		ft_putstr_fd("VISUAL ON!\n", 2);
		vs_start(core);
	}
	i = 1;
	while (i)
	{
//		if (bigmother == 50)
//			flag = 1;
		if (core->flags.visual)
		{
			draw(core, i);
			if (!core->flags.visual) // TODO: clean_all && exit?
				vs_end(core);
		}


		if (!core->ncur.pause)
		{
			flag = do_process(core, core->qua_bots);
			bigmother++;
			i++;
		}
//		oversight_key(core);
	}
	if (core->flags.visual)
		vs_end(core);

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
