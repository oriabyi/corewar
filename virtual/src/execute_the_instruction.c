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

int 			choose_instruction(t_cell *cell, t_bot *bot)
{
	if (bot->carriage->command == CW_LIVE)
	{
		return(alive_instruct(cell, bot));
	}
	else if (bot->carriage->command == CW_LD)
	{
		return(load_instruct(cell, bot));
	}
	else if (bot->carriage->command == CW_ST)
	{
		return(store_instruct(cell, bot));
	}
	else if (bot->carriage->command == CW_ADD ||
			bot->carriage->command == CW_SUB)
	{
		return(add_sub_instructs(cell, bot));
	}
	else if (bot->carriage->command == CW_OR ||
			bot->carriage->command == CW_XOR ||
			bot->carriage->command == CW_AND)
	{
		return(logical_operations(cell, bot));
	}
	else if (bot->carriage->command == CW_ZJMP)
	{
		return(jump_if_carry_instruct(cell, bot));
	}
	else if (bot->carriage->command == CW_LDI ||
			bot->carriage->command == CW_LLDI)
	{
		return(load_index_instruct(cell, bot));
	}
	else if (bot->carriage->command == CW_STI)
	{
		return(store_index_instruct(cell, bot));
	}
	else if (bot->carriage->command == CW_FORK ||
			bot->carriage->command == CW_LFORK)
	{
		return(fork_instruct(cell, bot));
	}
	else if (bot->carriage->command == CW_LLD)
	{
		return(long_load_instruct(cell, bot));
	}
	else if (bot->carriage->command == CW_AFF)
	{
		return(aff_instruct(cell, bot));
	}
	else
		move_carriage(cell, bot, 1);
	return (0);
}


int 			get_command(t_cell *cell, t_bot *bot)
{
	int 		quant_carriages;
	t_carriage	*head;
	int 		flag = 0;


	quant_carriages = bot->quant_carriages;
	head = bot->carriage;
	if (bigmother == 699945)
		write(0, 0, 0);
	while (bot->carriage && quant_carriages--)
	{
		if (bot->carriage->command == 0)
		{
			bot->carriage->command = which_instruction((char *) cell[bot->carriage->cur_pos].hex);
			bot->carriage->cycles = get_cycles(bot);
		}


		if (bot->carriage->cycles == 0)// || bot->quant_carriages == 1) // delete second condition
		{
			if (bot->carriage->command <= 16)
			{
				if (bigmother == 812)
					write(0, 0, 0);
				dprintf(bot->fd, "i = %d\nCommand: %d\n\n", bigmother, bot->carriage->command);
				bot->carriage->cur_pos = (int)correction_coordinates(bot->carriage->cur_pos);
				choose_instruction(cell, bot); // do i need bot

			}
			else
			{
				move_carriage(cell, bot, 1);
				bot->carriage->cur_pos = (int)correction_coordinates(bot->carriage->cur_pos);
			}
			bot->carriage->command = 0;
			bot->carriage->cycles = 0; // BIG DOG_NAIL
			flag++;
		}
		else
		{
			bot->carriage->cycles--;
		}
		bot->carriage = bot->carriage->next;

	}


	bot->carriage = head;
	return (flag);
}

int 			do_process(t_corewar *core, int qua_bots)
{
	if (qua_bots-- == 0)
		return (0);
	do_process(core, (qua_bots));
	return (get_command(core->cell, &(core->bots[qua_bots])));
}