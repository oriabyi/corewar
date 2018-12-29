/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_init_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 19:41:52 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/27 19:41:57 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_visualization.h"

void	init_time(t_corewar *core)
{
	NCUR.tstart.tv_nsec = 0;
	NCUR.tstart.tv_sec = 0;
	NCUR.tend.tv_nsec = 0;
	NCUR.tend.tv_sec = 0;
}
