#include "../includes/corewar_header.h"

int 	jump_if_carry_instruct(t_cell *cell, t_bot *bot) // refactor this function !!!
{
	int 	jump;

	if (bot->carriage->carry == 0)
	{
		move_carriage(cell, bot, 3);
		return (0);
	}

	if (IDX_MOD)
		jump = get_t_dir_two(cell, bot) % IDX_MOD;

//	if (cell[bot->carriage->cur_pos].bot_id >= DENOTE_CARRIAGE)
//		cell[bot->carriage->cur_pos].bot_id -= DENOTE_CARRIAGE; // make cariage_bot color just bot color

	cell[bot->carriage->cur_pos].bot_id = get_id_of_bot(cell[bot->carriage->cur_pos].bot_id);


	if (bot->carriage->cur_pos + jump >= MEM_SIZE)
		bot->carriage->cur_pos += jump - MEM_SIZE;
	else
		bot->carriage->cur_pos += jump;

	bot->carriage->cur_pos = (int)correction_coordinates(bot->carriage->cur_pos);

	if (cell[bot->carriage->cur_pos].hex[0] == '0' && cell[bot->carriage->cur_pos].hex[1] == '1')
		cell[bot->carriage->cur_pos].bot_id = bot->id + DENOTE_ALIVE; // make bot color -> cariage_bot
	else
		cell[bot->carriage->cur_pos].bot_id = bot->id + DENOTE_CARRIAGE; // make bot color -> cariage_bot
	return (0);
}