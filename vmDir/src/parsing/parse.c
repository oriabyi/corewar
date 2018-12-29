/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 18:15:04 by ariabyi           #+#    #+#             */
/*   Updated: 2018/12/28 18:15:05 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_header.h"

int					get_all_other_info(t_champ *champ, int fd)
{
	char			buf;

	champ->name = get_name(fd);
	if (interlayer(fd) == 0)
	{
		champ->size = get_size(fd);
		champ->comment = get_comment(fd);
		if (interlayer(fd) == 0)
		{
			if (get_exec_code(fd, champ->size, &champ->exec_code) == 1 &&
				read(fd, &buf, 1) == 0)
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
	int				check_num;

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

int					get_flag_n(t_corewar *core, char **av, int *counter,
														unsigned *champ_id)
{
	if (*(av[(*counter)]) == '-' && av[(*counter) + 1])
	{
		*champ_id = (unsigned)ft_atoi(av[(*counter) + 1]);
		if (are_nums(av[(*counter) + 1]) == 1)
			return (BAD_VALUE_FOR_FLAG_N);
		if (check_got_num(av[*counter + 1], *champ_id, 1) &&
			av[*counter + 1][ft_strlen(av[*counter + 1]) - 1] != '0')
			return (BAD_VALUE_FOR_FLAG_N);
		(void)core;
		if (get_champ_by_id(core->champs, *champ_id) &&
				*champ_id != O_CHAMPS + 1)
			return (SAME_NUM_FOR_CHAMPS);
		(*counter) += 2;
		return (1);
	}
	return (0);
}

int					get_champs_info(t_corewar *core, char **av, int *counter)
{
	unsigned		champ_id;
	int				check_code;
	int				champs;

	champs = 0;
	check_code = 0;
	while (av[(*counter)] && check_code == 0 && ++champs <= O_CHAMPS)
	{
		champ_id = O_CHAMPS + 1;
		if ((check_code = get_flag_n(core, av, counter, &champ_id)))
			;
		else if (*(av[(*counter)]) == '-' && av[(*counter) + 1] == NULL)
			return (NO_ID_AFTER_FLAG);
		else
			champ_id = find_free_space(core->champs);
		if (check_code == BAD_VALUE_FOR_FLAG_N ||
				check_code == SAME_NUM_FOR_CHAMPS)
			return (check_code);
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
	fill_champs(core, &core->champs, core->qua_champs);
	reverse_list(&core->carriage);
	if (av[counter])
		return (REDUNDANT_ARGUMENTS);
	return (check_code);
}
