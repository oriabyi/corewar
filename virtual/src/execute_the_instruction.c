#include "../includes/corewar_header.h"

void						list_of_instructions(t_field *field,
										t_carriage *carriage, t_args *arguments)
{
	if (COMMAND == CW_LD || COMMAND == CW_LLD)
		load_instruct(carriage, arguments);
	else if (COMMAND == CW_ST)
		store_instruct(field, carriage, arguments);
	else if (COMMAND == CW_ADD || COMMAND == CW_SUB)
		add_sub_instructs(carriage, arguments);
	else if (COMMAND == CW_XOR || COMMAND == CW_OR || COMMAND == CW_AND)
		logical_operations(carriage, arguments);
	else if (COMMAND == CW_LDI || COMMAND == CW_LLDI)
		load_index_instruct(field, carriage, arguments);
	else if (COMMAND == CW_STI)
		store_index_instruct(field, carriage, arguments);
	else if (COMMAND == CW_AFF)
		aff_instruct(carriage, arguments);
}


void 					choose_instruction(t_field *field, t_carriage *carriage, t_corewar *core, t_args *arguments)
{
	int 				check_jump;

	if ((IS_VALID_COMMAND(COMMAND) == false))
	{
		move_carriage(field, 1, carriage);
		return ;
	}
	if (get_t_args(field, carriage, arguments) == 1)
		arguments->is_valid = 1;
	else if (COMMAND == CW_ZJMP)
		check_jump = jump_if_carry_instruct(field, carriage, arguments);
	else if (COMMAND == CW_FORK || COMMAND == CW_LFORK)
		fork_instruct(field, carriage, &core->quant_carriages, arguments);
	else if (COMMAND == CW_LIVE)
		alive_instruct(field, carriage, core, arguments);
	else
		list_of_instructions(field, carriage, arguments);
	if (COMMAND != CW_ZJMP || check_jump == true)
	{
		move_carriage(field, 1 + (get_codage(COMMAND) ? get_indent(LIST_ARGUMENTS, arguments->qua_args, get_dir_bytes(COMMAND)) + 1 : (COMMAND == CW_LIVE ? 4 : 2)),
				carriage);
		*arguments = (t_args){0, 0, 0, {0, 0, 0}, 0, 0, 0};
	}
}

void 			do_process(t_corewar *core)
{
	t_carriage	*carriage;

	carriage = core->carriage;
	while (carriage)
	{
		if (COMMAND == 0)
		{
			COMMAND = ft_ahtoi((char *)(core->field[CUR_COORD].hex));
			if (IS_VALID_COMMAND(COMMAND) == true)
				CYCLES = get_cycles(carriage);
		}
		(CYCLES)--;
		if (CYCLES <= 0)
		{
			choose_instruction(core->field, carriage, core, &core->arguments);
			COMMAND = 0;
		}
		carriage = carriage->next;
	}
}
