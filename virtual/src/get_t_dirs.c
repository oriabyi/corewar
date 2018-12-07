#include "../includes/corewar_header.h"

unsigned char 		get_t_dir_one(t_cell *cell, t_bot *bot)
{
	char 		*temp;
	unsigned char 		result;

	temp = ft_strdup((char *)cell[bot->carriage->cur_pos + 2].hex);
	free(temp);
	result = (unsigned char)ft_ahtoi(temp);
	return (result);
}

short 		get_t_dir_two(t_cell *cell, t_bot *bot)
{
	char 		*temp;
	short 		result;

	temp = ft_multjoin(2, (char *)cell[bot->carriage->cur_pos + 1].hex,
					   (char *)cell[bot->carriage->cur_pos + 2].hex);

	result = (short)ft_ahtoi(temp);
	free(temp);
	return (result);
}


unsigned int 	get_t_dir_four(t_cell *cell, t_bot *bot)
{
	char 		*temp;
	unsigned	result;

	temp = ft_multjoin(4, (char *)cell[bot->carriage->cur_pos + 2].hex,
					   (char *)cell[bot->carriage->cur_pos + 3].hex,
					   (char *)cell[bot->carriage->cur_pos + 4].hex,
					   (char *)cell[bot->carriage->cur_pos + 5].hex);
	result = ft_ahtoi(temp);
	free(temp);
	return (result);
}