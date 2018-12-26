#include "../includes/corewar_header.h"


unsigned char 	 get_argument(t_field *field, int coord)
{
	coord = (int)correction_coordinates(coord);
	return ((unsigned char)ft_ahtoi((char *)field[coord].hex));
}

#include "../../libft/int_to_char_hex.c"

int 	write_in_field(t_field *field, int coord, unsigned char t_reg, t_carriage *carriage)
{

	char **str;
	int 	counter;

	counter = 0;
	str = int_to_char_hex(REG[t_reg], 4); //define 5
	if (!str)
		return (1); // return an ERROR
	while (str[counter])
	{
		coord = (int)correction_coordinates(coord);
		ft_strncpy((char *)field[coord].hex, str[counter], 2);
		field[coord].old_owner = field[CUR_COORD].champ_id;
		field[coord].champ_id = field[CUR_COORD].champ_id; //+ DENOTE_ALTERED;
		field[coord].is_alive = 0;
		field[coord].altered_cycles = ALTERED_FIELD;
		coord++;
		counter++;
	}
	free_char_matrix(str);
	return (0);
}

ssize_t 		correction_coordinates(ssize_t coordinate)
{
	if (coordinate >= MEM_SIZE)
	{
		coordinate %= MEM_SIZE;
	}
	while (coordinate < 0)
	{
		coordinate += MEM_SIZE;
	}
	return (coordinate);
}


int 					get_regs_value(int argument, t_carriage *carriage, int type, int num, ...)
{
	int 				check_code;
	va_list 			ap;
	ssize_t 			*temp_reg;
	int 				coord;

	va_start(ap, num);
	check_code = 0;
	while (num)
	{
		coord = va_arg(ap, int);
		temp_reg = va_arg(ap, ssize_t *);
		if (check_instruction_arg(get_part_argument(argument, coord), type) == 0)
		{
			if (check_reg((int)(*temp_reg)))
				check_code = 1;
			*temp_reg = REG[*temp_reg];
		}
		num--;
	}
	va_end(ap);
	return (check_code);
}

void 	store_index_instruct(t_field *field, t_carriage *carriage, t_args *arguments)	//label size == 2
{
	ssize_t 		coord;

	if (get_regs_value(LIST_ARGUMENTS, carriage, T_REG, 2,
			SECOND_ARG, &CAR_SECOND_ARG,
			THIRD_ARG, &CAR_THIRD_ARG) == 1)
	{
		return ;
	}
	coord = (((int)(CAR_SECOND_ARG + CAR_THIRD_ARG) % IDX_MOD) + CUR_COORD); // TODO: mb not int
	write_in_field(field, (int)coord, (unsigned char)CAR_FIRST_ARG, carriage);
}








