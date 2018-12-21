#include "../includes/corewar_header.h"


int 			get_cycles(t_bot *bot)
{
	if (COMMAND == CW_LIVE)
		return (CW_LIVE_CYCLES);
	else if (COMMAND == CW_LD)
		return (CW_LD_CYCLES);
	else if (COMMAND == CW_ST)
		return(CW_ST_CYCLES);
	else if (COMMAND == CW_ADD)
		return (CW_ADD_CYCLES);
	else if (COMMAND == CW_SUB)
		return (CW_SUB_CYCLES);
	else if (COMMAND == CW_AND)
		return(CW_AND_CYCLES);
	else if (COMMAND == CW_OR)
		return(CW_OR_CYCLES);
	else if (COMMAND == CW_XOR)
		return(CW_XOR_CYCLES);
	else if (COMMAND == CW_ZJMP)
		return (CW_ZJMP_CYCLES);
	else if (COMMAND == CW_LDI)
		return (CW_LDI_CYCLES);
	else if (COMMAND == CW_STI)
		return (CW_STI_CYCLES);
	else if (COMMAND == CW_FORK)
		return (CW_FORK_CYCLES);
	else if (COMMAND == CW_LLD)
		return (CW_LLD_CYCLES);
	else if (COMMAND == CW_LLDI)
		return (CW_LLDI_CYCLES);
	else if (COMMAND == CW_LFORK)
		return (CW_LFORK_CYCLES);
	else if (COMMAND == CW_AFF)
		return (CW_AFF_CYCLES);
	else
		return (NO_INSTRUCTION);
}

int 			get_dir_bytes(unsigned command)
{
	if ((command >= CW_LIVE && command <= CW_XOR) ||
		command == CW_LLD || command == CW_AFF)
		return (FOUR_BYTES);
	else
		return (TWO_BYTES);
}


int			get_codage(unsigned command)
{
	if (command == CW_LIVE || command == CW_ZJMP ||
		command == CW_FORK || command == CW_LFORK)
	{
		return (false);
	}
	else
		return (true);
}



void					fill_old_owner(t_field *field, int coord)
{
	field[coord].old_owner = field[coord].bot_id;
}

void 					 denote_field(t_field *field, int coord)
{
	fill_old_owner(field, coord);
	if (field[coord].hex[0] == '0' && field[coord].hex[1] == '1')
		field[coord].bot_id =
				get_id_of_bot(field[coord].bot_id) + DENOTE_ALIVE;
	else
		field[coord].bot_id =
				get_id_of_bot(field[coord].bot_id) + DENOTE_CARRIAGE;
}

