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

#include "../includes/libft.h"

char		*get_hex_by_int_byte(size_t num, size_t len)
{
	char	*result;
	ssize_t	large_num;
	int		power;
	int		counter;

	counter = 0;
	power = (int)len - 1;
	large_num = num;
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_memset(result, '0', len);
	result[len] = '\0';
	while (large_num && power >= 0)
	{
		counter = 0;
		while (large_num >= raise_to_power(16, power))
		{
			large_num -= raise_to_power(16, power);
			counter++;
		}
		result[(len - 1) - power] = (counter <= 9)
				? (char)(counter + '0') : get_num_in_hex(counter);
		power--;
	}
	return (result);
}
