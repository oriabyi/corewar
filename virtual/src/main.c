#include "../includes/corewar_header.h"
#include "stdio.h"

//codage - считываем ли мы первое число после команды

int				reveal_memory_space(t_corewar *core, int cycle);


void	remove_dead_processes(t_carriage **begin_list)
{
	t_carriage	*to_free;

	if (*begin_list)
	{
		if ((*begin_list)->alive == FALSE)
		{
			to_free = *begin_list;
			*begin_list = (*begin_list)->next;
			free(to_free);
			remove_dead_processes(begin_list);
		}
		else
			remove_dead_processes(&(*begin_list)->next);
	}
}

void 			check_cycle_to_die(t_corewar *core)
{

	int 		counter;

	counter = 0;
	while (counter < core->qua_bots)
	{
		remove_dead_processes(&core->bots[counter].carriage);
		counter++;
	}
}

void			game(t_corewar *core) // delete flag
{
	unsigned 		i;
	int 		flag = 0;

	vs_init(core);
	if (core->flags.visual)
	{
		ft_putstr_fd("VISUAL ON!\n", 2);
		vs_start(core);
	}
	i = 1;
	while (i)
	{
		if (bigmother > 3000)
			flag = 1;
		if (core->flags.visual)
			reveal_memory_space(core, i);
//		else if (flag)
//			dog_nail_vs(core);
		flag = do_process(core, core->qua_bots);
		if (i % CYCLE_TO_DIE == 0)
			check_cycle_to_die(core);
		bigmother++;
		i++;
//		printf("%d\n", i);
//		oversight_key(core);
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
