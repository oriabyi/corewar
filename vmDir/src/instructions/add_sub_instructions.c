/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sub_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 19:08:57 by ariabyi           #+#    #+#             */
/*   Updated: 2018/12/28 19:08:58 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_header.h"

void				add_sub_instructs(t_carriage *carriage, t_args *arguments)
{
	REG[ARG_THIRD] =
		which_operation_needs(REG[ARG_FIRST],
								REG[ARG_SECOND],
								I_COMMAND);
	change_carry_if_need((unsigned char)ARG_THIRD, carriage);
}
