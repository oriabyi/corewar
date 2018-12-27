#include "../includes/corewar_header.h"

char			*pull_out_champs_info(t_corewar *core);

void 			get_game_type(t_corewar *core)
{
	if (F_VISUAL)
	{
		visual_start(core);
		display_windows(core, 1);
	}
	else if (F_DUMP)
	{
		ft_putstr(pull_out_champs_info(core));
	}
}

void			war(t_corewar *core)
{
	unsigned 	cycles_limit;

	cycles_limit = (unsigned)core->cycle_to_die;
	core->cycles = 0;
	get_game_type(core);
//	bigmother say powel nahuy
	while (1)
	{
		if (F_VISUAL == false && core->cycles && core->cycles == F_DUMP)
		{
			print_memory(core);
			break ;
		}
		if (core->cycles >= F_DUMP && F_VISUAL)
			core->cycles = (unsigned)draw(core, core->cycles, &cycles_limit);
		else
			core->cycles++;
		bigmother = core->cycles;
		do_process(core);
		if (core->cycles == cycles_limit)
		{
			core->cycle_to_die = check_cycle_to_die(core);
			cycles_limit = core->cycles + core->cycle_to_die;
		}
		if (core->cycle_to_die <= 0 || core->carriage == NULL)
		{
			if (F_VISUAL)
			{
				int old_cycles = core->cycles;
				NCUR.pause = 1;
				core->cycles = (unsigned) draw(core, core->cycles, &cycles_limit);
				if (core->cycles >= old_cycles)
					break;
				continue;
			}
			break ;
		}
	}

//	char *temp = ft_multjoin(3, "Contestant 2, \"", core->champs[core->last_live].name, "\", has won !\n");
//	ft_putstr(temp);
//	free(temp);

	if (F_VISUAL)
		visual_end(core);
}

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

	bigmother = 0;
	init_core(&core);
	check_code = check_availability_flags(&core.flags, ac, av);
	if ((check_code || (check_code = parse(&core, av))) ||
		(check_code = visual_init(&core)))
	{
		return (check_correctness(&core, check_code));
	}
	init_instructions((t_instructions *)&core.instructions);
	war(&core);
	reset_game(&core);
	clean_all(&core);
//	printf("bigmother = %d\n", bigmother);
	return (0);
}

int main(int ac, char **av)
{
	return (submain(ac, av));
}
