/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriages_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 17:32:25 by ariabyi           #+#    #+#             */
/*   Updated: 2018/12/28 17:32:26 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_header.h"

void			remove_carriage(t_field *field)
{
	if (field->carriages_on)
		field->carriages_on--;
	if (field->is_alive == 1)
		field->is_alive = 2;
}

void			place_carriage(t_field *field)
{
	field->carriages_on++;
}

void			move_carriage(t_field *field, int step, t_carriage *carriage)
{
	remove_carriage(&field[CUR_COORD]);
	CUR_COORD = (int)correction_coordinates(CUR_COORD + step);
	place_carriage(&field[CUR_COORD]);
	CUR_COORD = (int)correction_coordinates(CUR_COORD);
}

void			change_carry_if_need(unsigned char coord, t_carriage *carriage)
{
	if (REG[coord] == 0)
		CARRY = true;
	else
		CARRY = false;
}
