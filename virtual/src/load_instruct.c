#include "../includes/corewar_header.h"

void 	remove_carriage(t_cell *cell, unsigned id)
{
	if (cell->sum_acts == 0)
	{
		cell->bot_id = get_id_of_bot(id);
		cell->last_owner = cell->bot_id;
	}
	else
	{
		cell->sum_acts--;
	}
}

void 	place_carriage(t_cell *cell, unsigned id)
{
	if (CR_IS_VIEW_CARRIAGE(cell->bot_id))
	{
		cell->sum_acts++;
	}
	else
	{
		cell->bot_id = get_id_of_bot(id);
		if (cell->hex[0] == '0' && cell->hex[1] == '1')
			cell->bot_id += DENOTE_ALIVE;
		else
			cell->bot_id += DENOTE_CARRIAGE;
	}
}

void 	move_carriage(t_cell *cell, t_bot *bot, int step, int is_owned)
{
	remove_carriage(&cell[bot->carriage->cur_pos], bot->id);
	bot->carriage->cur_pos = (int)correction_coordinates(bot->carriage->cur_pos + step);
	place_carriage(&cell[bot->carriage->cur_pos], bot->id);
}

void 	change_carry_if_need(t_bot *bot, int position)
{
	if (bot->carriage->registers[position] == 0)
		bot->carriage->carry = TRUE;
	else
		bot->carriage->carry = FALSE;
}


ssize_t 		get_dir(t_cell *cell, t_bot *bot, int handicap, int bytes)
{
	int 		temp_bytes;
	char 		*temp;
	ssize_t		result;

	result = 0;
	temp = ft_strdup("");
	temp_bytes = bytes;
	while (temp_bytes--)
	{
		temp = ft_multjoinfr(3, NULL, temp,
				(char *)cell[bot->carriage->cur_pos + handicap].hex);
		handicap++;
	}
	if (bytes == ONE_BYTE)
		result = (unsigned char)ft_ahtoi(temp);
	else if (bytes == TWO_BYTES)
		result = (short)ft_ahtoi(temp);
	else if (bytes == FOUR_BYTES)
		result = ft_ahtoi(temp);

	free(temp);
	return (result);
}

int			load_instruct(t_cell *cell, t_bot *bot) // label size == 4
{
	int 	argument;
	int 	step;
	int 	t_reg;

	step = 1;
	t_reg = 0;
	argument = get_argument(cell, bot, step++);
	if (check_instruction_args(argument,
			(T_DIR | T_IND), T_REG, NONE_ARG) == ERROR)
	{
		move_carriage(cell, bot, fishka(argument, 2, FOUR_BYTES) + step, NOT_OWN);
		return (ERROR);
	}

	if (GET_FIRST_ARGUMENT(argument) == T_DIR)
	{
		t_reg = get_argument(cell, bot, step + FOUR_BYTES);
		bot->carriage->registers[t_reg] =
							(unsigned)get_arg_dir(cell, bot, &step, FOUR_BYTES);
	}
	else if (GET_FIRST_ARGUMENT(argument) == GET_THIRD_ARGUMENT(T_IND))
	{
		t_reg = get_argument(cell, bot, step + TWO_BYTES);
		bot->carriage->registers[t_reg] =
							(unsigned)get_arg_ind(cell, bot, &step, IDX_MOD_ON);
	}
	step++;
	change_carry_if_need(bot, t_reg);
	move_carriage(cell, bot, step, NOT_OWN);
	return (0);
}
