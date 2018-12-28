#include "../includes/corewar_header.h"

unsigned 					interlayer(int fd);


int 				get_all_other_info(t_champ *champ, int fd)
{
	char 			buf;

	champ->name = get_name(fd);
	if (interlayer(fd) == 0)
	{
		champ->size = get_size(fd);
		champ->comment = get_comment(fd);
		if (interlayer(fd) == 0)
		{
			get_exec_code(fd, champ->size, &champ->exec_code);
			if (read(fd, &buf, 1) == 0)
			{
				return (check_champ_info(champ));
			}
			else
				return (BAD_EXEC_CODE_LENGTH);
		}
		else
			return (BAD_COMMENT_LENGTH);
	}
	else
		return (BAD_NAME_LENGTH);
}

int					get_champ(t_champ *champ, char *champfilename, unsigned id)
{
	int				fd;
	int 			check_num;

	champ->id = id;
	check_num = check_champ_file(champfilename);
	if (check_num)
		return (check_num);
	if ((fd = open(champfilename, O_RDONLY)) < 0)
		return (BAD_CHAMP);
	if (get_num_by_octet_bytes(fd, sizeof(unsigned)) != COREWAR_EXEC_MAGIC)
		check_num = WRONG_MAGIC_VALUE;
	else
	{
		check_num = get_all_other_info(champ, fd);
	}
	close(fd);
	return (check_num);
}

t_carriage 				*create_carriage(int id)
{
	t_carriage			*carriage;

	if ((carriage = (t_carriage *)malloc(sizeof(t_carriage))) == NULL)
		return (NULL);
	*carriage = (t_carriage){0, 0, 0, 0, 0, {(unsigned)(-id), 0, 0, 0, 0, 0, 0, 0,
									0, 0, 0, 0, 0, 0, 0, 0}, 0, NULL, NULL};
	return (carriage);
}

void 				reverse_list(t_carriage **begin_list)
{
	t_carriage		*curr;
	t_carriage		*next;
	t_carriage		*prev;

	prev = NULL;
	curr = *begin_list;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*begin_list = prev;

}


void 				fill_champs(t_corewar *core, t_champ **champ, int qua_champs) // refactor me
{
	t_carriage		*head;
	unsigned		counter;

	counter = 0;
	head = NULL;
	while (counter < qua_champs)
	{
		if (core->carriage == NULL)
		{
			head = create_carriage((*champ)[counter].id);
			core->carriage = head;
		}
		else
		{
			head->next = create_carriage((*champ)[counter].id);
			head = head->next;
		}
		head->next = NULL;
		head->id = core->quant_carriages++;
		counter++;
	}
	head = core->carriage;
	counter = 0;
	while (counter < qua_champs)
	{
		head->cur_coord = (MEM_SIZE / qua_champs) * counter;
		head = head->next;
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
		champ_id = O_BOTS + 1;
		if (*(av[(*counter)]) == '-' && av[(*counter) + 1])
		{
			champ_id = (unsigned)ft_atoi(av[(*counter) + 1]);
			if (are_nums(av[(*counter) + 1]) == 1)
				return (BAD_VALUE_FOR_FLAG_N);
			if (get_champ_by_id(core->champs, champ_id) && champ_id != O_BOTS + 1)
				return (SAME_NUM_FOR_CHAMPS);
			(*counter) += 2;
		}
		else if (*(av[(*counter)]) == '-' && av[(*counter) + 1] == NULL)
			return (NO_ID_AFTER_FLAG);
		champ_id = (champ_id <= O_BOTS) ? champ_id : find_free_space(core->champs);
		check_code = get_champ(&(core->champs[core->qua_champs]),
							   av[(*counter)++], champ_id);
		core->qua_champs++;
	}
	return (check_code);
}

int					parse(t_corewar *core, char **av)
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
	if ((check_code = get_champs_info(core, av, &counter)))
		return (check_code);
	sort_champs(&core->champs, core->qua_champs);
	fill_champs(core, &core->champs, core->qua_champs);
	reverse_list(&core->carriage);
	if (av[counter])
		return (REDUNDANT_ARGUMENTS);
	return (check_code);
}

