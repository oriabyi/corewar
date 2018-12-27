/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 14:34:49 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/23 17:35:27 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	main(int ac, char **av)
{
	t_asm *asb;

	if (ac > 1)
		if (ft_check_extention(av[ac - 1]))
			ft_get_data(av[ac - 1], &asb);
		else
			ft_put_error(2, av[ac - 1]);
	else
		ft_put_error(17, av[0]);
	return (0);
}
