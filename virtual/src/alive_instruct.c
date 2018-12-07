#include "../includes/corewar_header.h"

int 	alive_instruct(t_cell *cell, t_bot *bot)
{
	cell[bot->carriage->cur_pos].bot_id = get_id_of_bot(cell[bot->carriage->cur_pos].bot_id) + DENOTE_ALIVE;
	cell[bot->carriage->cur_pos].time = SHOW_CHANGED_CYCLES;
	bot->carriage->alive = TRUE;
	move_carriage(cell, bot, 5);

	return (0);
}