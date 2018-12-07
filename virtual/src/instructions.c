#include "../includes/corewar_header.h"

//handicap
//static int 	get_argument_(int num, int bytes)
//{
//	int bits;
//
//	bits = bytes * 8 - 1;
//	while (num > bits)
//		num >>= 4;
//	return (num);
//}

int 	t_load_instr(t_cell *cell, t_bot *bot, int t_reg, int handicap) // swap this with get_t_dir_four
{
	char 		*temp;

	temp = ft_multjoin(4, (char *)cell[bot->carriage->cur_pos + (handicap + 0)].hex,
					   (char *)cell[bot->carriage->cur_pos + (handicap + 1)].hex,
					   (char *)cell[bot->carriage->cur_pos + (handicap + 2)].hex,
					   (char *)cell[bot->carriage->cur_pos + (handicap + 3)].hex);
	bot->carriage->registers[t_reg] = ft_ahtoi(temp);
	free(temp);
	return (5);
}
