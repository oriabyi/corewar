#include "asm.h"

int main(int ac, char **av)
{
	t_asm *asb;

	if (ac > 1)
		if (ft_check_extention(av[ac - 1]))
			ft_get_data(av[ac - 1], &asb);
		else
			ft_put_error(2, av[ac - 1]);
	else
		ft_put_error(0, "file");
	system("leaks asm");
	return (0);
}