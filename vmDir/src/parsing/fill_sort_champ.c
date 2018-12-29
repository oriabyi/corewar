/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_sort_champ.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 18:19:38 by ariabyi           #+#    #+#             */
/*   Updated: 2018/12/28 18:19:39 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_header.h"

void				reverse_list(t_carriage **begin_list)
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

void				fill_first_carriages(t_corewar *core, unsigned qua_champs)
{
	t_carriage		*head;
	unsigned		counter;

	head = core->carriage;
	counter = 0;
	while (counter < qua_champs)
	{
		head->cur_coord = (MEM_SIZE / qua_champs) * counter;
		head = head->next;
		counter++;
	}
}

void				fill_last_live(t_corewar *core, unsigned qua_champs)
{
	unsigned		counter;

	counter = 0;
	while (counter < qua_champs)
	{
		core->last_live = counter;
		counter++;
	}
}

void				fill_champs(t_corewar *core,
							t_champ **champ, unsigned qua_champs)
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
	fill_first_carriages(core, qua_champs);
	fill_last_live(core, qua_champs);
}
