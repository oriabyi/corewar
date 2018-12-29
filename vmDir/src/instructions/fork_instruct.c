/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_instruct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 19:13:48 by ariabyi           #+#    #+#             */
/*   Updated: 2018/12/28 19:13:50 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_header.h"

t_carriage				*copy_carriage(t_carriage *src, int id)
{
	int					counter;
	t_carriage			*dst;

	counter = 0;
	if (!(dst = create_carriage(id)))
		return (NULL);
	dst->carry = src->carry;
	dst->flag = src->flag;
	dst->alive = true;
	dst->cycles = 0;
	while (counter < NUMBER_OF_REGISTERS)
	{
		dst->registers[counter] = src->registers[counter];
		counter++;
	}
	return (dst);
}

void					insert_new_carriage(t_carriage **list, t_carriage *new,
										unsigned *quant_carriages)
{
	new->id = (*quant_carriages)++;
	new->next = *list;
	*list = new;
}

void					fork_instruct(t_field *field, t_carriage *carriage,
										t_corewar *core, t_args *arguments)
{
	t_carriage			*new_carriage;

	new_carriage = copy_carriage(carriage, core->quant_carriages);
	if (new_carriage == NULL)
	{
		return ;
	}
	if (I_COMMAND == CW_FORK)
	{
		new_carriage->cur_coord = (int)(CUR_COORD + (ARG_FIRST % IDX_MOD));
	}
	else if (I_COMMAND == CW_LFORK)
	{
		new_carriage->cur_coord = (int)(CUR_COORD + (ARG_FIRST));
	}
	new_carriage->cur_coord =
			(int)correction_coordinates(new_carriage->cur_coord);
	field[new_carriage->cur_coord].carriages_on++;
	insert_new_carriage(&core->carriage, new_carriage, &core->quant_carriages);
}
