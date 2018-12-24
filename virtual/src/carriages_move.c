#include "../includes/corewar_header.h"

//alive and zjmp

void 	remove_carriage(t_field *field, unsigned id)
{
	field->carriages_on--;


//	if (field->carriages_on == 0)
//	{
//		field->champ_id = field->old_owner;
//	}
	if (field->hex[0] == '0' && field->hex[1] == '1')
		field->is_alive = 0;
}

void 	place_carriage(t_field *field, unsigned id)
{
	field->carriages_on++;
	if (field->hex[0] == '0' && field->hex[1] == '1')
		field->is_alive = 1;
//	field->old_owner = field->champ_id;
//	denote_field(field, 0);
}


void 	move_carriage(t_field *field, unsigned id, int step, t_carriage *carriage)
{
	remove_carriage(&field[CUR_COORD], id);

	CUR_COORD = (int)correction_coordinates(CUR_COORD + step);

	place_carriage(&field[CUR_COORD], id);

	CUR_COORD = (int)correction_coordinates(CUR_COORD);
}


void 	change_carry_if_need(int coord, t_carriage *carriage)
{
	if (REG[coord] == 0)
		CARRY = true;
	else
		CARRY = false;
}
