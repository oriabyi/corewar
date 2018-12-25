#include "../includes/corewar_header.h"

unsigned 			how_many_champs_alive(t_corewar *core)
{
	int 		counter;
	unsigned 	lives;

	counter = 0;
	lives = 0;
	while (counter < core->qua_champs)
	{
		if (core->champs[counter].alive != CHAMP_IS_DEAD)
			lives++;
		counter++;
	}
	return (lives);
}

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
	unsigned 	cycles;
	unsigned 	cycles_limit;

	cycles_limit = (unsigned)core->cycle_to_die;
	cycles = 0;
	get_game_type(core);
	while (core->cycle_to_die > 0)
	{

		if (F_VISUAL == false && cycles && cycles == F_DUMP)
		{
			print_memory(core);
			break ;
		}

		if (cycles >= F_DUMP && F_VISUAL)
			cycles = (unsigned)draw(core, cycles);
		else
			cycles++;
		do_process(core);
		bigmother++;
		if (cycles == cycles_limit)
		{
			core->cycle_to_die = check_cycle_to_die(core);
			if (how_many_champs_alive(core) == 0)
				break ;
			cycles_limit = cycles + core->cycle_to_die;
		}
	}
	char *temp = ft_multjoin(3, "Contestant 2, \"", core->champs[core->last_live - 1].name, "\", has won !\n");
	ft_putstr(temp);
	free(temp);

	if (F_VISUAL)
		visual_end(core);
}

void 			init_core(t_corewar *core)
{
	core->field = NULL;
	core->ncur = (t_ncurses){0, {0, 0}, {0, 0}, 0, 0, 0, 0};
	ft_bzero(core->ncur.cycle_to_go, 7);
	ft_bzero(core->ncur.champ_id, 7);
	ft_bzero(core->ncur.carriage_id, 7);
	core->ncur.current_field = NULL;
	core->ncur.memory_window = NULL;
	core->ncur.score_window = NULL;
	core->champs = NULL;
	core->flags = (t_flags){0, 0};
	core->cycle_to_die = CYCLE_TO_DIE;
	core->max_checks = 0;
	core->qua_champs = 0;
	core->qua_lives = 0;
	core->quant_carriages = 0;
	core->last_live = 0;
	core->carriage = NULL;
	core->arguments = (t_args){0, {0, 0, 0}, 0, 0, 0};
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
	war(&core);
	clean_all(&core);
//	printf("bigmother = %d\n", bigmother);
	return (0);
}

int main(int ac, char **av)
{
	submain(ac, av);
	system("leaks -q Corewar");
	return(0);
}
