#include "../includes/corewar_header.h"

void 			reset_game(t_corewar *core)
{
	int 		counter;

	counter = 0;
	while (counter < core->qua_champs)
	{
		clean_carriages(core->champs[counter].carriage);
		core->champs[counter].carriage = create_carriage(core->champs[counter].id);
		counter++;
	}
	free(core->field);
	create_memory_space(core);
	fill_memory_space(core->champs, core->field, core->qua_champs);
	core->max_checks = 0;
	core->cycle_to_die = CYCLE_TO_DIE;
}