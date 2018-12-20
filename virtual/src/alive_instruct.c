#include "../includes/corewar_header.h"

void 	alive_instruct(t_field *field, t_bot *bot)
{
	unsigned 	t_dir;


	t_dir = (unsigned)get_arguments(field, bot, 0x80, FIRST_ARG);

	field[CUR_COORD].old_owner = field[CUR_COORD].bot_id;

	field[CUR_COORD].bot_id =
			get_id_of_bot(field[CUR_COORD].bot_id) + DENOTE_ALIVE;
	field[CUR_COORD].time = SHOW_CHANGED_CYCLES;

	ALIVE = true;
}