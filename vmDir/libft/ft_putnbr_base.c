/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 17:36:37 by ariabyi           #+#    #+#             */
/*   Updated: 2017/11/03 17:36:40 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_base(char *b, char *c)
{
	while (*c && *b && *c++ == *b++)
		if (*b == '\0')
			return (1);
	return (0);
}

static void		ft_putnbr_parse(int n, int b, char *base)
{
	if (n >= b)
	{
		ft_putnbr_parse(n / b, b, base);
		n %= b;
	}
	ft_putchar(base[n]);
}

void			ft_putnbr_base(int nbr, char *base)
{
	int		c;

	c = 0;
	if (!check_base(base, "0123456789ABCDEF"))
		return ;
	while (*base++)
		c++;
	if (c <= 1)
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	ft_putnbr_parse(nbr, c, "0123456789ABCDEF");
}
