#include "../includes/corewar_header.h"


int 			get_cycles(t_bot *bot)
{
	if (bot->carriage->command == CW_LIVE)
		return (CW_LIVE_CYCLES);
	else if (bot->carriage->command == CW_LD)
		return (CW_LD_CYCLES);
	else if (bot->carriage->command == CW_ST)
		return(CW_ST_CYCLES);
	else if (bot->carriage->command == CW_ADD)
		return (CW_ADD_CYCLES);
	else if (bot->carriage->command == CW_SUB)
		return (CW_SUB_CYCLES);
	else if (bot->carriage->command == CW_AND)
		return(CW_AND_CYCLES);
	else if (bot->carriage->command == CW_OR)
		return(CW_OR_CYCLES);
	else if (bot->carriage->command == CW_XOR)
		return(CW_XOR_CYCLES);
	else if (bot->carriage->command == CW_ZJMP)
		return (CW_ZJMP_CYCLES);
	else if (bot->carriage->command == CW_LDI)
		return (CW_LDI_CYCLES);
	else if (bot->carriage->command == CW_STI)
		return (CW_STI_CYCLES);
	else if (bot->carriage->command == CW_FORK)
		return (CW_FORK_CYCLES);
	else if (bot->carriage->command == CW_LLD)
		return (CW_LLD_CYCLES);
	else if (bot->carriage->command == CW_LLDI)
		return (CW_LLDI_CYCLES);
	else if (bot->carriage->command == CW_LFORK)
		return (CW_LFORK_CYCLES);
	else if (bot->carriage->command == CW_AFF)
		return (CW_AFF_CYCLES);
	else
		return (NO_INSTRUCTION);
}