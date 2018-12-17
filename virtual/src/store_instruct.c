#include "../includes/corewar_header.h"

int 	store_instruct(t_cell *cell, t_bot *bot) // label size == 4
{
	int 	argument;
	int 	t_reg_num;
	int 	step;
	ssize_t 	position;

	step = 1;
	argument = get_argument(cell, bot, step++);
	t_reg_num = get_argument(cell, bot, step++);
	if (check_reg(bot, t_reg_num) || check_instruction_args(argument,
			(T_REG), (T_REG | T_IND), (NONE_ARG)) == ERROR)
	{
		move_carriage(cell, bot, fishka(argument, 2, FOUR_BYTES) + step, NOT_OWN);
		return (ERROR);
	}

	if (GET_SECOND_ARGUMENT(argument) == T_REG)
	{
		position = get_argument(cell, bot, step++);
		bot->carriage->registers[position] =
											bot->carriage->registers[t_reg_num];
		if (check_reg(bot, (int)position))
			return (move_carriage(cell, bot, fishka(argument, 2, FOUR_BYTES) + step, NOT_OWN));
	}
	else if (GET_SECOND_ARGUMENT(argument) == GET_T_IND_ARG(T_IND))
	{
		position = correction_coordinates(
				(get_arg_dir(cell, bot, &step, TWO_BYTES) % IDX_MOD) +
														bot->carriage->cur_pos);
		write_in_cell(cell, (int)position, bot, t_reg_num);
	}

	move_carriage(cell, bot, step, NOT_OWN);
	return (0);
}