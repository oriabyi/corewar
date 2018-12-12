#include "../includes/corewar_header.h"
#include "stdio.h"

void	remove_dead_processes(t_carriage **begin_list, int *alive_processes)
{
	t_carriage	*to_free;

	if (*begin_list)
	{
		if ((*begin_list)->alive == FALSE)
		{
			to_free = *begin_list;
			*begin_list = (*begin_list)->next;
			free(to_free);
			remove_dead_processes(begin_list, alive_processes);
		}
		else
		{
			remove_dead_processes(&(*begin_list)->next, alive_processes);
			(*alive_processes)++;
		}
	}
}

int 			check_cycle_to_die(t_corewar *core)
{
	int 			counter;
	int 			alive_processes;
	static int 		cycle_to_die;
	static int 		max_checks;

	if (core == NULL)
	{
		max_checks = 0;
		cycle_to_die = CYCLE_TO_DIE;
		return (0);
	}
	counter = 0;
	alive_processes = 0;
	while (counter < core->qua_bots)
	{
		remove_dead_processes(&core->bots[counter].carriage, &alive_processes);
		counter++;
	}
	if (alive_processes > 21)
		cycle_to_die -= CYCLE_DELTA;
	else
		max_checks++;

	if (max_checks == MAX_CHECKS)
	{
		max_checks = 0;
		cycle_to_die -= CYCLE_DELTA;
	}
	cycle_to_die *= (cycle_to_die < 0) ? 0 : 1;
	return (cycle_to_die);
}

void			game(t_corewar *core) // delete flag
{
	unsigned 		i;
	int 		flag = 0;
	int 		cycle_to_die;


//	check_cycle_to_die(NULL);
	cycle_to_die = CYCLE_TO_DIE;
	vs_init(core);

	if (core->flags.visual)
	{
		ft_putstr_fd("VISUAL ON!\n", 2);
		vs_start(core);
	}
	i = 0;
	while (i < 20000)
	{
		if (i == core->flags.dump)
		{
			//print_memory();
			exit_message(core, 0, "Dump");
		}
		if (i && cycle_to_die && i % cycle_to_die == 0)
			cycle_to_die = check_cycle_to_die(core);
		if (bigmother == 50)
			flag = 1;
		if (core->flags.visual)
		{
			draw(core, i);
			if (!core->flags.visual) // TODO: clean_all && exit? gde blyat logika? kak ono syda zaidet esli vuwe if s ysloviem protivlopolojnim???
				vs_end(core);
		}
//		else
//			dog_nail_vs(core);


//		if (!core->ncur.pause)
//		{
			flag = do_process(core, core->qua_bots);
			bigmother++;
			i++;
//		}
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
