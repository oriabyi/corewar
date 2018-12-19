#include "../includes/corewar_header.h"

int 	jump_if_carry_instruct(t_cell *cell, t_bot *bot) // refactor this function !!! label = 2
{
	int 	jump;


	if (CARRY == 0)
	{
//		bot->carriage->flag
		return (1);
	}

	if (IDX_MOD)
	{
		jump = (short)get_arguments(cell, bot, 0x80, FIRST_ARG);
	}


	cell[CUR_POS].bot_id = cell[CUR_POS].last_owner;


	CUR_POS = (int)correction_coordinates(CUR_POS + jump);

	if (cell[CUR_POS].hex[0] == '0' &&
		cell[CUR_POS].hex[1] == '1')
	{
		cell[CUR_POS].bot_id = bot->id + DENOTE_ALIVE;
	}
	else
	{
		cell[CUR_POS].bot_id = bot->id + DENOTE_CARRIAGE;
	}
	return (0);
}