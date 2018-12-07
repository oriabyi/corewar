/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:44:09 by ariabyi           #+#    #+#             */
/*   Updated: 2018/02/08 18:08:41 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_put1(int c)
{
	unsigned		int a[4];
	unsigned		int v2;

	v2 = 14712960;
	a[2] = (c & 63);
	a[1] = (c & 4032);
	a[0] = (c & 61440);
	a[2] = a[2] | v2;
	a[1] = (a[1] << 2) | v2;
	a[0] = (a[0] << 4) | v2;
	a[2] = a[2] & 255;
	a[1] = a[1] & 65280;
	a[1] = a[1] >> 8;
	a[0] = a[0] & 16711680;
	a[0] = a[0] >> 16;
	write(1, &a[0], 1);
	write(1, &a[1], 1);
	write(1, &a[2], 1);
	return (1);
}

static int			ft_put2(int c)
{
	unsigned		int a[4];
	unsigned		int v3;

	v3 = 4034953344;
	a[3] = (c & 63);
	a[2] = (c & 4032);
	a[1] = (c & 258048);
	a[0] = (c & 1835008);
	a[3] = a[3] | v3;
	a[2] = (a[2] << 2) | v3;
	a[1] = (a[1] << 4) | v3;
	a[0] = (a[0] << 6) | v3;
	a[3] = a[3] & 255;
	a[2] = a[2] & 65280;
	a[2] = a[2] >> 8;
	a[1] = a[1] & 16711680;
	a[1] = a[1] >> 16;
	a[0] = a[0] & 4279238656;
	a[0] = a[0] >> 24;
	write(1, &a[0], 1);
	write(1, &a[1], 1);
	write(1, &a[2], 1);
	write(1, &a[3], 1);
	return (1);
}

int					ft_putchar(int c)
{
	unsigned int	v1;
	unsigned int	a[4];

	v1 = 49280;
	if (c <= 127)
	{
		write(1, &c, 1);
		return (1);
	}
	else if (c <= 2047)
	{
		a[1] = ((c & 63) | v1) & 255;
		a[0] = ((c & 1984) << 2) | v1;
		a[0] = (a[0] & 65280) >> 8;
		write(1, &a[0], 1);
		write(1, &a[1], 1);
		return (1);
	}
	else if (c <= 65535)
		return (ft_put1(c));
	else if (c <= 2097151)
		return (ft_put2(c));
	return (0);
}
