#include "../includes/corewar_header.h"

void 	remove_carriage(t_cell *cell, unsigned id, int is_owned)
{
	if (is_owned == OWN)
	{
		cell->bot_id = cell->last_owner;
		return;
	}
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

void 	place_carriage(t_cell *cell, unsigned id, int is_owned)
{
	if (CR_IS_VIEW_CARRIAGE(cell->bot_id))
	{
		cell->sum_acts++;
	}
	else
	{
		cell->last_owner = cell->bot_id;
		cell->bot_id = get_id_of_bot(id);
		if (cell->hex[0] == '0' && cell->hex[1] == '1')
			cell->bot_id += DENOTE_ALIVE;
		else
			cell->bot_id += DENOTE_CARRIAGE;
	}
}

int 	move_carriage(t_cell *cell, t_bot *bot, int step, int is_owned)
{
	remove_carriage(&cell[bot->carriage->cur_pos], bot->id, is_owned);
	bot->carriage->cur_pos = (int)correction_coordinates(bot->carriage->cur_pos + step);
	place_carriage(&cell[bot->carriage->cur_pos], bot->id, is_owned);
	if (bot->carriage->invalid_reg == true)
	{
		bot->carriage->invalid_reg = false;
		return (1);
	}
	return (0);
}

void 	change_carry_if_need(t_bot *bot, int position)
{
	if (bot->carriage->registers[position] == 0)
		bot->carriage->carry = true;
	else
		bot->carriage->carry = false;
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

int 		check_reg(t_bot *bot, int reg)
{
	if (CHECK_REG(reg) == false)
	{
		bot->carriage->invalid_reg = true;
		return (1);
	}
	return (0);
}

int			load_instruct(t_cell *cell, t_bot *bot) // label size == 4
{
	int 	argument;
	int 	step;
	int 	t_reg;
	unsigned reg_value;

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
		reg_value = (unsigned)get_arg_dir(cell, bot, &step, FOUR_BYTES);
	}
	else if (GET_FIRST_ARGUMENT(argument) == GET_THIRD_ARGUMENT(T_IND))
	{
		t_reg = get_argument(cell, bot, step + TWO_BYTES);
		reg_value =	(unsigned)get_arg_ind(cell, bot, &step, IDX_MOD_ON);
	}
	if (check_reg(bot, t_reg) == 1)
	{
		return (move_carriage(cell, bot, fishka(argument, 2, FOUR_BYTES) + step, NOT_OWN));
	}
	bot->carriage->registers[t_reg] = reg_value;
	step++;
	change_carry_if_need(bot, t_reg);
	move_carriage(cell, bot, step, NOT_OWN);
	return (0);
}
