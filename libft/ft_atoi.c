/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:11:26 by ariabyi           #+#    #+#             */
/*   Updated: 2017/11/24 18:34:27 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int			c;
	int			sign;
	long long	res;
	long long	r;

	res = 0;
	sign = 1;
	c = 0;
	while (((s[c] >= 9 && s[c] <= 13) || s[c] == ' ') && s[c++])
		;
	if (s[c] == '+' || s[c] == '-')
		if (s[c++] == '-')
			sign = -1;
	while ((s[c] >= '0' && s[c] <= '9') && s[c])
	{
		r = res * 10 + s[c++] - '0';
		res = r;
	}
	return (res * sign);
}
