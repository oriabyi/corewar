#include "../includes/corewar_header.h"

void 	remove_carriage(t_field *field, unsigned id, int is_owned)
{
	if (is_owned == OWN)
	{
		field->champ_id = get_id_of_champ(field->old_owner);
		return;
	}
//	if (field->sum_acts == 0)
//	{
		field->champ_id = get_id_of_champ(id);
		field->old_owner = field->champ_id;
//	}
//	else
//	{
//		field->sum_acts--;
//	}
}

void 	place_carriage(t_field *field, unsigned id, int is_owned)
{
	if (CR_IS_VIEW_CARRIAGE(field->champ_id))
	{
		field->sum_acts++;
	}
	else
	{
		field->old_owner = field->champ_id;
		denote_field(field, 0);
	}
}

void 	move_carriage(t_field *field, unsigned id, int step, int is_owned, t_carriage *carriage)
{
	remove_carriage(&field[CUR_COORD], id, is_owned);

	CUR_COORD = (int)correction_coordinates(CUR_COORD + step);

	place_carriage(&field[CUR_COORD], id, is_owned);

	CUR_COORD = (int)correction_coordinates(CUR_COORD);
}


void 	change_carry_if_need(int coord, t_carriage *carriage)
{
	if (REG[coord] == 0)
		CARRY = true;
	else
		CARRY = false;
}
