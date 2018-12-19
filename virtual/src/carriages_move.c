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

void 	move_carriage(t_cell *cell, t_bot *bot, int step, int is_owned)
{
	remove_carriage(&cell[CUR_POS], bot->id, is_owned);
	CUR_POS = (int)correction_coordinates(CUR_POS + step);
	place_carriage(&cell[CUR_POS], bot->id, is_owned);

	CUR_POS = (unsigned)correction_coordinates(CUR_POS);
	if (bot->carriage->invalid_reg == true)
	{
		bot->carriage->invalid_reg = false;
	}
}


void 	change_carry_if_need(t_bot *bot, int position)
{
	if (REG[position] == 0)
		CARRY = true;
	else
		CARRY = false;
}
