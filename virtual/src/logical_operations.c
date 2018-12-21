#include "../includes/corewar_header.h"

unsigned				which_operation_needs(unsigned a, unsigned b, unsigned command)
{
	if (command == CW_AND)
		return (a & b);
	else if (command == CW_OR)
		return (a | b);
	else if (command == CW_XOR)
		return (a ^ b);
	else if (command == CW_ADD)
		return (a + b);
	else if (command == CW_SUB)
		return (a - b);
	return (0);
}


int 					get_part_argument(int argument, int coord)
{
	if (coord == FIRST_ARG)
	{
		return (argument >> 6);
	}
	else if (coord == SECOND_ARG)
	{
		return ((argument >> 4) & 3);
	}
	else if (coord == THIRD_ARG)
	{
		return ((argument >> 2) & 3);
	}
	return (-1);
}

int 					check_type_arguments(int argument, int type, int num, ...)
{
	int 				check_code;
	va_list 			ap;
	int 				temp_reg;
	int 				coord;

	check_code = 0;
	va_start(ap, num);
	while (num)
	{
		coord = va_arg(ap, int);
		temp_reg = va_arg(ap, int);
		if (check_instruction_arg(get_part_argument(argument, coord), type) == 0)
		{
			if (check_reg(temp_reg))
				check_code = 1;
		}
		num--;
	}
	va_end(ap);
	return (check_code);
}

void					logical_operations(t_field *field, t_carriage *carriage, unsigned char argument)
{
	unsigned 		first_arg;
	unsigned 		second_arg;
	unsigned 		third_arg;

	if (check_instruction_args(argument, (T_REG | T_DIR | T_IND),(T_REG | T_DIR | T_IND), T_REG) == ERROR)
	{
		return ;
	}
	first_arg = (unsigned)get_arguments(field, argument, FIRST_ARG, carriage);
	second_arg = (unsigned)get_arguments(field, argument, SECOND_ARG, carriage);
	third_arg = (unsigned)get_arguments(field, argument, THIRD_ARG, carriage);

	if (check_type_arguments(argument, T_REG, 3, 0, first_arg, 1, second_arg, 2, third_arg) == 1)
		return ;

	REG[third_arg] = which_operation_needs(first_arg, second_arg, COMMAND);
	change_carry_if_need(third_arg, carriage);
}
