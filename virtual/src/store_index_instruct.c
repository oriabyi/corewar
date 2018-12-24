#include "../includes/corewar_header.h"


unsigned char 	 get_argument(t_field *field, int coord)
{
	coord = (int)correction_coordinates(coord);
	return ((unsigned char)ft_ahtoi((char *)field[coord].hex));
}

#include "../../libft/int_to_char_hex.c"

int 	write_in_field(t_field *field, int coord, int t_reg, t_carriage *carriage,
					  unsigned id)
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


//			if (field[coord].carriages_on)
				field[coord].old_owner = get_id_of_champ(id);
//			else
				field[coord].champ_id = get_id_of_champ(id); //+ DENOTE_ALTERED;

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

void 	store_index_instruct(t_field *field, t_carriage *carriage, unsigned char argument, unsigned id)	//label size == 2
{
	ssize_t 		coord;
	ssize_t		 	first_arg;
	ssize_t 		second_arg;
	ssize_t			third_arg;

	if (check_instruction_args(argument,
			T_REG, (T_REG | T_DIR | T_IND), (T_REG | T_DIR)) == ERROR)
	{
		return ;
	}

	first_arg = get_arguments(field, argument, FIRST_ARG, carriage);
	second_arg = get_arguments(field, argument, SECOND_ARG, carriage);
	third_arg = get_arguments(field, argument, THIRD_ARG, carriage);

	if (get_regs_value(argument, carriage, T_REG, 2, 1, &second_arg, 2, &third_arg) == 1)
		return ;

	coord = (((short)(second_arg + third_arg) % IDX_MOD) + CUR_COORD);

	write_in_field(field, (int)coord, (int)first_arg, carriage, id);
}








