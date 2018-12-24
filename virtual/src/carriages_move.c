#include "../includes/corewar_header.h"

//alive and zjmp

void 	remove_carriage(t_field *field)
{
	field->carriages_on--;
	if (field->hex[0] == '0' && field->hex[1] == '1')
		field->is_alive = 0;
}

void 	place_carriage(t_field *field)
{
	field->carriages_on++;
	if (field->hex[0] == '0' && field->hex[1] == '1')
		field->is_alive = 1;
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
