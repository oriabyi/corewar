/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 02:18:42 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/11 02:18:48 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(long long value, int base)
{
	char		alphabet[36];
	int			i;
	uintmax_t	value_cpy;
	char		*line;

	if (!value)
		return (ft_zero_line());
	i = -1;
	while (++i < 36)
		alphabet[i] = (i < 10) ? '0' + i : 'a' + i - 10;
	i = 2;
	value_cpy = value;
	while ((value_cpy /= base) > 0)
		i++;
	line = (char *)malloc((base == 10 && value < 0) ? ++i : i);
	line[--i] = '\0';
	value_cpy = value;
	while (i--)
	{
		line[i] = alphabet[value_cpy % base];
		value_cpy = value_cpy / base;
	}
	if (base == 10 && value < 0)
		line[0] = '-';
	return (line);
}
