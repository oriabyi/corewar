# include "../includes/corewar_header.h"

void					add_sub_instructs(t_field *field, t_bot *bot)
{
	unsigned char		third_arg;
	unsigned char 		second_arg;
	unsigned char		first_arg;
	unsigned char		argument;

	argument = get_argument(field, bot, 1);

	if (check_instruction_args(argument, T_REG, T_REG, T_REG) == ERROR)
	{
		return ;
	}
	first_arg = (unsigned char)get_arguments(field, bot, argument, FIRST_ARG);
	second_arg = (unsigned char)get_arguments(field, bot, argument, SECOND_ARG);
	third_arg = (unsigned char)get_arguments(field, bot, argument, THIRD_ARG);

	if (check_type_arguments(argument, T_REG, 3, 0, first_arg, 1, second_arg, 2, third_arg) == 1)
	{
		return ;
	}

	REG[third_arg] = which_operation_needs(REG[first_arg], REG[second_arg], COMMAND);
	change_carry_if_need(bot, third_arg);
}
