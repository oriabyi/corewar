# include "../includes/corewar_header.h"

void					add_sub_instructs(t_field *field, t_carriage *carriage,
														unsigned char argument)
{
	unsigned char		third_arg;
	unsigned char 		second_arg;
	unsigned char		first_arg;

	if (check_instruction_args(argument, T_REG, T_REG, T_REG) == ERROR)
	{
		return ;
	}
	first_arg = (unsigned char)get_arguments(field,
			argument, FIRST_ARG, carriage);
	second_arg = (unsigned char)get_arguments(field,
			argument, SECOND_ARG, carriage);
	third_arg = (unsigned char)get_arguments(field,
			argument, THIRD_ARG, carriage);
	if (check_type_arguments(argument, T_REG, 3,
					0, first_arg, 1, second_arg, 2, third_arg) == 1)
	{
		return ;
	}
	REG[third_arg] =
			which_operation_needs(REG[first_arg], REG[second_arg], COMMAND);
	change_carry_if_need(third_arg, carriage);
}
