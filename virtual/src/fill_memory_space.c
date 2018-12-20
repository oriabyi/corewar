#include "../includes/corewar_header.h"

void				fill_memory_space(t_bot *bots, t_field *field, int qua_bots)
{
	unsigned 		counter;
	unsigned 		bot_counter;
	unsigned 		num_of_bot;
	unsigned char	*seq;

	counter = 0;
	num_of_bot = 0;
	bot_counter = 0;
	seq = (unsigned char *)"0123456789abcdef";
	while (num_of_bot < qua_bots)
	{
		if (counter && counter % (MEM_SIZE / qua_bots) == 0)
		{
			if (++num_of_bot == qua_bots)
				break ;
			bot_counter = 0;
		}
		field[counter].val = bots[num_of_bot].exec_code[bot_counter];

		if (counter < bots[num_of_bot].size + (MEM_SIZE / qua_bots) * num_of_bot)
		{
			field[counter].bot_id = num_of_bot + COUNTING_FROM_ONE;
			field[counter].old_owner = field[counter].bot_id;
			field[counter].hex[0] = seq[bots[num_of_bot].exec_code[bot_counter] / 16];
			field[counter].hex[1] = seq[bots[num_of_bot].exec_code[bot_counter] % 16];
		}
		if (bots[num_of_bot].carriage &&
		((bots[num_of_bot].carriage->cur_coord == NOT_EXPOSED && num_of_bot) ||
											(counter == 0 && num_of_bot == 0)))
		{
			bots[num_of_bot].carriage->cur_coord = counter;
			field[counter].bot_id = num_of_bot + COUNTING_FROM_ONE + DENOTE_CARRIAGE;
		}
		bot_counter++;
		counter++;
	}
}