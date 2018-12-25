#include "../includes/corewar_header.h"

void	remove_dead_processes(t_field *field, t_carriage **begin_list,
													unsigned *qua_carriages)
{
	t_carriage	*to_free;

	if (*begin_list == NULL)
		return ;
	if ((*begin_list)->alive == false)
	{
		to_free = *begin_list;
		*begin_list = (*begin_list)->next;
//		if (*begin_list && (*begin_list)->next)
//			(*begin_list)->next->id = (*begin_list)->id;
		(*qua_carriages)--;
//		field[to_free->cur_coord].champ_id = get_id_of_champ((unsigned)to_free->id);
		free(to_free);
		remove_dead_processes(field, begin_list, qua_carriages);
	}
	else
	{
		if ((*begin_list)->next)
			(*begin_list)->next->id = (*begin_list)->id + 1;
		remove_dead_processes(field, &(*begin_list)->next, qua_carriages);
	}
}

int i(t_champ *champ)
{
	int i = 0;
	int f = 0;
	t_carriage *temp;

	if (champ == NULL)
		return (0);
	temp = champ->carriage;
	while (champ->carriage)
	{
		i++;
		if (champ->carriage->alive == false)
			f++;
		champ->carriage = champ->carriage->next;
	}
	champ->carriage = temp;
	return (i);
}

int 			check_cycle_to_die(t_corewar *core)
{
	remove_dead_processes(core->field, &core->carriage, &core->quant_carriages);
	if (core->qua_lives > 21)
	{
		core->cycle_to_die -= CYCLE_DELTA;
	}
	else
	{
		core->max_checks++;
	}
	if (core->max_checks == MAX_CHECKS)
	{
		core->max_checks = 0;
		core->cycle_to_die -= CYCLE_DELTA;
	}
	core->qua_lives = 0;
	return ((core->cycle_to_die > 0) ? core->cycle_to_die : 0);
}
























