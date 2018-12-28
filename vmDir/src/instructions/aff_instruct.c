/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_instruct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 19:14:48 by ariabyi           #+#    #+#             */
/*   Updated: 2018/12/28 19:14:50 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_header.h"

void				aff_instruct(t_carriage *carriage, t_args *arguments)
{
	write(1, (const void *)((ssize_t)(REG[ARG_FIRST] % 256)), 1);
}
