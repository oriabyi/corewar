#include "../includes/corewar_header.h"

t_carriage				*copy_carriage(t_carriage *src, int id)
{
	int					counter;
	t_carriage			*dst;

	counter = 0;
	if (!(dst = create_carriage(id)))
		return (NULL);
	dst->carry = src->carry;
	dst->flag = src->flag;
	dst->alive = src->alive;
	dst->command = 0;
	dst->cycles = 0;
	dst->id = id;
	while (counter < NUMBER_OF_REGISTERS)
	{
		dst->registers[counter] = src->registers[counter];
		counter++;
	}
	return (dst);
}


void					fork_instruct(t_field *field, t_bot *bot)
{
	short				first_arg;
	t_carriage			*new_carriage;
	t_carriage			*head;

	head = bot->carriage;

	first_arg = (short)get_arguments(field, bot, 0x80, FIRST_ARG);
	new_carriage = copy_carriage(head, bot->quant_carriages);
	if (new_carriage == NULL)
	{
		return ;
	}

	if (COMMAND == CW_FORK)
	{
		new_carriage->cur_coord = head->cur_coord + (first_arg % IDX_MOD);
	}
	else if (COMMAND == CW_LFORK)
	{
		new_carriage->cur_coord = head->cur_coord + (first_arg);
	}
	new_carriage->cur_coord = (int)correction_coordinates(new_carriage->cur_coord);

	denote_field(field, new_carriage->cur_coord);

	while (head && head->next)
		head = head->next;
	if (head && ++bot->quant_carriages)
		head->next = new_carriage;
}