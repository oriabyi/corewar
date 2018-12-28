/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 19:18:32 by ariabyi           #+#    #+#             */
/*   Updated: 2018/12/28 19:18:34 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_header.h"

void					logical_operations(t_carriage *carriage,
															t_args *arguments)
{
	if (get_regs_value(LIST_ARGUMENTS, carriage, T_REG, 2,
							FIRST_ARG, &ARG_FIRST,
							SECOND_ARG, &ARG_SECOND) == 1)
	{
		return ;
	}
	REG[ARG_THIRD] =
			which_operation_needs(ARG_FIRST, ARG_SECOND, I_COMMAND);
	change_carry_if_need((unsigned char)ARG_THIRD, carriage);
}
