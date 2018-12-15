#include "../includes/corewar_header.h"



int				get_flags_help(t_flags *flags, char *av)
{
	while (*av)
	{
		if (*av == 'v')
			flags->visual = 1;// Рыба
		else if (*av == 'd')
			flags->dump = 1;// Рыба
		else if (*av == 'a')
			flags->a_visual = 1;// Рыба
		else if (*av == 'o')
			flags->o_visual = 1;// Рыба
		else if (*av == 's')
			flags->s_visual = 1;// Рыба
		else if (*av == 'n')
			return (0);
		else
			return (1);
		av++;
	}
	return (0);
}

int				get_flags(t_flags *flags, char **av)
{
	int			counter;

	counter = 0;
	while (av[counter] && *(av[counter]) == '-')
	{
		if (ft_strcmp(av[counter], "-v") == 0)
			flags->visual = 1;
		else if (ft_strcmp(av[counter], "-d") == 0)// Рыба
		{
			flags->dump = (unsigned)ft_atoi(av[++counter]);
		}
		else if (ft_strcmp(av[counter], "-a") == 0)// Рыба
			flags->a_visual = 1;
		else if (ft_strcmp(av[counter], "-o") == 0)// Рыба
			flags->o_visual = 1;
		else if (ft_strcmp(av[counter], "-s") == 0)// Рыба
			flags->s_visual = 1;
		else if (ft_strcmp(av[counter], "-n") == 0)// Рыба
			break ;
		else if (*(av[counter]) == '-')
			if (get_flags_help(flags, (av[counter] + 1)) == 1)
			{
				ft_putstr_fd("Usage: ./corewar -[nd] champs\n", 2);
				exit (WRONG_ARGUMENTS);
			}
		counter++;
	}
	return (0);
}


int				check_arguments(t_flags *flags, int ac, char **av)
{
	if (ac < 2)
	{
		ft_putendl_fd("Usage: ./corewar -[nd] [champion1 champion2 .."
				"champion 4] ", 2);
		exit (WRONG_ARGUMENTS);
	}
	*flags = (t_flags){0, 0, 0, 0, 0};
	if (av[1] && av[1][0] == '-')
	{
		get_flags(flags, (av + 1));
	}
	return (0);
}