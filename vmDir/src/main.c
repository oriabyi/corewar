# include "../includes/corewar_header.h"

void 			init_core(t_corewar *core)
{
	core->field = NULL;
	core->champs = NULL;
	core->flags = (t_flags){0, 0};
	core->cycle_to_die = CYCLE_TO_DIE;
	core->max_checks = 0;
	core->qua_champs = 0;
	core->qua_lives = 0;
	core->quant_carriages = 0;
	core->last_live = 0;
	core->carriage = NULL;
	core->cycles = 0;
	core->arguments = (t_args){0, 0, 0, 0};
}


int				submain(int ac, char **av)
{
	int 		check_code;
	t_corewar	core;

	init_core(&core);
	check_code = check_availability_flags(&core.flags, ac, av);
	if ((check_code || (check_code = parse(&core, av))) ||
		(check_code = visual_init(&core)))
	{
		return (check_correctness(&core, check_code));
	}
	init_instructions((t_instructions *)&core.instructions);
	war_loop(&core);
	reset_game(&core);
	clean_all(&core);
	return (0);
}

int main(int ac, char **av)
{
	submain(ac, av);
	system("leaks corewar");
	return (0);
}
