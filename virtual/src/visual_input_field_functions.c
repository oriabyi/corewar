#include "../includes/corewar_header.h"

void				fill_input_field_with_zeros(char *field)
{
	ft_bzero(field, 7);
}

int 				uppend_input_field(char *field, char n)
{
	int				i;

	i = 0;
	while (i <= 5)
	{
		if (!field[i])
		{
			field[i] = n;
			field[i + 1] = '\0';
			return (0);
		}
		i++;
	}
	return (1);
}

int 			delete_last_letter_from_iput_field(char *field)
{
	int 		i;

	i = 0;
	while (i <= 5)
	{
		if (field[i] &&
			!field[i + 1])
		{
			field[i] = 0;
			return (0);
		}
		i++;
	}
	return (1);
}



void 			set_next_field(t_corewar *core)
{
	if (NCUR.current_field == NCUR.cycle_to_go)
		NCUR.current_field = NCUR.carriage_id;
	else if (NCUR.current_field == NCUR.carriage_id)
		NCUR.current_field = NCUR.cycle_to_go;
}

void 			set_prev_field(t_corewar *core)
{
	if (NCUR.current_field == NCUR.cycle_to_go)
		NCUR.current_field = NCUR.carriage_id;
	else if (NCUR.current_field == NCUR.carriage_id)
		NCUR.current_field = NCUR.cycle_to_go;
}