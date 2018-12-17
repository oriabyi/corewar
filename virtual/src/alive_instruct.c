#include "../includes/corewar_header.h"

int 	alive_instruct(t_cell *cell, t_bot *bot)
{
	int 		argument;
	int 		step;
	unsigned 	t_dir;

	step = 1;
	t_dir = (unsigned)get_arg_dir(cell, bot, &step, FOUR_BYTES);

	cell[bot->carriage->cur_pos].bot_id =
			get_id_of_bot(cell[bot->carriage->cur_pos].bot_id) + DENOTE_ALIVE;
	cell[bot->carriage->cur_pos].time = SHOW_CHANGED_CYCLES;
	bot->carriage->alive = true;
	move_carriage(cell, bot, 5, NOT_OWN);
	return (0);
}