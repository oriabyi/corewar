# include "../includes/corewar_header.h"


int 	check_instruction_args(unsigned char list_arguments, t_instructions *instr)
{
	int 		check_code;

	check_code = 0;

	if (list_arguments < 0x40)
		return (1);
	if (instr->qua_args)
	{
		check_code = check_instruction_arg(GET_FIRST_ARG(list_arguments),
				instr->have_to_have[FIRST_ARG]);
		if (check_code == 0 && instr->qua_args >= 2)
		{
			check_code = check_instruction_arg(GET_SECOND_ARG(list_arguments),
					instr->have_to_have[SECOND_ARG]);
			if (check_code == 0 && instr->qua_args >= 3)
			{
				check_code = check_instruction_arg(GET_THIRD_ARG(list_arguments),
						instr->have_to_have[THIRD_ARG]);
			}
		}
	}
	return (check_code ? 1 : 0);
}



int 					get_check_list_args(t_field *field, t_carriage *carriage, t_args *arguments)
{
	if (carriage->instr->codage == 1)
	{
		arguments->list_arguments = get_argument(field, CUR_COORD + 1);

		if (check_instruction_args(arguments->list_arguments, carriage->instr) == ERROR)
		{
			return (1);
		}
	}
	else
		arguments->list_arguments = (unsigned char)0x80;
	return (0);
}

void 					get_three_args(t_field *field, t_carriage *carriage, t_args *arguments)
{
	CAR_FIRST_ARG = get_arguments(field, arguments->list_arguments, FIRST_ARG, carriage);
	if (carriage->instr->qua_args >= 2)
	{
		CAR_SECOND_ARG = get_arguments(field, arguments->list_arguments, SECOND_ARG, carriage);
		if (carriage->instr->qua_args == 3)
		{
			CAR_THIRD_ARG = get_arguments(field, arguments->list_arguments, THIRD_ARG, carriage);
		}
	}
}

int 					check_regs_in_args(t_args *arguments)
{
	if (check_type_arguments(arguments, T_REG, 3,
							 FIRST_ARG, CAR_FIRST_ARG,
							 SECOND_ARG, CAR_SECOND_ARG,
							 THIRD_ARG, CAR_THIRD_ARG)
							 == ERROR)
	{
		return (1);
	}
	return (0);
}

int 					get_t_args(t_field *field, t_carriage *carriage, t_args *arguments)
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
