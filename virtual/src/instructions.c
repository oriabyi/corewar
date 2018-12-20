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

int 	t_load_instr(t_field *field, t_bot *bot, int t_reg, int handicap) // swap this with get_t_dir_four
{
	char 		*temp;

	temp = ft_multjoin(4, (char *)field[CUR_COORD + (handicap + 0)].hex,
					   (char *)field[CUR_COORD + (handicap + 1)].hex,
					   (char *)field[CUR_COORD + (handicap + 2)].hex,
					   (char *)field[CUR_COORD + (handicap + 3)].hex);
	REG[t_reg] = ft_ahtoi(temp);
	free(temp);
	return (5);
}
