/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump_if_carry_instruct.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 19:15:45 by ariabyi           #+#    #+#             */
/*   Updated: 2018/12/28 19:15:47 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_header.h"

int			jump_if_carry_instruct(t_field *field, t_carriage *carriage,
															t_args *arguments)
{
	if (CARRY == 0)
	{
		return (1);
	}
	move_carriage(field, (int)(ARG_FIRST % IDX_MOD), carriage);
	return (0);
}
