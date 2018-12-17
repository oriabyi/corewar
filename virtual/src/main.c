#include "../includes/corewar_header.h"
#include "stdio.h"

void	remove_dead_processes(t_carriage **begin_list, int *alive_processes,
							  unsigned *quant_carriages)
{
	t_carriage	*to_free;

	if (*begin_list)
	{
		if ((*begin_list)->alive == false)
		{
			to_free = *begin_list;
			*begin_list = (*begin_list)->next;
			free(to_free);
			(*quant_carriages)--;
			remove_dead_processes(begin_list, alive_processes, quant_carriages);
		}
		else
		{
			remove_dead_processes(&(*begin_list)->next, alive_processes, quant_carriages);
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
	while (counter < core->qua_bots)
	{
		remove_dead_processes(&core->bots[counter].carriage,
				&alive_processes, &core->bots[counter].quant_carriages);
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

char			*pull_out_champs_info(t_corewar *core)
{
	char 		*temp;
	int 		counter;

	counter = 0;
	temp = ft_strdup("Introducing contestants...\n");
	while (counter < core->qua_bots)
	{
		temp = ft_multjoinfr(13, NULL, temp, "* Player ", NULL,
				ft_itoa(counter + 1), ", weighing ", NULL,
				ft_itoa(core->bots[counter].size), " bytes, \"",
				core->bots[counter].name, "\" (\"",
				core->bots[counter].comment, "\") !\n");
		counter++;
	}
	return (temp);
}

# define LINE_SIZE 188

void 			print_memory(t_corewar *core)
{
	char			*temp;
	char			temp_memory_line[LINE_SIZE];
	size_t			i = 0;
	unsigned		j = 0;

	temp = pull_out_champs_info(core);
	while (i < MEM_SIZE)
	{
		j = 0;
		ft_bzero(temp_memory_line, LINE_SIZE);
		while (j == 0 || j % 62 != 0)
		{
			ft_multcat(2, temp_memory_line, (char *)core->cell[i].hex, " ");
			i++;
			j++;
		}
		ft_strcat(temp_memory_line, (char *)core->cell[i++].hex);
		i++;
		temp = ft_multjoinfr(7, NULL, temp, "0x",
			get_hex_by_int_byte((i - 64), 4), " : ", temp_memory_line, "\n");
	}
	write(1, temp, ft_strlen(temp));
	free(temp);
}

void			game(t_corewar *core)
{
	unsigned 		i;
	core->cycle_to_die = CYCLE_TO_DIE;
	core->max_checks = 0;

	visual_init(core);
	if (core->flags.visual)
	{
		visual_start(core);
		display_windows(core, 1);
	}
	i = 1;
	while (i < 15000)
	{
		if (!core->flags.visual && i == core->flags.dump)
		{
			print_memory(core);
			exit_message(core, 0, NULL);
		}
		if (i && core->cycle_to_die && i % core->cycle_to_die == 0)
			core->cycle_to_die = check_cycle_to_die(core);


		if (i >= core->flags.dump && core->flags.visual)
		{
			i = (unsigned)draw(core, i);
		}
		else
		{
			i++;
		}
		do_process(core, core->qua_bots);
		bigmother++;
	}
	if (core->flags.visual)
		visual_end(core);

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
