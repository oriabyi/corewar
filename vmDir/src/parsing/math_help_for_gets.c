/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_help_for_gets.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 18:05:38 by ariabyi           #+#    #+#             */
/*   Updated: 2018/12/28 18:06:26 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_header.h"

int							get_old_young_bits(unsigned char num,
														int base, int *power)
{
	int						younger;
	int						older;

	if (base == 0)
		return (0);
	older = num / base;
	younger = num % base;
	older = older * raise_to_power(base, *power);
	(*power)--;
	younger = younger * raise_to_power(base, *power);
	(*power)--;
	return (older + younger);
}

unsigned					get_num_by_octet_bytes(int fd, int size)
{
	unsigned				result;
	int						power;
	unsigned char			buf;

	power = size * 2 - 1;
	result = 0;
	while (power >= 0)
	{
		read(fd, &buf, 1);
		result += get_old_young_bits(buf, 16, &power);
	}
	return (result);
}

unsigned					count_char_no_bound(const char *string, char letter,
															unsigned len)
{
	unsigned				counter;
	unsigned				counter_char;

	counter = 0;
	counter_char = 0;
	if (string == NULL)
		return (0);
	while (counter < len)
	{
		if (string[counter] == letter)
			counter_char++;
		counter++;
	}
	return (counter_char);
}

unsigned					interlayer(int fd)
{
	unsigned char			buf[4];
	unsigned				len;

	read(fd, buf, 4);
	len = count_char_no_bound((char *)buf, '\0', 4);
	if (len == 4)
		return (0);
	else
		return (ERROR);
}

unsigned char				*ft_strncpy_without_boundes(
								const unsigned char *src,
								size_t len, size_t max)
{
	unsigned char			*result;
	unsigned				i;

	i = 0;
	if (!(result = (unsigned char *)malloc(sizeof(unsigned char) * (len + 1))))
		return (NULL);
	while (i < len && i < max)
	{
		result[i] = src[i];
		i++;
	}
	return (result);
}
