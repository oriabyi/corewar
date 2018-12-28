#include "../includes/corewar_header.h"

int				submain(int ac, char **av)
{
	int 		check_code;
	t_corewar	core;

	init_core(&core);
	check_code = check_availability_flags(&core.flags, ac, av);
	if ((check_code || (check_code = parse(&core, av))) ||
		(check_code = visual_init(&core)))
	{
		return (check_correctness(&core, check_code));
	}
	init_instructions((t_instructions *)&core.instructions);
	war_loop(&core);
	reset_game(&core);
	clean_all(&core);
	return (0);
}

int main(int ac, char **av)
{
	submain(ac, av);
	system("leaks corewar");
	return (0);
}
