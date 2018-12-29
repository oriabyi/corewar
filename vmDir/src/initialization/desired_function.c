/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   desired_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 18:28:38 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/28 18:28:40 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_header.h"

void			insert(t_instructions *instructions, unsigned first,
												unsigned second, unsigned third)
{
	instructions->qua_args = 0;
	if ((instructions->desired[0] = first))
	{
		instructions->qua_args++;
		if ((instructions->desired[1] = second))
		{
			instructions->qua_args++;
			if ((instructions->desired[2] = third))
				instructions->qua_args++;
		}
	}
}

void			desired(t_instructions *instructions, unsigned command)
{
	if (command == CW_LIVE || command == CW_ZJMP ||
		command == CW_FORK || command == CW_LFORK)
	{
		insert(instructions, NONE_ARG, NONE_ARG, NONE_ARG);
	}
	else if (command == CW_LD || command == CW_LLD)
		insert(instructions, T_DIR | T_IND, T_REG, NONE_ARG);
	else if (command == CW_ST)
		insert(instructions, T_REG, T_REG | T_IND, NONE_ARG);
	else if (command == CW_ADD || command == CW_SUB)
		insert(instructions, T_REG, T_REG, T_REG);
	else if (command == CW_AND || command == CW_OR || command == CW_XOR)
	{
		insert(instructions,
				T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG);
	}
	else if (command == CW_LDI || command == CW_LLDI)
	{
		insert(instructions,
				T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG);
	}
	else if (command == CW_STI)
		insert(instructions, T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR);
	else if (command == CW_AFF)
		insert(instructions, T_REG, NONE_ARG, NONE_ARG);
}
