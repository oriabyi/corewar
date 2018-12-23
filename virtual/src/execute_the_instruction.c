#include "../includes/corewar_header.h"

unsigned		get_instruction_id(char *command)
{
	return (ft_ahtoi(command));
}

void						list_of_instructions(t_field *field,
										t_carriage *carriage, unsigned id,
										unsigned char argument)
{
	if (COMMAND == CW_LIVE)
		alive_instruct(field, carriage, id);
	else if (COMMAND == CW_LD || COMMAND == CW_LLD) //well
		load_instruct(field, carriage, argument); //check with T_IND
	else if (COMMAND == CW_ST)	// checked coordinates && t_reg
		store_instruct(field, carriage, argument, id);
	else if (COMMAND == CW_ADD || COMMAND == CW_SUB)
		add_sub_instructs(field, carriage, argument);
	else if (COMMAND == CW_OR || COMMAND == CW_XOR || COMMAND == CW_AND)
		logical_operations(field, carriage, argument);
	else if (COMMAND == CW_LDI || COMMAND == CW_LLDI)
		load_index_instruct(field, carriage, argument);
	else if (COMMAND == CW_STI)
		store_index_instruct(field, carriage, argument, id);
	else if (COMMAND == CW_AFF)
		aff_instruct(field, carriage, id);
}


void 					choose_instruction(t_field *field, t_carriage *carriage,
										unsigned id, unsigned *quant_carriages)
{
	int 				check_jump;
	unsigned char		argument;

	if (IS_VALID_COMMAND(COMMAND) == false)
	{
		move_carriage(field, id, 1, carriage);
		return ;
	}
	argument = (get_codage(COMMAND)) ?
			get_argument(field, CUR_COORD + 1) : (unsigned char)0x80;
	if (COMMAND == CW_ZJMP)
		check_jump = jump_if_carry_instruct(field, carriage, id);
	else if (COMMAND == CW_FORK || COMMAND == CW_LFORK)
		fork_instruct(field, carriage, quant_carriages);
	else
		list_of_instructions(field, carriage, id, argument);
	if (COMMAND != CW_ZJMP || check_jump == true)
	{
		move_carriage(field, id, (1 + fishka(argument, 3,
			get_dir_bytes(COMMAND)) + get_codage(COMMAND)), carriage);
	}
}


void 			get_command(t_field *field, t_champ *champ)
{
	t_carriage	*carriage;

	carriage = champ->carriage;
	while (carriage)
	{
		if (COMMAND == 0)
		{
			COMMAND = get_instruction_id((char *)(field[CUR_COORD].hex));
			if (IS_VALID_COMMAND(COMMAND) == true)
				CYCLES = get_cycles(carriage);
		}
		(CYCLES)--;
		if (CYCLES <= 0)
		{
			choose_instruction(field, carriage, champ->id, &champ->quant_carriages);
			COMMAND = 0;
			CYCLES = 0;
		}
		carriage = carriage->next;
	}

}

void 			do_process(t_corewar *core)
{
	unsigned 		champ_num;

	champ_num = 0;
	get_command(core->field, &(core->champs[core->qua_champs - 1]));
	while (champ_num < (core->qua_champs - 1))
	{
		get_command(core->field, &(core->champs[champ_num]));
		champ_num++;
	}
}
