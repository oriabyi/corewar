#include "../includes/corewar_header.h"

void 			reset_game(t_corewar *core)
{
	int 		counter;

	counter = 0;
	while (counter < core->qua_bots)
	{
		clean_carriages(core->bots[counter].carriage);
		core->bots[counter].carriage = create_carriage(core->bots[counter].id);
		counter++;
	}
	free(core->cell);
	create_memory_space(core);
	fill_memory_space(core->bots, core->cell, core->qua_bots);
	core->max_checks = 0;
	core->cycle_to_die = CYCLE_TO_DIE;
}