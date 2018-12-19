#include "../includes/corewar_header.h"


unsigned		which_instruction(char *command)
{
	unsigned 	code_instruction;
	char		instruction[3];

	code_instruction = 1;
	ft_strcpy(instruction, "01");
	while (ft_strcmp(command, (char *)instruction) && code_instruction < 17)
	{
		if (instruction[0] == '0' && instruction[1] < '9')
			(instruction[1])++;
		else if (instruction[0] == '0' && instruction[1] == '9')
			instruction[1] = 'a';
		else if (instruction[0] == '0' && instruction[1] < 'f')
			(instruction[1])++;
		else if (instruction[0] == '0' && instruction[1] == 'f')
		{
			instruction[0] = '1';
			instruction[1] = '0';
		}
		code_instruction++;
	}
	return (code_instruction);
}

void 			choose_instruction(t_cell *cell, t_bot *bot)
{
	int 		argument;
	int 		check_jump;

	if (IS_VALID_COMMAND(COMMAND) == false)
	{
		move_carriage(cell, bot, 1, OWN);
		return ;
	}
	else
	{
		argument = (get_codage(COMMAND)) ? get_argument(cell, bot, 1) : 0x80;
	}


	if (COMMAND == CW_LIVE)
	{
		alive_instruct(cell, bot);
	}
	else if (COMMAND == CW_LD) //well
	{
		load_instruct(cell, bot);
	}
	else if (COMMAND == CW_ST)	// checked coordinates && t_reg
	{
		store_instruct(cell, bot);
	}
	else if (COMMAND == CW_ADD ||
			COMMAND == CW_SUB)
	{
		add_sub_instructs(cell, bot);
	}
	else if (COMMAND == CW_OR ||
			COMMAND == CW_XOR ||
			COMMAND == CW_AND)
	{
		logical_operations(cell, bot);
	}
	else if (COMMAND == CW_ZJMP)
	{
		check_jump = jump_if_carry_instruct(cell, bot);
	}
	else if (COMMAND == CW_LDI ||
			COMMAND == CW_LLDI)
	{
		load_index_instruct(cell, bot);
	}
	else if (COMMAND == CW_STI)
	{
		store_index_instruct(cell, bot);
	}
	else if (COMMAND == CW_FORK ||
			COMMAND == CW_LFORK)
	{
		fork_instruct(cell, bot);
	}
	else if (COMMAND == CW_LLD)
	{
		long_load_instruct(cell, bot);
	}
	else if (COMMAND == CW_AFF)
	{
		aff_instruct(cell, bot);
	}
	if (COMMAND != CW_ZJMP || check_jump == 1)
	{
		move_carriage(cell, bot, (1 + fishka(argument, 3, get_dir_bytes(COMMAND)) + get_codage(COMMAND)), NOT_OWN);
	}
}


void 			get_command(t_cell *cell, t_bot *bot)
{
	int 		quant_carriages;
	t_carriage	*head;


	quant_carriages = bot->quant_carriages;
	head = bot->carriage;
	while (bot->carriage && quant_carriages--)
	{

		if (COMMAND == 0)
		{
			COMMAND = which_instruction((char *) cell[CUR_POS].hex);
			if (IS_VALID_COMMAND(COMMAND) == true)
				bot->carriage->cycles = get_cycles(bot);

		}
		bot->carriage->cycles--;
		if (bot->carriage->cycles <= 0)
		{
			choose_instruction(cell, bot); // do i need bot
			COMMAND = 0;
			bot->carriage->cycles = 0;
		}
		bot->carriage = bot->carriage->next;
	}

	bot->carriage = head;
}

void 			do_process(t_corewar *core, int qua_bots)
{
	if (qua_bots > 0)
	{
		qua_bots--;
		do_process(core, (qua_bots));
		get_command(core->cell, &(core->bots[qua_bots]));
	}
}