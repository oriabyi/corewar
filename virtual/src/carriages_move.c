#include "../includes/corewar_header.h"

void 	remove_carriage(t_field *field, unsigned id, int is_owned)
{
	if (is_owned == OWN)
	{
		field->bot_id = field->old_owner;
		return;
	}
	if (field->sum_acts == 0)
	{
		field->bot_id = get_id_of_bot(id);
		field->old_owner = field->bot_id;
	}
	else
	{
		field->sum_acts--;
	}
}

void 	place_carriage(t_field *field, unsigned id, int is_owned)
{
	if (CR_IS_VIEW_CARRIAGE(field->bot_id))
	{
		field->sum_acts++;
	}
	else
	{
		field->old_owner = field->bot_id;
		denote_field(field, 0);
	}
}

void 	move_carriage(t_field *field, t_bot *bot, int step, int is_owned)
{
	remove_carriage(&field[CUR_COORD], bot->id, is_owned);
	CUR_COORD = (int)correction_coordinates(CUR_COORD + step);
	place_carriage(&field[CUR_COORD], bot->id, is_owned);

	CUR_COORD = (unsigned)correction_coordinates(CUR_COORD);
	if (bot->carriage->invalid_reg == true)
	{
		bot->carriage->invalid_reg = false;
	}
}


void 	change_carry_if_need(t_bot *bot, int coord)
{
	if (REG[coord] == 0)
		CARRY = true;
	else
		CARRY = false;
}
