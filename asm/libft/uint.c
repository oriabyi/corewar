/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 02:23:20 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/11 02:23:25 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_unlen(unsigned long long n)
{
	if (n /= 10)
		return (1 + ft_nlen(n));
	return (1);
}

void		ft_lengthen_ru(t_elem *el, t_data *data, int n)
{
	int w;
	int p;

	p = ft_shorten_w(el, data, n, &w);
	while (w > p && !ft_strchr(el->flags, '0') && ++g_printed && w--)
		ft_putchar(' ');
	ft_prepare_flags_int(el, data);
	while (p > 0 && ++g_printed && p--)
	{
		ft_putchar('0');
		w--;
	}
	while (w > 0 && w--)
	{
		if (ft_strchr(el->flags, '0'))
			ft_putchar('0');
		else
			ft_putchar(' ');
		g_printed++;
	}
	g_printed += ft_unlen((*data).ju);
	ft_putunbr((*data).ju);
}

void		ft_lengthen_lu(t_elem *el, t_data *data, int n)
{
	int w;
	int p;

	p = ft_shorten_w(el, data, n, &w);
	ft_prepare_flags_int(el, data);
	while (p > 0 && ++g_printed && p--)
	{
		ft_putchar('0');
		w--;
	}
	g_printed += ft_unlen((*data).ju);
	ft_putunbr((*data).ju);
	while (w > 0 && ++g_printed && w--)
		ft_putchar(' ');
}

void		ft_prepare_uint(t_elem *el, t_data *data)
{
	if (ft_strchr(el->flags, '.') && !el->precision && !data->ji)
	{
		g_printed += el->width;
		while (el->width--)
			ft_putchar(' ');
	}
	else if (!ft_strchr(el->flags, '-') || (ft_strchr(el->flags, '0')))
		ft_lengthen_ru(el, data, ft_unlen((*data).ju));
	else
		ft_lengthen_lu(el, data, ft_unlen((*data).ju));
}
