#include "../includes/corewar_header.h"

unsigned				which_operation_needs(ssize_t a, ssize_t b, unsigned command)
{
	if (command == CW_AND)
		return (unsigned)(a & b);
	else if (command == CW_OR)
		return (unsigned)(a | b);
	else if (command == CW_XOR)
		return (unsigned)(a ^ b);
	else if (command == CW_ADD)
		return (unsigned)(a + b);
	else if (command == CW_SUB)
		return (unsigned)(a - b);
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

int 					check_type_arguments(t_args *arguments, int type, int num, ...)
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
		if (check_instruction_arg(get_part_argument(LIST_ARGUMENTS, coord), type) == 0)
		{
			if (check_reg(temp_reg))// && coord <= arguments->qua_args)
			{
				check_code = 1;
				break ;
			}
		}
		num--;
	}
	va_end(ap);
	return (check_code);
}

void					logical_operations(t_carriage *carriage, t_args *arguments)
{
	if (get_regs_value(LIST_ARGUMENTS, carriage, T_REG, 2,
					   FIRST_ARG, &CAR_FIRST_ARG,
					   SECOND_ARG, &CAR_SECOND_ARG) == 1)
	{
		return ;
	}
	REG[CAR_THIRD_ARG] =
			which_operation_needs(CAR_FIRST_ARG, CAR_SECOND_ARG, COMMAND);
	change_carry_if_need((unsigned char)CAR_THIRD_ARG, carriage);
}
