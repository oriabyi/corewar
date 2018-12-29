/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ahtoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 10:10:49 by ariabyi           #+#    #+#             */
/*   Updated: 2018/11/23 10:11:27 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int			hex_to_int(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 87);
	return (c);
}

unsigned			ft_ahtoi(const char *string)
{
	unsigned		result;
	size_t			len;
	int				temp;

	result = 0;
	if (string == NULL || *string == '\0')
		return (0);
	len = ft_strlen(string);
	while (*string)
	{
		len--;
		if (*string < 0)
			temp = *string;
		else
			temp = hex_to_int(*string);
		result += temp * raise_to_power(16, (int)len);
		string++;
	}
	return (result);
}
