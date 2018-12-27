#include "../includes/corewar_header.h"


void 	add_champ_id(int coord, t_field *field, t_carriage *carriage)
{
	int 	counter;

	counter = 0;
	while (counter < 4)
	{
		coord = (int)correction_coordinates(coord);
		field[coord].champ_id = field[CUR_COORD].champ_id;
		field[coord].is_alive = 0;
		field[coord].altered_cycles = ALTERED_FIELD;
		coord++;
		counter++;
	}
}

void 	store_instruct(t_field *field, t_carriage *carriage, t_args *arguments,
					   unsigned cycles) // label size == 4
{
	if (GET_SECOND_ARG(LIST_ARGUMENTS) == T_REG)
	{
		REG[CAR_SECOND_ARG] = REG[CAR_FIRST_ARG];
	}
	else
	{
		write_in_field(field, (int)(CAR_SECOND_ARG + CUR_COORD),
					   (unsigned char)CAR_FIRST_ARG, carriage); //TODO: dont sure that it has to be (int)
		add_champ_id((int)(CAR_SECOND_ARG + CUR_COORD), field, carriage);
	}
}