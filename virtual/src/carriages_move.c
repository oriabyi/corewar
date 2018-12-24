#include "../includes/corewar_header.h"

void 	remove_carriage(t_field *field)
{
	field->champ_id = get_id_of_champ(field->old_owner);
	if ((field->altered_cycles == ALTERED_FIELD || field->altered_cycles > 0) &&
		CR_IS_VIEW_ALTERED(field->champ_id) == false)
	{
		field->champ_id = get_id_of_champ(field->champ_id) + DENOTE_ALTERED;
	}
}

void 	place_carriage(t_field *field)
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


void 	move_carriage(t_field *field, int step, t_carriage *carriage)
{
	remove_carriage(&field[CUR_COORD]);
	CUR_COORD = (int)correction_coordinates(CUR_COORD + step);
	place_carriage(&field[CUR_COORD]);
	CUR_COORD = (int)correction_coordinates(CUR_COORD);
}


void 	change_carry_if_need(int coord, t_carriage *carriage)
{
	if (REG[coord] == 0)
		CARRY = true;
	else
		CARRY = false;
}
