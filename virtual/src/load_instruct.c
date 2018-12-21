#include "../includes/corewar_header.h"

void					load_instruct(t_field *field, t_carriage *carriage, unsigned char argument)
{
	ssize_t				first_arg;
	unsigned char		second_arg;

	if (check_instruction_args(argument,
			(T_DIR | T_IND), T_REG, NONE_ARG) == ERROR)
	{
		return ;
	}
	first_arg = get_arguments(field, argument, FIRST_ARG, carriage);
	second_arg = (unsigned char)get_arguments(field, argument, SECOND_ARG, carriage);

	if (check_reg(second_arg) == 1)
	{
		return ;
	}

	if (GET_SECOND_ARGUMENT(argument) == GET_T_IND_ARG(T_IND) &&
			COMMAND == CW_LD)
	{
		first_arg %= IDX_MOD;
	}

	REG[second_arg] = (unsigned)first_arg;
	change_carry_if_need(second_arg, carriage);
}
