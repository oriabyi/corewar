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
	if (!(*champs = (t_champ *)malloc(sizeof(t_champ) * O_CHAMPS)))
		return (MEMORY_ERROR);
	while (counter < O_CHAMPS)
	{
		(*champs)[counter] = (t_champ){NULL, NULL, NULL, (O_CHAMPS + 1),
																0, 0, 0, 0};
		counter++;
	}
	return (0);
}

unsigned			find_free_space(t_champ *champs)
{
	unsigned		counter;

	counter = 1;
	while (counter < (O_CHAMPS + 1))
	{
		if (get_champ_by_id(champs, counter) == false)
			return (counter);
		counter++;
	}
	return (O_CHAMPS + 1);
}

int					get_champ_by_id(t_champ *champ, unsigned id)
{
	int				counter;

	counter = 0;
	while (counter < O_CHAMPS)
	{
		if (champ[counter].id == id)
			return (true);
		counter++;
	}
	return (false);
}
