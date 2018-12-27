#include "../includes/corewar_header.h"

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
		instructions->bytes_dir = FOUR_BYTES;
	else
		instructions->bytes_dir = TWO_BYTES;
}


void 			fill_aicommand(t_instructions *instructions, unsigned code)
{
	instructions->i_command = code;
	instructions->a_byte = get_hex_by_int_byte(code, 2);
}

void 			init_instructions(t_instructions *instructions)
{
	unsigned 		pos_instr;

	pos_instr = 0;
	while (pos_instr < QUA_INSTRUCTIONS)
	{
		fill_aicommand(&instructions[pos_instr], (pos_instr + 1));
		fill_cycles(&instructions[pos_instr], instructions[pos_instr].i_command);
		fill_codage(&instructions[pos_instr], instructions[pos_instr].i_command);
		fill_dir_bytes(&instructions[pos_instr], instructions[pos_instr].i_command);
		pos_instr++;
	}
}

t_instructions	*get_instruction_by_id(t_instructions *instructions, unsigned id)
{
	int 		counter;

	counter = 0;
	while (counter < QUA_INSTRUCTIONS)
	{
		if (instructions[counter].i_command == id)
			return (&instructions[counter]);
		counter++;
	}
	return (NULL);
}