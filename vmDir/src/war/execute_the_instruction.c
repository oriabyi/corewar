/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_the_instruction.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 17:36:02 by ariabyi           #+#    #+#             */
/*   Updated: 2018/12/28 17:36:02 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_header.h"

void					list_of_instructions(t_field *field,
										t_carriage *carriage, t_args *arguments,
												unsigned cycles)
{
	if (I_COMMAND == CW_LD || I_COMMAND == CW_LLD)
		load_instruct(carriage, arguments);
	else if (I_COMMAND == CW_ST)
		store_instruct(field, carriage, arguments, cycles);
	else if (I_COMMAND == CW_ADD || I_COMMAND == CW_SUB)
		add_sub_instructs(carriage, arguments);
	else if (I_COMMAND == CW_XOR || I_COMMAND == CW_OR || I_COMMAND == CW_AND)
		logical_operations(carriage, arguments);
	else if (I_COMMAND == CW_LDI || I_COMMAND == CW_LLDI)
		load_index_instruct(field, carriage, arguments);
	else if (I_COMMAND == CW_STI)
		store_index_instruct(field, carriage, arguments, cycles);
	else if (I_COMMAND == CW_AFF)
		aff_instruct(carriage, arguments);
}

void					choose_instruction(t_field *field, t_carriage *carriage,
																t_corewar *core)
{
	int					check_jump;

	if (get_t_args(field, carriage, &core->arguments) == 1)
		;
	else if (I_COMMAND == CW_ZJMP)
		check_jump = jump_if_carry_instruct(field, carriage, &core->arguments);
	else if (I_COMMAND == CW_FORK || I_COMMAND == CW_LFORK)
		fork_instruct(field, carriage, core, &core->arguments);
	else if (I_COMMAND == CW_LIVE)
		alive_instruct(field, carriage, core, &core->arguments);
	else
		list_of_instructions(field, carriage, &core->arguments, core->cycles);
	if (I_COMMAND != CW_ZJMP || check_jump == true)
	{
		if (I_CODAGE)
		{
			move_carriage(field, 1 + get_indent(core->arguments.list_arguments,
									I_QUA_ARGS, I_LABEL_SIZE) + 1, carriage);
		}
		else
			move_carriage(field, 1 + (I_COMMAND == CW_LIVE ? 4 : 2), carriage);
		core->arguments = (t_args){0, 0, 0, 0};
	}
	I_INSTRUCT = NULL;
}

void					do_process(t_corewar *core)
{
	t_carriage			*carriage;

	carriage = core->carriage;
	while (carriage)
	{
		if (I_INSTRUCT == 0)
		{
			I_INSTRUCT = get_instruction_by_id(
					(t_instructions *)&core->instructions,
					ft_ahtoi((char *)(core->field[CUR_COORD].hex)));
			if (I_INSTRUCT)
				carriage->cycles = I_INSTRUCT->cycles;
		}
		carriage->cycles--;
		if (carriage->cycles <= 0)
		{
			if (I_INSTRUCT)
				choose_instruction(core->field, carriage, core);
			else
				move_carriage(core->field, 1, carriage);
		}
		carriage = carriage->next;
	}
}
