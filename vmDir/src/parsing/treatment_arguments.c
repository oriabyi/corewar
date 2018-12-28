/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment_arguments.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 18:17:19 by ariabyi           #+#    #+#             */
/*   Updated: 2018/12/28 18:17:27 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_header.h"

int					get_flags_help(t_flags *flags, char *av)
{
	while (*av)
	{
		if (*av == 'v')
			flags->visual = 1;
		else if (*av == 'd')
			flags->dump = 1;
		else if (*av == 'n')
			return (0);
		else
			return (1);
		av++;
	}
	return (0);
}

int					get_flags(t_flags *flags, char **av)
{
	int				counter;

	counter = 0;
	while (av[counter] && *(av[counter]) == '-')
	{
		if (ft_strcmp(av[counter], "-v") == 0)
			flags->visual = 1;
		else if (ft_strcmp(av[counter], "-d") == 0 ||
					ft_strcmp(av[counter], "-dump") == 0)
		{
			flags->dump = (unsigned)ft_atoi(av[++counter]);
			if (check_got_num(av[counter], flags->dump, 1))
				return (BAD_NUMBER_FOR_DUMP);
		}
		else if (ft_strcmp(av[counter], "-n") == 0)
			break ;
		else if (*(av[counter]) == '-' &&
			get_flags_help(flags, (av[counter] + 1)) == 1)
		{
			return (BAD_FLAGS);
		}
		counter++;
	}
	return (0);
}

int					check_availability_flags(t_flags *flags, int ac, char **av)
{
	if (ac < 2)
	{
		return (NEED_ARGUMENTS);
	}
	else if (ft_strcmp(av[1], "--help") == 0)
	{
		return (PRINT_USAGE);
	}
	if (av[1] && av[1][0] == '-')
	{
		return (get_flags(flags, (av + 1)));
	}
	return (0);
}
