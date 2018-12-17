#include "../includes/corewar_header.h"

int 	check_instruction_arg(int argument, int byte) // rename byte
{
	if (byte == (T_REG | T_DIR | T_IND))
		return (0);
	if (argument == T_REG && (byte & 1) == false)
		return (T_REG);
	if (argument == T_DIR && (byte & 2) == false)
		return (T_DIR);
	if (argument == GET_T_IND_ARG(T_IND) && (byte & 4) == false)
		return (T_IND);
	return (0);
}

int 	check_instruction_args(int argument, int first, int second, int third)
{
	int 		check_code;

	check_code = check_instruction_arg(GET_FIRST_ARGUMENT(argument), first);
	if (check_code == 0)
	{
		check_code =
				check_instruction_arg(GET_SECOND_ARGUMENT(argument), second);
		if (check_code == 0)
		{
			check_code =
					check_instruction_arg(GET_THIRD_ARGUMENT(argument), third);
		}
	}
	return (check_code ? ERROR : 0);
}

int 	help_fishka(int argument, int bytes)
{
	if (argument == T_REG)
		return (1);
	else if (argument == T_DIR)
		return (bytes);
	else if (argument == T_IND)
		return (2);
	return (0);
}

int 	fishka(int argument, int count_arguments, int bytes)
{
	int 	step;

	step = 0;
	step += help_fishka(check_instruction_arg(GET_FIRST_ARGUMENT(argument), NONE_ARG), bytes);
	if (count_arguments >= 2)
	{
		step += help_fishka(check_instruction_arg(GET_SECOND_ARGUMENT(argument), NONE_ARG), bytes);
		if (count_arguments == 3)
			step += help_fishka(check_instruction_arg(GET_THIRD_ARGUMENT(argument), NONE_ARG), bytes);
	}
	return (step);
}

int 		check_reg(t_bot *bot, int reg)
{
	if (CHECK_REG(reg) == false)
	{
		bot->carriage->invalid_reg = true;
		return (1);
	}
	return (0);
}

int 			check_t_regs(t_bot *bot, t_cell *cell, int step, unsigned char *t_reg)
{
	*t_reg = (unsigned char)get_argument(cell, bot, step + 1);
	if (check_reg(bot, (int)*t_reg))
		return (1);
	return (0);
}
