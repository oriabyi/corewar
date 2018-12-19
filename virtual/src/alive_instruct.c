#include "../includes/corewar_header.h"

void 	alive_instruct(t_cell *cell, t_bot *bot)
{
	unsigned 	t_dir;


	t_dir = (unsigned)get_arguments(cell, bot, 0x80, FIRST_ARG);

	cell[CUR_POS].last_owner = cell[CUR_POS].bot_id;

	cell[CUR_POS].bot_id =
			get_id_of_bot(cell[CUR_POS].bot_id) + DENOTE_ALIVE;
	cell[CUR_POS].time = SHOW_CHANGED_CYCLES;

	ALIVE = true;
}