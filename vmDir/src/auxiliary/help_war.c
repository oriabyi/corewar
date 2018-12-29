/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_war.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 19:21:31 by ariabyi           #+#    #+#             */
/*   Updated: 2018/12/28 19:21:32 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_visualization.h"

unsigned char			get_argument(t_field *field, int coord)
{
	coord = (int)correction_coordinates(coord);
	return ((unsigned char)ft_ahtoi((char *)field[coord].hex));
}

int						write_in_field(t_field *field,
							int coord, unsigned t_reg)
{
	char				**str;
	int					counter;

	counter = 0;
	str = int_to_char_hex(t_reg, 4);
	if (!str)
		return (1);
	while (str[counter])
	{
		coord = (int)correction_coordinates(coord);
		ft_strncpy((char *)field[coord].hex, str[counter], 2);
		coord++;
		counter++;
	}
	free_char_matrix(str);
	return (0);
}

ssize_t					correction_coordinates(ssize_t coordinate)
{
	if (coordinate >= MEM_SIZE)
	{
		coordinate %= MEM_SIZE;
	}
	while (coordinate < 0)
	{
		coordinate += MEM_SIZE;
	}
	return (coordinate);
}

int						get_regs_value(int argument, t_carriage *carriage,
											int type, int num, ...)
{
	int					check_code;
	va_list				ap;
	ssize_t				*temp_reg;
	int					coord;

	va_start(ap, num);
	check_code = 0;
	while (num)
	{
		coord = va_arg(ap, int);
		temp_reg = va_arg(ap, ssize_t *);
		if (check_instruction_arg(
				get_part_argument(argument, coord), type) == 0)
		{
			if (check_reg((int)(*temp_reg)))
				check_code = 1;
			*temp_reg = REG[*temp_reg];
		}
		num--;
	}
	va_end(ap);
	return (check_code);
}

void					add_champ_id(int coord, t_field *field,
								t_carriage *carriage, unsigned cycles)
{
	int					counter;

	counter = 0;
	while (counter < 4)
	{
		coord = (int)correction_coordinates(coord);
		field[coord].champ_id = field[CUR_COORD].champ_id;
		field[coord].altered_cycles = cycles + SHOW_CHANGED_CYCLES;
		coord++;
		counter++;
	}
}
