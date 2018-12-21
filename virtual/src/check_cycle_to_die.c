#include "../includes/corewar_header.h"

void	remove_dead_processes(t_field *field, t_carriage **begin_list,
								int *alive_processes, unsigned *quant_carriages)
{
	t_carriage	*to_free;

	if (*begin_list)
	{
		if ((*begin_list)->alive == false)
		{
			to_free = *begin_list;
			*begin_list = (*begin_list)->next;
			if (*begin_list)
				(*begin_list)->next->id = (*begin_list)->id;
			(*quant_carriages)--;
			field[to_free->cur_coord].champ_id = get_id_of_champ((unsigned)to_free->id);
			free(to_free);
			remove_dead_processes(field, begin_list, alive_processes, quant_carriages);
		}
		else
		{
			if ((*begin_list)->next)
				(*begin_list)->next->id = (*begin_list)->id + 1;
			remove_dead_processes(field, &(*begin_list)->next, alive_processes, quant_carriages);
			(*alive_processes)++;
		}
	}
}

int 			check_cycle_to_die(t_corewar *core)
{
	int 			counter;
	int 			alive_processes;

	counter = 0;
	alive_processes = 0;
	while (counter < core->qua_champs)
	{
		remove_dead_processes(core->field, &core->champs[counter].carriage,
				&alive_processes, &core->champs[counter].quant_carriages);
		counter++;
	}
	if (alive_processes > 21)
		core->cycle_to_die -= CYCLE_DELTA;
	else
		core->max_checks++;

	if (core->max_checks == MAX_CHECKS)
	{
		core->max_checks = 0;
		core->cycle_to_die -= CYCLE_DELTA;
	}
	core->cycle_to_die *= (core->cycle_to_die < 0) ? 0 : 1;
	return (core->cycle_to_die);
}