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
	if (!field->carriages_on && field->hex[0] == '0' && field->hex[1] == '1')
		field->is_alive = 0;
}

void			place_carriage(t_field *field)
{
	field->carriages_on++;
	if (field->hex[0] == '0' && field->hex[1] == '1')
		field->is_alive = 1;
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

void			denote_field(t_field *field, int coord)
{
	if (field[coord].hex[0] == '0' && field[coord].hex[1] == '1')
		field[coord].is_alive = 1;
}
