#include "../../includes/corewar_header.h"

int				notification_message(t_corewar *core, int notific_code,
														char *notific_message)
{
	ft_putendl_fd(notific_message, STDERR_FILENO);
	clean_all(core);
	if (notific_code == PRINT_USAGE)
		free(notific_message);
	return (notific_code);
}