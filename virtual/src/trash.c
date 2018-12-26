#include "../includes/corewar_header.h"


int 			get_cycles(t_carriage *carriage)
{
	if (COMMAND == CW_SUB || COMMAND == CW_ADD ||
		COMMAND == CW_LLD || COMMAND == CW_LIVE)
		return (10);
	else if (COMMAND == CW_LD || COMMAND == CW_ST)
		return (5);
	else if (COMMAND == CW_OR || COMMAND == CW_AND || COMMAND == CW_XOR)
		return(6);
	else if (COMMAND == CW_ZJMP)
		return (CW_ZJMP_CYCLES);
	else if (COMMAND == CW_LDI || COMMAND == CW_STI)
		return (25);
	else if (COMMAND == CW_FORK)
		return (CW_FORK_CYCLES);
	else if (COMMAND == CW_LLDI)
		return (CW_LLDI_CYCLES);
	else if (COMMAND == CW_LFORK)
		return (CW_LFORK_CYCLES);
	else if (COMMAND == CW_AFF)
		return (CW_AFF_CYCLES);
	else
		return (NO_INSTRUCTION);
}

void 			insert(t_args *arguments, unsigned first, unsigned second,
					   unsigned third)
{
	if ((arguments->have_to_have[0] = first))
		arguments->qua_args++;
	if ((arguments->have_to_have[1] = second))
		arguments->qua_args++;
	if ((arguments->have_to_have[2] = third))
		arguments->qua_args++;
}


void 			get_arguments_table(t_carriage *carriage, t_args *arguments)
{
	if (COMMAND == CW_LIVE || COMMAND == CW_ZJMP ||
		COMMAND == CW_FORK || COMMAND == CW_LFORK)
	{
		insert(arguments, NONE_ARG, NONE_ARG, NONE_ARG);
	}
	else if (COMMAND == CW_LD || COMMAND == CW_LLD)
		insert(arguments, T_DIR | T_IND, T_REG, NONE_ARG);
	else if (COMMAND == CW_ST)
		insert(arguments, T_REG, T_REG | T_IND, NONE_ARG);
	else if (COMMAND == CW_ADD || COMMAND == CW_SUB)
		insert(arguments, T_REG, T_REG, T_REG);
	else if (COMMAND == CW_AND || COMMAND == CW_OR || COMMAND == CW_XOR)
	{
		insert(arguments,
				T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG);
	}
	else if (COMMAND == CW_LDI || COMMAND == CW_LLDI)
	{
		insert(arguments,
				T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG);
	}
	else if (COMMAND == CW_STI)
		insert(arguments, T_REG, T_REG | T_DIR, T_REG | T_DIR);
	else if (COMMAND == CW_AFF)
		insert(arguments, T_REG, NONE_ARG, NONE_ARG);
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

void 					 denote_field(t_field *field, int coord)
{
	field[coord].old_owner = field[coord].champ_id;
	if (field[coord].hex[0] == '0' && field[coord].hex[1] == '1')
		field[coord].is_alive = 1;
}

