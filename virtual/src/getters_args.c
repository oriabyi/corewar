#include "../includes/corewar_header.h"


ssize_t		get_arg_reg(t_cell *cell, t_bot *bot, int *step)
{
	int 		t_reg;
	ssize_t 	first_agg;

	t_reg = (unsigned char)get_dir(cell, bot, *step, ONE_BYTE);
	first_agg = (int)bot->carriage->registers[t_reg];
	*step += ONE_BYTE;

	return (first_agg);
}

ssize_t		get_arg_dir(t_cell *cell, t_bot *bot, int *step, int bytes)
{
	ssize_t 	first_agg;

	first_agg = get_dir(cell, bot, *step, bytes);
	*step += bytes;

	return (first_agg);
}

ssize_t		get_arg_ind(t_cell *cell, t_bot *bot, int *step, int code)
{
	int 	t_ind;
	ssize_t first_agg;


	t_ind = (short)get_dir(cell, bot, *step, TWO_BYTES);

	if (code == IDX_MOD_ON)
		t_ind %= IDX_MOD;
	t_ind = (unsigned)get_dir(cell, bot, (*step + t_ind + bot->carriage->cur_pos), FOUR_BYTES);
//	if (code == IDX_MOD_ON)
//		t_ind %= IDX_MOD;
	*step += TWO_BYTES;

	return (t_ind);
}
