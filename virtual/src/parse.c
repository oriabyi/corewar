#include "../includes/corewar_header.h"


int					get_bot(t_bot *bot, char *botfilename, unsigned number)
{
	int				fd;

	bot->id = number;

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
	*carriage = (t_carriage){0, 0, 0, 0, {0, (unsigned)(-id), 0, 0, 0, 0, 0,
									   	0, 0, 0, 0, 0, 0, 0, 0, 0}, 0, 0, NULL};
	return (carriage);
}


int 				create_bots(t_bot **bots)
{
	int 			counter;

	counter = 0;
	if (!(*bots = (t_bot *)malloc(sizeof(t_bot) * O_BOTS)))
		return (MEMORY_ERROR);
	while (counter < O_BOTS)
	{
		(*bots)[counter] = (t_bot){NULL, NULL, NULL, 0, 0, 0, 0, NULL};
		counter++;
	}
	return (0);
}


unsigned 			find_free_space(t_bot *bots)
{
	unsigned 			counter;
	int 			ids[O_BOTS];

	if (bots == NULL)
		return (0);
	counter = 0;
	while (counter < O_BOTS)
		ids[counter++] = 0;
	counter = 0;
	while (counter < O_BOTS)
	{
		if (bots[counter].id != 0)
			ids[bots[counter].id - 1] = 1;
		counter++;
	}
	counter = 0;
	while (counter < O_BOTS)
	{
		if (ids[counter] == 0)
			return (counter + 1);
		counter++;
	}
	return (counter);
}

int 				fill_bot_by_himself(t_bot *bot, int id)
{
	(bot)->carriage = create_carriage(id);
	(bot)->fd =
			open("/Users/ariabyi/CLionProjects/Corewar/test.txt", O_WRONLY);
	(bot)->quant_carriages++;
	return (0);
}

void 				fill_bots(t_bot **bot, int qua_bots)
{
	int 			counter;

	counter = 0;
	while (counter < qua_bots)
	{
		fill_bot_by_himself(&((*bot)[counter]), (*bot)[counter].id);
		counter++;
	}
}

void 				swap_bots_id(t_bot *first, t_bot *second)
{
	t_bot			temp;

	temp = *first;
	*first = *second;
	*second = temp;
}

void 				swap_bots(t_bot *first, t_bot *second)
{
	t_bot			temp;

	temp = *first;
	*first = *second;
	*second = temp;
}


void 				reverse_bots(t_bot **bot, int qua_bots)
{

	if (qua_bots == 1)
		return ;
	else if (qua_bots == 2)
	{
		swap_bots(&((*bot)[0]), &((*bot)[1]));
	}
	else if (qua_bots == 3)
	{
		swap_bots(&((*bot)[0]), &((*bot)[2]));
	}
	else if (qua_bots == 4)
	{
		swap_bots(&((*bot)[0]), &((*bot)[3]));
		swap_bots(&((*bot)[1]), &((*bot)[2]));
	}
}


void 				sort_bots(t_bot **bot, int qua_bots)
{
	int 			counter;

	counter = 0;
	while (counter + 1 < qua_bots)
	{
		if ((*bot)[counter].id > (*bot)[counter + 1].id)
		{
			swap_bots(&((*bot)[counter]), &((*bot)[counter + 1]));
			counter = 0;
		}
		else
			counter++;
	}
}


int					get_bots(t_corewar *core, char **av)
{
	int				check_code;
	int				counter;
	int				bots;
	unsigned		bot_id;

	bot_id = 0;
	bots = 0;
	counter = 1;
	check_code = 0;
	while (av[counter] && *(av[counter]) == '-')
	{
		if (av[counter][1] == 'n')
			break ;
		if (ft_strchr(av[counter], 'd'))
			counter++;
		counter++;
	}
	if (!av[counter])
		return (BAD_ARGUMENTS);
	if ((check_code = create_bots(&core->bots)) != 0)
		return (check_code);

	while (av[counter] && check_code == 0 && ++bots <= O_BOTS)
	{

		if (*(av[counter]) == '-')
		{
			bot_id = (unsigned)ft_atoi(av[counter + 1]);
			if (bot_id < 1 || bot_id > 4 || core->bots[bot_id].id != 0 ||
				ft_pwrbase(bot_id, 10) != ft_strlen(av[counter + 1]))
				return (ERROR); // replace with good define
			counter += 2;
			check_code = get_bot(&(core->bots[core->qua_bots]),
								 av[counter++], bot_id);
		}
		else
		{
			check_code = get_bot(&(core->bots[core->qua_bots]),
							 av[counter++], (find_free_space(core->bots)));
		}
		core->qua_bots++;
	}

	fill_bots(&core->bots, core->qua_bots);

	sort_bots(&core->bots, core->qua_bots);

//	reverse_bots(&core->bots, core->qua_bots);

	if (av[counter])
		return (BAD_ARGUMENTS);
	return (check_code);
}

int					parse(t_corewar *core, char **av)
{
	int				check_code;

	check_code = get_bots(core, av);
	check_correctness(core, check_code);

	return (0);
}
