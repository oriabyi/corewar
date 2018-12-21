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

void 			choose_instruction(t_field *field, t_bot *bot)
{
	int 		argument;
	int 		check_jump;

	if (IS_VALID_COMMAND(COMMAND) == false)
	{
		move_carriage(field, bot, 1, OWN);
		return ;
	}
	else
	{
		argument = (get_codage(COMMAND)) ? get_argument(field, bot, 1) : 0x80;
	}


	if (COMMAND == CW_LIVE)
	{
		alive_instruct(field, bot);
	}
	else if (COMMAND == CW_LD ||
			COMMAND == CW_LLD) //well
	{
		load_instruct(field, bot); //check with T_IND
	}
	else if (COMMAND == CW_ST)	// checked coordinates && t_reg
	{
		store_instruct(field, bot);
	}
	else if (COMMAND == CW_ADD ||
			COMMAND == CW_SUB)
	{
		add_sub_instructs(field, bot);
	}
	else if (COMMAND == CW_OR ||
			COMMAND == CW_XOR ||
			COMMAND == CW_AND)
	{
		logical_operations(field, bot);
	}
	else if (COMMAND == CW_ZJMP)
	{
		check_jump = jump_if_carry_instruct(field, bot);
	}
	else if (COMMAND == CW_LDI ||
			COMMAND == CW_LLDI)
	{
		load_index_instruct(field, bot);
	}
	else if (COMMAND == CW_STI)
	{
		store_index_instruct(field, bot);
	}
	else if (COMMAND == CW_FORK ||
			COMMAND == CW_LFORK)
	{
		fork_instruct(field, bot);
	}
	else if (COMMAND == CW_AFF)
	{
		aff_instruct(field, bot);
	}
	if (COMMAND != CW_ZJMP || check_jump == true)
	{
		move_carriage(field, bot, (1 + fishka(argument, 3, get_dir_bytes(COMMAND)) + get_codage(COMMAND)), NOT_OWN);
	}
}


void 			get_command(t_field *field, t_bot *bot)
{
	int 		quant_carriages;
	t_carriage	*head;


	quant_carriages = bot->quant_carriages;
	head = bot->carriage;
	while (bot->carriage && quant_carriages--)
	{

		if (COMMAND == 0)
		{
			COMMAND = which_instruction((char *)(field[CUR_COORD].hex));
			if (IS_VALID_COMMAND(COMMAND) == true)
				bot->carriage->cycles = get_cycles(bot);
		}
		bot->carriage->cycles--;
		if (bot->carriage->cycles <= 0)
		{
			choose_instruction(field, bot);
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
		get_command(core->field, &(core->bots[qua_bots]));
	}
}