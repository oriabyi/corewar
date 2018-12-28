/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 19:11:27 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/28 19:14:15 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_header.h"

int				main(int ac, char **av)
{
	int			check_code;
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
