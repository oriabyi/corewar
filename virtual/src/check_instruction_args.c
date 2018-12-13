#include "../includes/corewar_header.h"

int 	check_instruction_arg(int argument, int byte) // rename byte
{
	if (byte == (T_REG | T_DIR | T_IND))
		return (0);
	if (argument == T_REG && (byte & 1) == FALSE)
		return (ERROR);
	if (argument == T_DIR && (byte & 2) == FALSE)
		return (ERROR);
	if (argument == GET_T_IND_ARG(T_IND) && (byte & 4) == FALSE)
		return (ERROR);
	return (0);
}

int 	check_instruction_args(int argument, int first, int second, int third)
{
	int 		check_code;

	check_code = check_instruction_arg(GET_FIRST_ARGUMENT(argument), first);
	if (check_code == 0)
	{
		check_code =
				check_instruction_arg(GET_SECOND_ARGUMENT(argument), second);
		if (check_code == 0)
		{
			check_code =
					check_instruction_arg(GET_THIRD_ARGUMENT(argument), third);
		}
	}
	return (check_code);
}
