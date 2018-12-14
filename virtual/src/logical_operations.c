#include "../includes/corewar_header.h"

ssize_t				which_operation_needs(ssize_t a, ssize_t b, int command)
{
	if (command == CW_AND)
		return (a & b);
	else if (command == CW_OR)
		return (a | b);
	else if (command == CW_XOR)
		return (a ^ b);
	else if (command == CW_ADD)
		return (a + b);
	else if (command == CW_SUB)
		return (a - b);
	return (0);
}

int					get_args_log_operations(t_cell *cell, t_bot *bot,
													int *step, ssize_t *vessel)
{
	int				argument;

	*step = 1;
	*vessel = 0;
	argument = get_argument(cell, bot, (*step)++);
	if (check_instruction_args(argument,
			(T_REG | T_DIR | T_IND),(T_REG | T_DIR | T_IND), T_REG) == ERROR)
	{
		move_carriage(cell, bot, fishka(argument, 3, FOUR_BYTES) + *step);
		return (ERROR);
	}
	if (GET_FIRST_ARGUMENT(argument) == T_REG)
		*vessel = get_arg_reg(cell, bot, step);
	else if (GET_FIRST_ARGUMENT(argument) == T_DIR)
		*vessel = get_arg_dir(cell, bot, step, FOUR_BYTES);
	else if (GET_FIRST_ARGUMENT(argument) == GET_T_IND_ARG(T_IND))
		*vessel = get_arg_ind(cell, bot, step, IDX_MOD_ON);
	if (GET_SECOND_ARGUMENT(argument) == T_REG)
		*vessel = which_operation_needs(*vessel,
			(get_arg_reg(cell, bot, step)), bot->carriage->command);
	else if (GET_SECOND_ARGUMENT(argument) == T_DIR)
		*vessel = which_operation_needs(*vessel,
			(get_arg_dir(cell, bot, step, FOUR_BYTES)), bot->carriage->command);
	else if (GET_SECOND_ARGUMENT(argument) == GET_T_IND_ARG(T_IND))
		*vessel = which_operation_needs(*vessel,
			(get_arg_ind(cell, bot, step, IDX_MOD_ON)), bot->carriage->command);
	return (0);
}

int					logical_operations(t_cell *cell, t_bot *bot)
{
	int				t_reg;
	int				step;
	ssize_t			vessel;

	if (get_args_log_operations(cell, bot, &step, &vessel) == ERROR)
		return (ERROR);
	t_reg = (unsigned char)get_dir(cell, bot, step, ONE_BYTE);
	step += ONE_BYTE;
	bot->carriage->registers[t_reg] = (unsigned)vessel;
	move_carriage(cell, bot, step);
	change_carry_if_need(bot, t_reg);
	return (0);
}
