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
	dst->alive = false; // false? here change
	dst->command = 0;
	dst->cycles = 0;
	while (counter < NUMBER_OF_REGISTERS)
	{
		dst->registers[counter] = src->registers[counter];
		counter++;
	}
	return (dst);
}

void 					insert_new_carriage(t_carriage *head, t_carriage *new_carriage, unsigned *quant_carriages)
{
	t_carriage *temp;

	new_carriage->id = (*quant_carriages)++;
	//just after
	if (head->next)
	{
		temp = head->next;
		head->next = new_carriage;
		new_carriage->next = temp;
	}
	else
		head->next = new_carriage;

	//at end

//	temp = head;
//	while (temp && temp->next)
//	{
//		temp = temp->next;
//	}
//	if (temp)
//		temp->next = new_carriage;


}

void					fork_instruct(t_field *field, t_carriage *carriage,
									 unsigned *quant_carriages, t_args *arguments)
{
	t_carriage			*new_carriage;


	new_carriage = copy_carriage(carriage, *quant_carriages);
	if (new_carriage == NULL)
	{
		return ;
	}
	if (COMMAND == CW_FORK)
	{
		new_carriage->cur_coord = CUR_COORD + (int)(CAR_FIRST_ARG % IDX_MOD);
	}
	else if (COMMAND == CW_LFORK)
	{
		new_carriage->cur_coord = CUR_COORD + (int)(CAR_FIRST_ARG);
	}
	new_carriage->cur_coord = (int)correction_coordinates(new_carriage->cur_coord);
	field[new_carriage->cur_coord].carriages_on++;
	denote_field(field, new_carriage->cur_coord);
	insert_new_carriage(carriage, new_carriage, quant_carriages);
}