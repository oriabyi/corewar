/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 17:42:10 by ariabyi           #+#    #+#             */
/*   Updated: 2018/12/28 17:42:11 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_header.h"

int						check_instruction_args(unsigned char list_arguments,
													t_instructions *instruction)
{
	int					check_code;

	check_code = 0;
	if (list_arguments < 0x40)
		return (1);
	if (instruction->qua_args)
	{
		check_code = check_instruction_arg(GET_FIRST_ARG(list_arguments),
				I_DESIRED[FIRST_ARG]);
		if (check_code == 0 && instruction->qua_args >= 2)
		{
			check_code = check_instruction_arg(GET_SECOND_ARG(list_arguments),
					I_DESIRED[SECOND_ARG]);
			if (check_code == 0 && instruction->qua_args >= 3)
			{
				check_code =
					check_instruction_arg(GET_THIRD_ARG(list_arguments),
							I_DESIRED[THIRD_ARG]);
			}
		}
	}
	return (check_code ? 1 : 0);
}

int						get_check_list_args(t_field *field,
									t_carriage *carriage, t_args *arguments)
{
	if (I_CODAGE == 1)
	{
		LIST_ARGUMENTS = get_argument(field, CUR_COORD + 1);
		if (check_instruction_args(LIST_ARGUMENTS, I_INSTRUCT) == ERROR)
		{
			return (1);
		}
	}
	else
		LIST_ARGUMENTS = (unsigned char)0x80;
	return (0);
}

void					get_three_args(t_field *field, t_carriage *carriage,
															t_args *arguments)
{
	ARG_FIRST = get_arguments(field, LIST_ARGUMENTS, FIRST_ARG, carriage);
	if (I_QUA_ARGS >= 2)
	{
		ARG_SECOND = get_arguments(field, LIST_ARGUMENTS,
				SECOND_ARG, carriage);
		if (I_QUA_ARGS == 3)
		{
			ARG_THIRD = get_arguments(field, LIST_ARGUMENTS,
					THIRD_ARG, carriage);
		}
	}
}

int						check_regs_in_args(t_args *arguments)
{
	if (check_type_arguments(arguments, T_REG, 3,
							FIRST_ARG, ARG_FIRST,
							SECOND_ARG, ARG_SECOND,
							THIRD_ARG, ARG_THIRD)
							== ERROR)
	{
		return (1);
	}
	return (0);
}

int						get_t_args(t_field *field, t_carriage *carriage,
															t_args *arguments)
{
	int					check_code;

	check_code = get_check_list_args(field, carriage, arguments);
	if (check_code == 0)
	{
		get_three_args(field, carriage, arguments);
		check_code = check_regs_in_args(arguments);
	}
	return (check_code);
}
