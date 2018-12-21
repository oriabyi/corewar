#include "../includes/corewar_header.h"

int 	jump_if_carry_instruct(t_field *field, t_bot *bot) // refactor this function !!! label = 2
{
	int 	jump;

	if (CARRY == 0)
	{
		return (1);
	}
	jump = (short)get_arguments(field, bot, 0x80, FIRST_ARG);
	fill_old_owner(field, CUR_COORD);
	CUR_COORD = (int)correction_coordinates(CUR_COORD + jump);
	denote_field(field, CUR_COORD);
	return (0);
}