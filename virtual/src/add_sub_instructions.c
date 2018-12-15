# include "../includes/corewar_header.h"

int				add_sub_instructs(t_cell *cell, t_bot *bot)
{
	int			argument;
	int			step;
	int			pos_in_reg;

	step = 1;
	argument = get_argument(cell, bot, step);
	if (check_instruction_args(argument, T_REG, T_REG, T_REG) == ERROR)
	{
		move_carriage(cell, bot, fishka(argument, 3, FOUR_BYTES) + step + 1); //mb check and change
		return (ERROR);
	}

	pos_in_reg = get_argument(cell, bot, (step + 3));
	bot->carriage->registers[pos_in_reg] =
			(unsigned)which_operation_needs(
					(ssize_t)bot->carriage->registers[
							(unsigned long)get_argument(cell, bot, step + 1)],
					(ssize_t)bot->carriage->registers[
							(unsigned long)get_argument(cell, bot, step + 2)],
					bot->carriage->command);
	step += 3;
	change_carry_if_need(bot, pos_in_reg);
	move_carriage(cell, bot, step + 1);
	return (0);
}
