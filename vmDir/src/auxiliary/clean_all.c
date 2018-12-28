/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 18:57:31 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/28 18:57:33 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_header.h"

void				clean_carriages(t_carriage *carriage)
{
	if (carriage)
		clean_carriages(carriage->next);
	free(carriage);
}

void				clean_champs(t_champ *champs, unsigned quantity)
{
	unsigned		counter;

	counter = 0;
	while (counter != quantity)
	{
		free(champs[counter].name);
		free(champs[counter].comment);
		free(champs[counter].exec_code);
		counter++;
	}
	free(champs);
}

void				clean_all(t_corewar *core)
{
	clean_champs((core->champs), core->qua_champs);
	if (core->carriage)
		clean_carriages(core->carriage);
	if (core->field)
		free(core->field);
}
