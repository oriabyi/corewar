#include "../../includes/corewar_header.h"

void 			get_game_type(t_corewar *core)
{
	if (F_VISUAL)
	{
		visual_start(core);
		display_windows(core, 1);
	}
	else
	{
		ft_putstr(pull_out_champs_info(core));
	}
}

void 			print_winner(t_corewar *core)
{
	char *temp;

	temp = ft_multjoinfr(6, "Contestant " , NULL,
			ft_itoa(core->champs[core->last_live].id) ,", \"",
			core->champs[core->last_live].name, "\", has won !\n");
	ft_putstr(temp);
	free(temp);
}

int 			game_over(t_corewar *core, unsigned *cycles_limit)
{
	int			old_cycles;

	if (F_VISUAL)
	{
		old_cycles = core->cycles;
		NCUR.pause = 1;
		core->cycles = (unsigned) draw(core, core->cycles, cycles_limit);
		if (core->cycles >= old_cycles)
			return (STOP_GAME);
		return (CONTINUE_GAME);
	}
	return (STOP_GAME);
}

int 			war_step(t_corewar *core, unsigned *cycles_limit)
{
	if (F_VISUAL == false && core->cycles && core->cycles == F_DUMP)
	{
		print_memory(core);
		return (STOP_GAME);
	}
	if (core->cycles >= F_DUMP && F_VISUAL)
	{
		core->cycles = (unsigned)draw(core, core->cycles, cycles_limit);
		if (!core->cycles)
			return (CONTINUE_GAME);
		else if (core->cycles == -1)
			return (STOP_GAME);
	}
	else
		core->cycles++;
	do_process(core);
	if (core->cycles == *cycles_limit)
	{
		core->cycle_to_die = check_cycle_to_die(core);
		*cycles_limit = core->cycles + core->cycle_to_die;
	}
	if (core->cycle_to_die <= 0 || core->carriage == NULL)
		return (game_over(core, cycles_limit));
	return (CONTINUE_GAME);
}



void			war_loop(t_corewar *core)
{
	unsigned 	cycles_limit;
	int 		status;

	cycles_limit = (unsigned)core->cycle_to_die;
	core->cycles = 0;
	get_game_type(core);
	while (1)
	{
		status = war_step(core, &cycles_limit);
		if (status == STOP_GAME)
			break ;
	}

	if (F_VISUAL)
		visual_end(core);
	if (core->cycle_to_die <= 0 || core->carriage == NULL)
	{
		print_winner(core);
	}
}