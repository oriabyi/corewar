#include "../includes/corewar_header.h"

//alive and zjmp

void 	remove_carriage(t_field *field, unsigned id, int is_owned)
{
	if (is_owned == OWN)
	{
		field->champ_id = get_id_of_champ(field->old_owner);
		return;
	}
	field->champ_id = get_id_of_champ(id); // get pure id
	field->old_owner = field->champ_id;
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
