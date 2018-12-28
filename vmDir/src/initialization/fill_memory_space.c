/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_memory_space.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 18:20:09 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/28 18:20:16 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_header.h"

void				fill_memory_space(t_champ *champs, t_field *field,
																int qua_champs)
{
	unsigned		count;
	unsigned		ch_count;
	unsigned		ch_num;
	unsigned char	*seq;

	count = 0;
	ch_num = 0;
	ch_count = 0;
	seq = (unsigned char *)"0123456789abcdef";
	while (ch_num < (unsigned)qua_champs)
	{
		if (count && count % (MEM_SIZE / qua_champs) == 0)
			if (++ch_num == (unsigned)qua_champs || (ch_count = 0))
				break ;
		if (count < champs[ch_num].size + (MEM_SIZE / qua_champs) * ch_num)
		{
			field[count].champ_id = ch_num + 1;
			field[count].hex[0] = seq[champs[ch_num].exec_code[ch_count] / 16];
			field[count].hex[1] = seq[champs[ch_num].exec_code[ch_count] % 16];
		}
		ch_count++;
		count++;
	}
}
