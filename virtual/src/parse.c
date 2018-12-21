#include "../includes/corewar_header.h"


int					get_champ(t_champ *champ, char *champfilename, unsigned number)
{
	int				fd;

	champ->id = number;

	if ((fd = open(champfilename, O_RDONLY)) < 0)
		return (BAD_ARGUMENTS);
	if (get_num_by_octet_bytes(fd) != COREWAR_EXEC_MAGIC)
		return (WRONG_MAGIC_VALUE);
	champ->name = get_name(fd);
	champ->size = (unsigned)get_size(fd);
	champ->comment = get_comment(fd);
	get_exec_code(fd, champ->size, &champ->exec_code);
	close(fd);
	return (0);
}

t_carriage 				*create_carriage(int id)
{
	t_carriage			*carriage;

	if ((carriage = (t_carriage *)malloc(sizeof(t_carriage))) == NULL)
		return (NULL);
	*carriage = (t_carriage){0, 0, 0, 0, {(unsigned)(-id), 0, 0, 0, 0, 0, 0, 0,
									0, 0, 0, 0, 0, 0, 0, 0}, 0, 0, 0, NULL};
	return (carriage);
}


int 				create_champs(t_champ **champs)
{
	int 			counter;

	counter = 0;
	if (!(*champs = (t_champ *)malloc(sizeof(t_champ) * O_BOTS)))
		return (MEMORY_ERROR);
	while (counter < O_BOTS)
	{
		(*champs)[counter] = (t_champ){NULL, NULL, NULL, 0, 0, 0, 0, NULL};
		counter++;
	}
	return (0);
}


unsigned 			find_free_space(t_champ *champs)
{
	unsigned 			counter;
	int 			ids[O_BOTS];

	if (champs == NULL)
		return (0);
	counter = 0;
	while (counter < O_BOTS)
		ids[counter++] = 0;
	counter = 0;
	while (counter < O_BOTS)
	{
		if (champs[counter].id != 0)
			ids[champs[counter].id - 1] = 1;
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

int 				fill_champ_by_himself(t_champ *champ, int id)
{
	(champ)->carriage = create_carriage(id);
	(champ)->fd =
			open("/Users/ariabyi/CLionProjects/Corewar/test.txt", O_WRONLY);
	(champ)->quant_carriages++;
	return (0);
}

void 				fill_champs(t_champ **champ, int qua_champs)
{
	int 			counter;

	counter = 0;
	while (counter < qua_champs)
	{
		fill_champ_by_himself(&((*champ)[counter]), (*champ)[counter].id);
		counter++;
	}
}

void 				swap_champs_id(t_champ *first, t_champ *second)
{
	unsigned		temp;

	temp = first->id;
	first->id = second->id;
	second->id = temp;
}

void 				swap_champs(t_champ *first, t_champ *second, int code)
{
	t_champ			temp;

	temp = *first;
	*first = *second;
	*second = temp;
	if (code == SWAP_ID)
		swap_champs_id(first, second);
}

void 				sort_champs(t_champ **champ, int qua_champs)
{
	int 			counter;

	counter = 0;
	while (counter + 1 < qua_champs)
	{
		if ((*champ)[counter].id > (*champ)[counter + 1].id)
		{
			swap_champs(&((*champ)[counter]), &((*champ)[counter + 1]), DO_NOT_SWAP_ID);
			counter = 0;
		}
		else
			counter++;
	}
}

int 				get_champs_info(t_corewar *core, char **av, int *counter)
{
	unsigned 		champ_id;
	int 			check_code;
	int 			champs;

	champs = 0;
	check_code = 0;
	while (av[(*counter)] && check_code == 0 && ++champs <= O_BOTS)
	{
		if (*(av[(*counter)]) == '-')
		{
			champ_id = (unsigned)ft_atoi(av[(*counter) + 1]) - 1;
			if (core->champs[champ_id].id != 0)
				return (SAME_NUM_FOR_CHAMPS);

			if (ft_pwrbase(champ_id, 10) != ft_strlen(av[(*counter) + 1]))
				return (TOO_BIG_NUM_FOR_CHAMP);

			(*counter) += 2;
			check_code = get_champ(&(core->champs[core->qua_champs]),
								 av[(*counter)++], champ_id);
		}
		else
		{
			check_code = get_champ(&(core->champs[core->qua_champs]),
							av[(*counter)++], (find_free_space(core->champs)));
		}
//		champ_id = (champ_id < 1 || champ_id > 4) ? champ_id : find_free_space(core->champs);

		core->qua_champs++;
	}
	return (check_code);
}


int					get_champs(t_corewar *core, char **av)
{
	int				check_code;
	int				counter;

	counter = 1;
	while (av[counter] && *(av[counter]) == '-')
	{
		if (av[counter][1] == 'n')
			break ;
		if (ft_strchr(av[counter], 'd'))
			counter++;
		counter++;
	}
	if (!av[counter])
		return (MISSING_CHAMP);
	if ((check_code = create_champs(&core->champs)) != 0)
		return (check_code);
	if (get_champs_info(core, av, &counter) != 0)
		return (1);
	fill_champs(&core->champs, core->qua_champs);
	sort_champs(&core->champs, core->qua_champs);
	if (av[counter])
		return (BAD_ARGUMENTS);
	return (check_code);
}

void 				set_zero_bots(t_corewar *core)
{
	int 			counter;

	counter = 0;
	while (counter < O_BOTS)
	{
		core->champs[counter] = (t_champ ){NULL, NULL, NULL, 0, 0, 0, 0, 0};
		counter++;
	}
}

int					parse(t_corewar *core, char **av)
{
	int				check_code;

	check_code = get_champs(core, av);
	check_correctness(core, check_code);

	return (0);
}
//-n 4 /Users/ariabyi/CLionProjects/Corewar/def_vm_champs/champs/Gagnant.cor
// -n 2 /Users/ariabyi/CLionProjects/Corewar/def_vm_champs/champs/Gagnant.cor
// -n 1 /Users/ariabyi/CLionProjects/Corewar/def_vm_champs/champs/Gagnant.cor
// -n 3 /Users/ariabyi/CLionProjects/Corewar/def_vm_champs/champs/Gagnant.cor

//-n 4 /Users/ariabyi/CLionProjects/Corewar/def_vm_champs/champs/Gagnant.cor -n 3 /Users/ariabyi/CLionProjects/Corewar/def_vm_champs/champs/Gagnant.cor -n 2 /Users/ariabyi/CLionProjects/Corewar/def_vm_champs/champs/Gagnant.cor -n 1 /Users/ariabyi/CLionProjects/Corewar/def_vm_champs/champs/Gagnant.cor