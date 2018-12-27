#include "../includes/corewar_header.h"

void						list_of_instructions(t_field *field,
										t_carriage *carriage, t_args *arguments)
{
	if (carriage->instr->i_command == CW_LD || carriage->instr->i_command == CW_LLD)
		load_instruct(carriage, arguments);
	else if (carriage->instr->i_command == CW_ST)
		store_instruct(field, carriage, arguments);
	else if (carriage->instr->i_command == CW_ADD || carriage->instr->i_command == CW_SUB)
		add_sub_instructs(carriage, arguments);
	else if (carriage->instr->i_command == CW_XOR || carriage->instr->i_command == CW_OR || carriage->instr->i_command == CW_AND)
		logical_operations(carriage, arguments);
	else if (carriage->instr->i_command == CW_LDI || carriage->instr->i_command == CW_LLDI)
		load_index_instruct(field, carriage, arguments);
	else if (carriage->instr->i_command == CW_STI)
		store_index_instruct(field, carriage, arguments);
	else if (carriage->instr->i_command == CW_AFF)
		aff_instruct(carriage, arguments);
}


void 					choose_instruction(t_field *field, t_carriage *carriage, t_corewar *core, t_args *arguments)
{
	int 				check_jump;

	if (carriage->instr == NULL)
	{
		move_carriage(field, 1, carriage);
		return ;
	}
	if (get_t_args(field, carriage, arguments) == 1)
		;
	else if (carriage->instr->i_command == CW_ZJMP)
		check_jump = jump_if_carry_instruct(field, carriage, arguments);
	else if (carriage->instr->i_command == CW_FORK || carriage->instr->i_command == CW_LFORK)
		fork_instruct(field, carriage, core, arguments);
	else if (carriage->instr->i_command == CW_LIVE)
		alive_instruct(field, carriage, core, arguments);
	else
		list_of_instructions(field, carriage, arguments);
	if (carriage->instr->i_command != CW_ZJMP || check_jump == true)
	{
		move_carriage(field, 1 + (carriage->instr->codage ? get_indent(arguments->list_arguments, carriage->instr->qua_args,carriage->instr->bytes_dir) + 1 : (carriage->instr->i_command == CW_LIVE ? 4 : 2)),	carriage);
		*arguments = (t_args){0, 0, 0, 0};
	}
}

void 			do_process(t_corewar *core)
{
	t_carriage	*carriage;

	carriage = core->carriage;
	while (carriage)
	{
		if (carriage->instr == 0)
		{
			carriage->instr = get_instruction_by_id((t_instructions *)&core->instructions, ft_ahtoi((char *)(core->field[CUR_COORD].hex)));
			if (carriage->instr)
			{
				carriage->cycles = carriage->instr->cycles;
				carriage->instr->i_command = carriage->instr->i_command;
			}
		}
		carriage->cycles--;
		if (carriage->cycles <= 0)
		{
			choose_instruction(core->field, carriage, core, &core->arguments);
			carriage->instr = NULL;

		}
		carriage = carriage->next;
	}
}
