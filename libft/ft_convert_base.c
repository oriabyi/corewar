/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 17:36:21 by ariabyi           #+#    #+#             */
/*   Updated: 2017/11/03 17:36:23 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_base(char *b, char *c)
{
	if (b && c)
		while (*c && *b && *c++ == *b++)
			if (*b == '\0')
				return (1);
	return (0);
}

static void		parse_convert_base(long long nb, char *bt, int c, char *r)
{
	int		sign;

	sign = 1;
	if (nb < 0)
	{
		nb *= -1;
		sign = -1;
	}
	if (sign == -1)
	{
		ft_strncat(r, "-", 1);
		sign = 1;
	}
	if (nb >= c)
		parse_convert_base(nb / c, bt, c, r);
	ft_strncat(r, &bt[nb % c], 1);
}

char			*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char			*r;
	long long		nb;
	int				l;
	long long		max;
	int				mem;

	if (!nbr || !base_to || !base_from)
		return (NULL);
	r = NULL;
	max = 1;
	mem = 1;
	l = ft_strlen(base_to);
	nb = ft_atoi_base(nbr, base_from);
	if (2147483647 < nb || nb < -2147483648 || \
		!check_base(base_to, "0123456789ABCDEF"))
		return (NULL);
	while (max <= nb)
	{
		max *= l;
		mem++;
	}
	r = (char *)malloc(sizeof(char) * (mem + 1));
	r[0] = '\0';
	parse_convert_base(nb, base_to, l, &(*r));
	return (r);
}
