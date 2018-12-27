#include "../includes/corewar_header.h"


void 			insert(t_instructions *instructions, unsigned first, unsigned second,
					   unsigned third)
{
	if ((instructions->desired[0] = first))
	{
		instructions->qua_args++;
		if ((instructions->desired[1] = second))
		{
			instructions->qua_args++;
			if ((instructions->desired[2] = third))
				instructions->qua_args++;
		}
	}
}

void 			fill_have_to_have(t_instructions *instructions, unsigned command)
{
	if (command == CW_LIVE || command == CW_ZJMP ||
		command == CW_FORK || command == CW_LFORK)
	{
		insert(instructions, NONE_ARG, NONE_ARG, NONE_ARG);
	}
	else if (command == CW_LD || command == CW_LLD)
		insert(instructions, T_DIR | T_IND, T_REG, NONE_ARG);
	else if (command == CW_ST)
		insert(instructions, T_REG, T_REG | T_IND, NONE_ARG);
	else if (command == CW_ADD || command == CW_SUB)
		insert(instructions, T_REG, T_REG, T_REG);
	else if (command == CW_AND || command == CW_OR || command == CW_XOR)
	{
		insert(instructions,
			   T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG);
	}
	else if (command == CW_LDI || command == CW_LLDI)
	{
		insert(instructions,
			   T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG);
	}
	else if (command == CW_STI)
		insert(instructions, T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR);
	else if (command == CW_AFF)
		insert(instructions, T_REG, NONE_ARG, NONE_ARG);
}


void 			fill_cycles(t_instructions *instructions, unsigned command)
{
	if (command == CW_SUB || command == CW_ADD ||
		command == CW_LLD || command == CW_LIVE)
		instructions->cycles = 10;
	else if (command == CW_LD || command == CW_ST)
		instructions->cycles = 5;
	else if (command == CW_OR || command == CW_AND || command == CW_XOR)
		instructions->cycles = 6;
	else if (command == CW_ZJMP)
		instructions->cycles = 20;
	else if (command == CW_LDI || command == CW_STI)
		instructions->cycles =  25;
	else if (command == CW_FORK)
		instructions->cycles = 800;
	else if (command == CW_LLDI)
		instructions->cycles = 50;
	else if (command == CW_LFORK)
		instructions->cycles = 1000;
	else if (command == CW_AFF)
		instructions->cycles = 2;
}

void 			fill_codage(t_instructions *instructions, unsigned command)
{
	if (command == CW_LIVE || command == CW_ZJMP ||
		command == CW_FORK || command == CW_LFORK)
	{
		instructions->codage = 0;
	}
	else
		instructions->codage = 1;
}

void 			fill_dir_bytes(t_instructions *instructions, unsigned command)
{
	if ((command >= CW_LIVE && command <= CW_XOR) ||
		command == CW_LLD || command == CW_AFF)
		instructions->label_size = FOUR_BYTES;
	else
		instructions->label_size = TWO_BYTES;
}

void 			init_instructions(t_instructions *instructions)
{
	unsigned 		pos_instr;

	pos_instr = 0;
	while (pos_instr < QUA_INSTRUCTIONS)
	{
		instructions[pos_instr].command = pos_instr + 1;
		fill_cycles(&instructions[pos_instr], instructions[pos_instr].command);
		fill_codage(&instructions[pos_instr], instructions[pos_instr].command);
		fill_dir_bytes(&instructions[pos_instr], instructions[pos_instr].command);
		fill_have_to_have(&instructions[pos_instr], instructions[pos_instr].command);
		pos_instr++;
	}
}

t_instructions	*get_instruction_by_id(t_instructions *instructions, unsigned id)
{
	int 		counter;

	counter = 0;
	while (counter < QUA_INSTRUCTIONS)
	{
		if (instructions[counter].command == id)
			return (&instructions[counter]);
		counter++;
	}
	return (NULL);
}