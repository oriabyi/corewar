#include "../includes/corewar_header.h"

int 	store_instruct(t_cell *cell, t_bot *bot) // label size == 4
{
	int 	argument;
	int 	t_reg_num;
	int 	step;
	ssize_t 	position;

	step = 1;
	argument = get_argument(cell, bot, step++);
	if (check_instruction_args(argument, (T_REG), (T_REG | T_IND), (NONE_ARG)) == ERROR)
		return (ERROR);

	t_reg_num = get_argument(cell, bot, step++);
	if (GET_SECOND_ARGUMENT(argument) == T_REG)
	{
		position = get_argument(cell, bot, step++);
		bot->carriage->registers[position] = bot->carriage->registers[t_reg_num];
	}
	else if (GET_SECOND_ARGUMENT(argument) == GET_T_IND_ARG(T_IND))
	{
		//delete (unsigned) in all cases like this
		position = get_arg_dir(cell, bot, &step, TWO_BYTES);
		position = correction_coordinates((position % IDX_MOD) + bot->carriage->cur_pos);

		write_in_cell(cell, (int)position, bot, t_reg_num);
	}

	move_carriage(cell, bot, step);
	return (0);
}