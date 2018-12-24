#include "../includes/corewar_header.h"

void				fill_memory_space(t_champ *champs, t_field *field, int qua_champs)
{
	unsigned 		counter;
	unsigned 		champ_counter;
	unsigned 		num_of_champ;
	unsigned char	*seq;

	counter = 0;
	num_of_champ = 0;
	champ_counter = 0;
	seq = (unsigned char *)"0123456789abcdef";
	while (num_of_champ < qua_champs)
	{
		if (counter && counter % (MEM_SIZE / qua_champs) == 0)
		{
			if (++num_of_champ == qua_champs)
				break ;
			champ_counter = 0;
		}
		if (counter < champs[num_of_champ].size + (MEM_SIZE / qua_champs) * num_of_champ)
		{
			field[counter].champ_id = num_of_champ + COUNTING_FROM_ONE;
			field[counter].old_owner = field[counter].champ_id;
			field[counter].hex[0] = seq[champs[num_of_champ].exec_code[champ_counter] / 16];
			field[counter].hex[1] = seq[champs[num_of_champ].exec_code[champ_counter] % 16];
		}
		if (champs[num_of_champ].carriage &&
		((champs[num_of_champ].carriage->cur_coord == NOT_EXPOSED && num_of_champ) ||
											(counter == 0 && num_of_champ == 0)))
		{
			champs[num_of_champ].carriage->cur_coord = counter;
			field[counter].champ_id = num_of_champ + COUNTING_FROM_ONE + DENOTE_CARRIAGE;
			field[counter].carriages_on++;
		}
		champ_counter++;
		counter++;
	}
}