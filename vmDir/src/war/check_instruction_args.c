/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruction_args.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 17:35:46 by ariabyi           #+#    #+#             */
/*   Updated: 2018/12/28 17:35:47 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_header.h"

int				check_instruction_arg(int argument, int byte)
{
	if (byte == (T_REG | T_DIR | T_IND))
		return (0);
	if (argument == T_REG && (byte & 1) == false)
		return (T_REG);
	if (argument == T_DIR && (byte & 2) == false)
		return (T_DIR);
	if (argument == GET_IND(T_IND) && (byte & 4) == false)
		return (T_IND);
	return (0);
}

int				get_indent_size(int argument, int bytes)
{
	if (argument == T_REG)
		return (1);
	else if (argument == T_DIR)
		return (bytes);
	else if (argument == T_IND)
		return (2);
	return (0);
}

int				get_indent(int argument, int count_arguments, int bytes)
{
	int			step;

	step = 0;
	if (count_arguments >= 1)
	{
		step += get_indent_size(check_instruction_arg(GET_FIRST_ARG(argument),
				NONE_ARG), bytes);
		if (count_arguments >= 2)
		{
			step += get_indent_size(
				check_instruction_arg(GET_SECOND_ARG(argument),
						NONE_ARG), bytes);
			if (count_arguments >= 3)
				step += get_indent_size(
						check_instruction_arg(GET_THIRD_ARG(argument),
								NONE_ARG), bytes);
		}
	}
	return (step);
}

int				check_reg(int reg)
{
	if (CHECK_REG(reg) == false)
	{
		return (1);
	}
	return (0);
}
