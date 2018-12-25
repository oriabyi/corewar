#include "../includes/corewar_header.h"

void						list_of_instructions(t_field *field,
										t_carriage *carriage)
{
	if (COMMAND == CW_LD || COMMAND == CW_LLD)
		load_instruct(carriage);
	else if (COMMAND == CW_ST)
		store_instruct(field, carriage);
	else if (COMMAND == CW_ADD || COMMAND == CW_SUB)
		add_sub_instructs(carriage);
	else if (COMMAND == CW_XOR || COMMAND == CW_OR || COMMAND == CW_AND)
		logical_operations(carriage);
	else if (COMMAND == CW_LDI || COMMAND == CW_LLDI)
		load_index_instruct(field, carriage);
	else if (COMMAND == CW_STI)
		store_index_instruct(field, carriage);
	else if (COMMAND == CW_AFF)
		aff_instruct(carriage);
}

void					get_arguments_table(t_carriage *carriage);

void 					get_t_args(t_field *field, t_carriage *carriage)
{
	if (get_codage(COMMAND) == true)
	{
		LIST_ARGUMENTS = get_argument(field, CUR_COORD + 1);
		get_arguments_table(carriage);
		if (check_instruction_args(LIST_ARGUMENTS,
								ADJUSTED[FIRST_ARG],
								ADJUSTED[SECOND_ARG],
								ADJUSTED[THIRD_ARG])
								== ERROR)
		{
			COMMAND = NO_INSTRUCTION;
		}
	}
	else
		LIST_ARGUMENTS = (unsigned char)0x80;
	CAR_FIRST_ARG = get_arguments(field, LIST_ARGUMENTS, FIRST_ARG, carriage);
	CAR_SECOND_ARG = get_arguments(field, LIST_ARGUMENTS, SECOND_ARG, carriage);
	CAR_THIRD_ARG = get_arguments(field, LIST_ARGUMENTS, THIRD_ARG, carriage);
	if (check_type_arguments(LIST_ARGUMENTS, T_REG, 3,
							FIRST_ARG, CAR_FIRST_ARG,
							SECOND_ARG, CAR_SECOND_ARG,
							THIRD_ARG, CAR_THIRD_ARG) == 1)
	{
		COMMAND = NO_INSTRUCTION;
	}
}

void 					choose_instruction(t_field *field, t_carriage *carriage, t_corewar *core)
{
	int 				check_jump;

	if (IS_VALID_COMMAND(COMMAND) == false)
	{
		move_carriage(field, 1, carriage);
		return ;
	}
	get_t_args(field, carriage);
	if (COMMAND == CW_ZJMP)
		check_jump = jump_if_carry_instruct(field, carriage);
	else if (COMMAND == CW_FORK || COMMAND == CW_LFORK)
		fork_instruct(field, carriage, &core->quant_carriages);
	else if (COMMAND == CW_LIVE)
		alive_instruct(field, carriage, core);
	else
		list_of_instructions(field, carriage);
	if (COMMAND != CW_ZJMP || check_jump == true)
	{
		move_carriage(field, (1 + get_indent(LIST_ARGUMENTS, 3,
			get_dir_bytes(COMMAND)) + get_codage(COMMAND)), carriage);
		carriage->arguments = (t_args){0, 0, {0, 0, 0}, 0, 0, 0};
	}
}

void 			do_process(t_corewar *core)
{
	unsigned 	qua_carriages;
	t_carriage	*carriage;

	qua_carriages = core->quant_carriages;
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
			choose_instruction(core->field, carriage, core);
			COMMAND = 0;
			CYCLES = 0;
		}
		carriage = carriage->next;
	}
}
