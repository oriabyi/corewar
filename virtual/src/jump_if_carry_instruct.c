#include "../includes/corewar_header.h"

int 	jump_if_carry_instruct(t_field *field, t_bot *bot)
{
	int 	jump;

	if (CARRY == 0)
	{
		return (1);
	}
	jump = (short)get_arguments(field, bot, 0x80, FIRST_ARG);
	move_carriage(field, bot, jump, NOT_OWN);
	denote_field(field, CUR_COORD);
	return (0);
}