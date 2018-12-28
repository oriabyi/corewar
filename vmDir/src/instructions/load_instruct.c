/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_instruct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 19:15:58 by ariabyi           #+#    #+#             */
/*   Updated: 2018/12/28 19:15:59 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_header.h"

void					load_instruct(t_carriage *carriage, t_args *arguments)
{
	REG[ARG_SECOND] = (unsigned)ARG_FIRST;
	change_carry_if_need((unsigned char)ARG_SECOND, carriage);
}
