/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_index_instruct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 19:10:33 by ariabyi           #+#    #+#             */
/*   Updated: 2018/12/28 19:17:04 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_header.h"

void					store_index_instruct(t_field *field,
							t_carriage *carriage,
							t_args *arguments, unsigned cycles)
{
	ssize_t				coord;

	if (get_regs_value(LIST_ARGUMENTS, carriage, T_REG, 2,
						SECOND_ARG, &ARG_SECOND,
						THIRD_ARG, &ARG_THIRD) == 1)
	{
		return ;
	}
	coord = (((int)(ARG_SECOND + ARG_THIRD) % IDX_MOD) + CUR_COORD);
	write_in_field(field, (int)coord, REG[ARG_FIRST]);
	add_champ_id((int)coord, field, carriage, cycles);
}
