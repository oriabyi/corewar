/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hex_by_int_byte.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:39:56 by ariabyi           #+#    #+#             */
/*   Updated: 2018/11/27 14:40:09 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char 	*get_hex_by_int_byte(size_t num)
{
	char 	*result;
	ssize_t large_num;
	int 	power;
	int 	counter = 0;

	power = 7;
	large_num = num;
	if (!(result = (char *)malloc(sizeof(char) * 9)))
		return (NULL);
	ft_memset(result, '0', 8);
	result[8] = '\0';
	while (large_num && power >= 0)
	{
		counter = 0;
		while (large_num >= raise_to_power(16, power))
		{
			large_num -= raise_to_power(16, power);
			counter++;
		}
		result[7 - power] = (counter <= 9) ? (char)(counter + '0') : get_num_in_hex(counter);
		power--;
	}
	return (result);
}

