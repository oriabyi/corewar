#include "../includes/corewar_header.h"



void				exit_message(t_corewar *core,
											int error_code, char *error_message)
{
	ft_putendl_fd(error_message, STDERR_FILENO);
	clean_all(core);
//	if (core->flags.visual)
//		visual_end(core);
//	system("leaks -q corewar");
	exit(error_code);
}

void				check_correctness(t_corewar *core, int check_code)
{
	if (check_code == 0)
		return ;
	else if (check_code == BAD_ARGUMENTS)
		exit_message(core, check_code, "Corewar ERROR: BAD ARGUMENTS!");
	else if (check_code == WRONG_ARGUMENTS)
		exit_message(core, check_code, "Corewar ERROR: WRONG ARGUMENTS!");
	else if (check_code == WRONG_MAGIC_VALUE)
		exit_message(core, check_code,
								"Corewar ERROR: BOT HAS WRONG MAGIC VALUE!");
	else if (check_code == MEMORY_ERROR)
		exit_message(core, check_code, "Corewar ERROR: ALLOCATE MEMORY ERROR!");
	else if (check_code == WRONG_PLACE_FOR_FLAGS)
		exit_message(core, check_code, "Corewar ERROR: WRONG PLACE FOR FLAGS!");
	else
		exit_message(core, check_code, "ERROR");
}
