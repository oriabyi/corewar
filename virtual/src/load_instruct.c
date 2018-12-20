#include "../includes/corewar_header.h"

void					load_instruct(t_field *field, t_bot *bot)
{
	int					argument;
	ssize_t				first_arg;
	unsigned char		second_arg;

	argument = get_argument(field, bot, 1);
	if (check_instruction_args(argument,
			(T_DIR | T_IND), T_REG, NONE_ARG) == ERROR)
	{
		return ;
	}
	first_arg = get_arguments(field, bot, argument, FIRST_ARG);
	second_arg = (unsigned char)get_arguments(field, bot, argument, SECOND_ARG);

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
	change_carry_if_need(bot, second_arg);
}
