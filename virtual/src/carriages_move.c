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
