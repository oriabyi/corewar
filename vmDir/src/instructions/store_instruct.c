/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_instruct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 19:17:12 by ariabyi           #+#    #+#             */
/*   Updated: 2018/12/28 19:17:14 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_header.h"

void		store_instruct(t_field *field, t_carriage *carriage,
										t_args *arguments, unsigned cycles)
{
	if (GET_SECOND_ARG(LIST_ARGUMENTS) == T_REG)
	{
		REG[ARG_SECOND] = REG[ARG_FIRST];
	}
	else
	{
		write_in_field(field, (int)(ARG_SECOND + CUR_COORD),
					REG[ARG_FIRST]);
		add_champ_id((int)(ARG_SECOND + CUR_COORD), field, carriage, cycles);
	}
}
