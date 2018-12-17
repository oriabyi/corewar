#include "../includes/corewar_header.h"

t_carriage				*copy_carrieage(t_carriage *src, int id)
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
	dst->number = src->number + 1;
	while (counter < NUMBER_OF_REGISTERS)
	{
		dst->registers[counter] = src->registers[counter];
		counter++;
	}
	return (dst);
}

int						fork_instruct(t_cell *cell, t_bot *bot)
{
	short				temp_t_dir;
	t_carriage			*temp;
	t_carriage			*head;

	head = bot->carriage;

	int step = 1;
	temp_t_dir = (short)get_arg_dir(cell, bot, &step, TWO_BYTES);
	temp = copy_carrieage(head, bot->id);
	if (temp == NULL)
		return (ERROR);
	if (bot->carriage->command == CW_FORK)
		temp->cur_pos = head->cur_pos + (temp_t_dir % IDX_MOD);
	else if (bot->carriage->command == CW_LFORK)
		temp->cur_pos = head->cur_pos + (temp_t_dir);
	temp->cur_pos = (int)correction_coordinates(temp->cur_pos);


	if (cell[temp->cur_pos].hex[0] == '0' && cell[temp->cur_pos].hex[1] == '1')
		cell[temp->cur_pos].bot_id =
				get_id_of_bot(cell[temp->cur_pos].bot_id) + DENOTE_ALIVE;
	else
		cell[temp->cur_pos].bot_id =
				get_id_of_bot(cell[temp->cur_pos].bot_id) + DENOTE_CARRIAGE;


	while (head && head->next)
		head = head->next;
	if (head && ++bot->quant_carriages)
		head->next = temp;
	move_carriage(cell, bot, 3, NOT_OWN);
	return (0);
}