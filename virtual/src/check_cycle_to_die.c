#include "../includes/corewar_header.h"

void	remove_dead_processes(t_carriage **begin_list,
							  unsigned *qua_carriages)
{
	t_carriage	*head;
	t_carriage	*to_free;
	t_carriage	*prev;

	head = *begin_list;
	prev = *begin_list;
	while (head)
	{
		if (head->alive == 0)
		{
			to_free = head;
			if (head == *begin_list)
			{
				*begin_list = (*begin_list)->next;
				head = *begin_list;
			}
			else
			{
				head = head->next;
				prev->next = head;
			}
			(*qua_carriages)--;
			free(to_free);
 		} else
		{
			prev = head;
			head = head->next;
		}
	}
}

unsigned		reset_carriages_id(t_carriage **cariage)
{
	t_carriage	*head;
	unsigned	counter;

	counter = 0;
	head = *cariage;
	while (head)
	{
		head->id = counter++;
		head = head->next;
	}
	return (counter);
}

int 			check_cycle_to_die(t_corewar *core)
{
	remove_dead_processes(&core->carriage, &core->quant_carriages);
	if (core->qua_lives > NBR_LIVE)
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
	core->quant_carriages = reset_carriages_id(&core->carriage);
	return ((core->cycle_to_die > 0) ? core->cycle_to_die : 0);
}
