#include "../includes/corewar_header.h"

int 	jump_if_carry_instruct(t_cell *cell, t_bot *bot) // refactor this function !!! label = 2
{
	int 	jump;
	int step = 1;


	if (bot->carriage->carry == 0)
	{
		move_carriage(cell, bot, 3);
		return (0);
	}

	if (IDX_MOD)
	{
		jump = (short)get_arg_dir(cell, bot, &step, TWO_BYTES);
	}


	cell[bot->carriage->cur_pos].bot_id =
			get_id_of_bot(cell[bot->carriage->cur_pos].bot_id);


	if (bot->carriage->cur_pos + jump >= MEM_SIZE)
		bot->carriage->cur_pos += jump - MEM_SIZE;
	else
		bot->carriage->cur_pos += jump;

	bot->carriage->cur_pos =
			(int)correction_coordinates(bot->carriage->cur_pos);

	if (cell[bot->carriage->cur_pos].hex[0] == '0' &&
		cell[bot->carriage->cur_pos].hex[1] == '1')
	{
		cell[bot->carriage->cur_pos].bot_id = bot->id + DENOTE_ALIVE;
	}
	else
	{
		cell[bot->carriage->cur_pos].bot_id = bot->id + DENOTE_CARRIAGE;
	}
	return (0);
}