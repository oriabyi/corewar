/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 17:45:05 by ariabyi           #+#    #+#             */
/*   Updated: 2018/12/28 17:45:06 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_header.h"

ssize_t				get_t_dir(t_field *field, t_carriage *carriage,
													int number, int main_arg)
{
	if (I_LABEL_SIZE == 2)
		return ((short)(get_dir(field, 1 + I_CODAGE + get_indent(main_arg,
				number, I_LABEL_SIZE), I_LABEL_SIZE, carriage)));
	else
		return ((unsigned)(get_dir(field, 1 + I_CODAGE + get_indent(main_arg,
				number, I_LABEL_SIZE), I_LABEL_SIZE, carriage)));
}

ssize_t				get_t_ind(t_field *field, t_carriage *carriage,
													int number, int main_arg)
{
	int				pos;

	pos = (short)get_dir(field, 1 + I_CODAGE + get_indent(main_arg, number,
			I_LABEL_SIZE), TWO_BYTES, carriage);
	if (I_COMMAND != CW_LLD)
		pos %= IDX_MOD;
	if (I_COMMAND == CW_ST)
		return ((short)pos);
	return ((unsigned)get_dir(field, pos, FOUR_BYTES, carriage));
}

ssize_t				get_arguments(t_field *field, int argument,
											int number, t_carriage *carriage)
{
	int				main_arg;

	main_arg = argument;
	if (number == 0)
		argument = GET_FIRST_ARG(argument);
	else if (number == 1)
		argument = GET_SECOND_ARG(argument);
	else if (number == 2)
		argument = GET_THIRD_ARG(argument);
	if (argument == T_REG)
	{
		return ((unsigned char)(get_argument(field, CUR_COORD + 1 + I_CODAGE +
			get_indent(main_arg, number, I_LABEL_SIZE)) - 1));
	}
	else if (argument == GET_IND(T_IND))
	{
		return (get_t_ind(field, carriage, number, main_arg));
	}
	else if (argument == T_DIR)
	{
		return (get_t_dir(field, carriage, number, main_arg));
	}
	return (0);
}

ssize_t				get_dir(t_field *field, int handicap, int bytes,
													t_carriage *carriage)
{
	int				temp_bytes;
	char			*temp;
	ssize_t			result;

	result = 0;
	temp = NULL;
	temp_bytes = bytes;
	handicap += CUR_COORD;
	while (temp_bytes--)
	{
		handicap = (int)correction_coordinates(handicap);
		temp = ft_multjoinfr(3, NULL, temp,
							(char *)field[handicap].hex);
		handicap++;
	}
	if (bytes == ONE_BYTE)
		result = (unsigned char)ft_ahtoi(temp);
	else if (bytes == TWO_BYTES)
		result = (short)ft_ahtoi(temp);
	else if (bytes == FOUR_BYTES)
		result = ft_ahtoi(temp);
	free(temp);
	return (result);
}
