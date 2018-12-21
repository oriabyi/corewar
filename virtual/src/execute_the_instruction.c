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

void 			choose_instruction(t_field *field, t_carriage *carriage, unsigned id,
								   unsigned *quant_carriages)
{
	unsigned char 		argument;
	int 		check_jump;

	if (IS_VALID_COMMAND(COMMAND) == false)
	{
		move_carriage(field, id, 1, OWN, carriage);
		return ;
	}
	else
	{
		argument = (get_codage(COMMAND)) ? get_argument(field, CUR_COORD + 1) : (unsigned char)0x80;
	}


	if (COMMAND == CW_LIVE)
	{
		alive_instruct(field, carriage);
	}
	else if (COMMAND == CW_LD ||
			COMMAND == CW_LLD) //well
	{
		load_instruct(field, carriage, argument); //check with T_IND
	}
	else if (COMMAND == CW_ST)	// checked coordinates && t_reg
	{
		store_instruct(field, carriage, argument, id);
	}
	else if (COMMAND == CW_ADD ||
			COMMAND == CW_SUB)
	{
		add_sub_instructs(field, carriage, argument);
	}
	else if (COMMAND == CW_OR ||
			COMMAND == CW_XOR ||
			COMMAND == CW_AND)
	{
		logical_operations(field, carriage, argument);
	}
	else if (COMMAND == CW_ZJMP)
	{
		check_jump = jump_if_carry_instruct(field, carriage, id);
	}
	else if (COMMAND == CW_LDI ||
			COMMAND == CW_LLDI)
	{
		load_index_instruct(field, carriage, argument);
	}
	else if (COMMAND == CW_STI)
	{
		store_index_instruct(field, carriage, argument, id);
	}
	else if (COMMAND == CW_FORK ||
			COMMAND == CW_LFORK)
	{
		fork_instruct(field, carriage, quant_carriages);
	}
	else if (COMMAND == CW_AFF)
	{
		aff_instruct(field, carriage, id);
	}
	if (COMMAND != CW_ZJMP || check_jump == true)
	{
		move_carriage(field, id, (1 + fishka(argument, 3, get_dir_bytes(COMMAND)) + get_codage(COMMAND)), NOT_OWN, carriage); // FIFTH
	}
}


void 			get_command(t_field *field, t_champ *champ)
{
	t_carriage	*head;
	t_carriage	*carriage;


	carriage = champ->carriage;
	head = champ->carriage;
	while (champ->carriage)
	{
		if (COMMAND == 0)
		{
			COMMAND = which_instruction((char *)(field[CUR_COORD].hex));
			if (IS_VALID_COMMAND(COMMAND) == true)
				CYCLES = get_cycles(carriage);
		}
		(champ->CYCLES)--;
		if (CYCLES <= 0)
		{
			choose_instruction(field, carriage, champ->id, &champ->quant_carriages);
			COMMAND = 0;
			CYCLES = 0;
		}
		champ->carriage = champ->carriage->next;
		carriage = champ->carriage;
	}

	champ->carriage = head;
}

void 			do_process(t_corewar *core, int qua_champs)
{
	if (qua_champs > 0)
	{
		qua_champs--;
		do_process(core, (qua_champs));
		get_command(core->field, &(core->champs[qua_champs]));
	}
}