#include "../includes/corewar_header.h"

int 	jump_if_carry_instruct(t_field *field, t_bot *bot) // refactor this function !!! label = 2
{
	int 	jump;


	if (CARRY == 0)
	{
//		bot->carriage->flag
		return (1);
	}

	if (IDX_MOD)
	{
		jump = (short)get_arguments(field, bot, 0x80, FIRST_ARG);
	}


	field[CUR_COORD].bot_id = field[CUR_COORD].old_owner;


	CUR_COORD = (int)correction_coordinates(CUR_COORD + jump);

	if (field[CUR_COORD].hex[0] == '0' &&
		field[CUR_COORD].hex[1] == '1')
	{
		field[CUR_COORD].bot_id = bot->id + DENOTE_ALIVE;
	}
	else
	{
		field[CUR_COORD].bot_id = bot->id + DENOTE_CARRIAGE;
	}
	return (0);
}