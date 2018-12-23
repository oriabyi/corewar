#include "../includes/corewar_header.h"

void				exit_message(t_corewar *core,
											int error_code, char *error_message)
{
	ft_putendl_fd(error_message, STDERR_FILENO);
	clean_all(core);
//	system("leaks -q corewar");
//	if (error_code == BAD_ARGUMENTS || error_code == BAD_FLAGS ||
//	error_code == BAD_NUMBER_FOR_DUMP || error_code == MISSING_CHAMP ||
//	error_code == )
	exit(error_code);
}