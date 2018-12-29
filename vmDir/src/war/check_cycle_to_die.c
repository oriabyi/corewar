/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cycle_to_die.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 17:33:33 by ariabyi           #+#    #+#             */
/*   Updated: 2018/12/28 17:33:34 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_header.h"

void				delete_carriage(t_carriage **begin_list, t_carriage **head,
											t_carriage **prev, t_field *field)
{
	t_carriage	*to_free;

	to_free = *head;
	if (*head == *begin_list)
	{
		*begin_list = (*begin_list)->next;
		*head = *begin_list;
	}
	else
	{
		*head = (*head)->next;
		(*prev)->next = *head;
	}
	field[to_free->cur_coord].carriages_on--;
	free(to_free);
}

void				remove_dead_processes(t_carriage **begin_list,
								unsigned *qua_carriages, t_field *field)
{
	t_carriage	*head;
	t_carriage	*prev;

	head = *begin_list;
	prev = *begin_list;
	while (head)
	{
		if (head->alive == 0)
		{
			delete_carriage(begin_list, &head, &prev, field);
			(*qua_carriages)--;
		}
		else
		{
			prev = head;
			head = head->next;
		}
	}
}

unsigned			reset_carriages_id(t_carriage **cariage)
{
	t_carriage	*head;
	unsigned	counter;

	counter = 0;
	head = *cariage;
	while (head)
	{
		head->id = counter++;
		head->alive = 0;
		head = head->next;
	}
	return (counter);
}

void				reset_lives_champ(t_champ **champ, unsigned qua_champs)
{
	unsigned		counter;

	counter = 0;
	while (counter < qua_champs)
	{
		(*champ)[counter].qua_lives = 0;
		counter++;
	}
}

int					check_cycle_to_die(t_corewar *core)
{
	remove_dead_processes(&core->carriage, &core->quant_carriages, core->field);
	if (core->qua_lives > NBR_LIVE)
	{
		core->cycle_to_die -= CYCLE_DELTA;
	}
	else
	{
		core->max_checks++;
	}
	if (core->max_checks == MAX_CHECKS)
	{
		core->max_checks = 0;
		core->cycle_to_die -= CYCLE_DELTA;
	}
	core->qua_lives = 0;
	core->quant_carriages = reset_carriages_id(&core->carriage);
	reset_lives_champ(&core->champs, core->qua_champs);
	return ((core->cycle_to_die > 0) ? core->cycle_to_die : 0);
}
