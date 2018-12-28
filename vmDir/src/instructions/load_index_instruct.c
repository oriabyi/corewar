/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_index_instruct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 19:09:26 by ariabyi           #+#    #+#             */
/*   Updated: 2018/12/28 19:09:51 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_header.h"

ssize_t				write_from_field(t_field *field, int handicap, int bytes)
{
	int				temp_bytes;
	char			*temp;
	ssize_t			result;

	result = 0;
	temp = NULL;
	temp_bytes = bytes;
	while (temp_bytes--)
	{
		handicap = (int)correction_coordinates(handicap);
		temp = ft_multjoinfr(3, NULL, temp, (char *)field[handicap].hex);
		handicap++;
	}
	if (bytes == 1)
		result = (unsigned char)ft_ahtoi(temp);
	else if (bytes == 2)
		result = (short)ft_ahtoi(temp);
	else if (bytes == 4)
		result = ft_ahtoi(temp);
	free(temp);
	return (result);
}

void				load_index_instruct(t_field *field, t_carriage *carriage,
													t_args *arguments)
{
	ssize_t			coord;

	coord = 0;
	if (get_regs_value(LIST_ARGUMENTS, carriage, T_REG, 2,
						FIRST_ARG, &ARG_FIRST,
						SECOND_ARG, &ARG_SECOND) == 1)
	{
		return ;
	}
	if (I_COMMAND == CW_LDI)
	{
		coord = (((ARG_FIRST + ARG_SECOND) % IDX_MOD) + CUR_COORD);
	}
	else if (I_COMMAND == CW_LLDI)
	{
		coord = ARG_FIRST + ARG_SECOND + CUR_COORD;
	}
	coord = correction_coordinates(coord);
	REG[ARG_THIRD] = (unsigned)write_from_field(field,
			(int)(coord), FOUR_BYTES);
	if (I_COMMAND == CW_LLDI)
		change_carry_if_need((unsigned char)ARG_THIRD, carriage);
}
