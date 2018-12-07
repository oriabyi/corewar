#include "../includes/corewar_header.h"


int					get_bot(t_bot *bot, char *botfilename, unsigned number)
{
	int				fd;

	bot->id = number + 1;

	if ((fd = open(botfilename, O_RDONLY)) < 0)
		return (BAD_ARGUMENTS);
	if (get_num_by_octet_bytes(fd) != COREWAR_EXEC_MAGIC)
		return (WRONG_MAGIC_VALUE);
	bot->name = get_name(fd);
	bot->size = (unsigned)get_size(fd);
	bot->comment = get_comment(fd);
	get_exec_code(fd, bot->size, &bot->exec_code);
	close(fd);
	return (0);
}

t_carriage 				*create_carriage(int id)
{
	t_carriage			*carriage;

	if (!(carriage = (t_carriage *)malloc(sizeof(t_carriage))))
		return (NULL);
	*carriage = (t_carriage){0, 0, 0, 0, {0, (unsigned)(-id), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0, 0, NULL};
	return (carriage);
}


int 				fill_bot(t_corewar *core)
{
	int 			i;

	i = 0;
	core->bots[core->qua_bots] = (t_bot){NULL, NULL, NULL, 0, 0, 0, 0, NULL};

	core->bots[core->qua_bots].carriage = create_carriage(core->qua_bots + 1);
//	if (!(core->bots[core->qua_bots].carriage = (t_carriage *)malloc(sizeof(t_carriage))))
//		return (MEMORY_ERROR);
//	*(core->bots[core->qua_bots].carriage) = (t_carriage){0, 0, 0, 0, 0, 0, 0};
	core->bots[core->qua_bots].fd = open("/Users/ariabyi/CLionProjects/Corewar/test.txt", O_WRONLY);
//	while (i < 16) // do i need this
//	{
//		core->bots[core->qua_bots].carriage->registers[i] = (unsigned long)(4294967295 - core->qua_bots);
//		core->bots[core->qua_bots].carriage->registers[i] = (unsigned long)(0 - core->qua_bots);
//		core->bots[core->qua_bots].carriage->registers[i] = 0;
//		i++;
//	}
	core->bots[core->qua_bots].quant_carriages++;
	return (0);
}

int					get_bots(t_corewar *core, char **av)
{
	int				check_code;
	int				counter;

	counter = 1;
	check_code = 0;
	while (av[counter] && *(av[counter]) == '-')
		counter++;
	if (!av[counter])
		return (BAD_ARGUMENTS);
	if (!(core->bots = (t_bot *)malloc(sizeof(t_bot) * O_BOTS)))
		return (MEMORY_ERROR);
	while (av[counter] && check_code == 0)
	{
		if (*(av[counter]) == '-')
			return (WRONG_PLACE_FOR_FLAGS);
		fill_bot(core);
//		core->bots[core->qua_bots] = (t_bot){NULL, NULL, NULL, 0, 0, NULL};
//		if (!(core->bots[core->qua_bots].carriage = (t_carriage *)malloc(sizeof(t_carriage))))
//			return (MEMORY_ERROR);
//		*(core->bots[core->qua_bots].carriage) = (t_carriage){0, 0, 0, 0, 0, 0, 0};
		check_code = get_bot(&(core->bots[core->qua_bots]), av[counter++], core->qua_bots++);
	}
	return (check_code);
}

int					parse(t_corewar *core, char **av)
{
	int				check_code;

	check_code = get_bots(core, av);
	check_correctness(core, check_code);

	return (0);
}
