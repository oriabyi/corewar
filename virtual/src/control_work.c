#include "../includes/corewar_header.h"

int				notification_message(t_corewar *core, int notific_code,
														char *notific_message)
{
	ft_putendl_fd(notific_message, STDERR_FILENO);
	clean_all(core);
	if (notific_code == PRINT_USAGE)
		free(notific_message);
//	system("leaks -q corewar");
//	if (notific_code == BAD_ARGUMENTS || notific_code == BAD_FLAGS ||
//	notific_code == BAD_NUMBER_FOR_DUMP || notific_code == MISSING_CHAMP ||
//	notific_code == )
//	exit(notific_code);
	return (notific_code);
}