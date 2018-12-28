/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_with_champs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 18:03:49 by ariabyi           #+#    #+#             */
/*   Updated: 2018/12/28 18:03:50 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_header.h"

int					create_champs(t_champ **champs)
{
	int				counter;

	counter = 0;
	if (!(*champs = (t_champ *)malloc(sizeof(t_champ) * O_BOTS)))
		return (MEMORY_ERROR);
	while (counter < O_BOTS)
	{
		(*champs)[counter] = (t_champ){NULL, NULL, NULL, (O_BOTS + 1), 0, 0};
		counter++;
	}
	return (0);
}

unsigned			find_free_space(t_champ *champs)
{
	unsigned		counter;

	counter = 1;
	while (counter < (O_BOTS + 1))
	{
		if (get_champ_by_id(champs, counter) == false)
			return (counter);
		counter++;
	}
	return (O_BOTS + 1);
}

int					get_champ_by_id(t_champ *champ, unsigned id)
{
	int				counter;

	counter = 0;
	while (counter < O_BOTS)
	{
		if (champ[counter].id == id)
			return (true);
		counter++;
	}
	return (false);
}

void				swap_champs(t_champ *first, t_champ *second)
{
	t_champ			temp;

	temp = *first;
	*first = *second;
	*second = temp;
}

void				sort_champs(t_champ **champ, int qua_champs)
{
	int				counter;

	counter = 0;
	while (counter + 1 < qua_champs)
	{
		if ((*champ)[counter].id > (*champ)[counter + 1].id)
		{
			swap_champs(&((*champ)[counter]), &((*champ)[counter + 1]));
			counter = 0;
		}
		else
			counter++;
	}
}
