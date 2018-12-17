# include "../includes/corewar_header.h"

int				add_sub_instructs(t_cell *cell, t_bot *bot)
{
	int			step;
	unsigned char			third;
	unsigned char 		second;
	unsigned char	first;

	step = 1;
	first = (unsigned char)get_argument(cell, bot, step);

	if (check_instruction_args(first, T_REG, T_REG, T_REG) == ERROR ||
			check_t_regs(bot, cell, (step + 1), &first) ||
			check_t_regs(bot, cell, (step + 2), &second) ||
			check_t_regs(bot, cell, (step + 3), &third))
	{
		move_carriage(cell, bot, fishka(first, 3, FOUR_BYTES) + step + 1, NOT_OWN); //mb check and change
		return (ERROR);
	}
	bot->carriage->registers[third] =
			(unsigned)which_operation_needs(
					(ssize_t)bot->carriage->registers[first],
					(ssize_t)bot->carriage->registers[second],
					bot->carriage->command);
	step += 3;
	change_carry_if_need(bot, third);
	move_carriage(cell, bot, step + 1, NOT_OWN);
	return (0);
}
