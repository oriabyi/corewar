/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 02:21:51 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/11 02:21:55 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_shorten_w(t_elem *el, t_data *data, int n, int *w)
{
	*w = (el->width > n) ? el->width - n : 0;
	if ((ft_strchr(el->flags, '+') || ft_strchr(el->flags, ' ')) &&
		n && (*data).ji >= 0)
		(*w)--;
	if ((*data).ji < 0)
		(*w)--;
	return ((el->precision > n) ? el->precision - n : 0);
}

void	ft_lengthen_r(t_elem *el, t_data *data, int n)
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
	g_printed += ft_nlen(ft_mod((*data).ji));
	ft_putnbr(ft_mod((*data).ji));
}

void	ft_lengthen_l(t_elem *el, t_data *data, int n)
{
	int w;
	int p;

	p = ft_shorten_w(el, data, n, &w);
	ft_prepare_flags_int(el, data);
	while (p > 0 && ++g_printed)
	{
		ft_putchar('0');
		p--;
		w--;
	}
	g_printed += ft_nlen(ft_mod((*data).ji));
	ft_putnbr(ft_mod((*data).ji));
	while (w > 0 && ++g_printed)
	{
		ft_putchar(' ');
		w--;
	}
}

void	ft_prepare_int(t_elem *el, t_data *data)
{
	if (ft_strchr(el->flags, '.') && !el->precision && !data->ji &&
		!ft_strchr(el->flags, '-'))
	{
		g_printed += el->width;
		while (el->width--)
			ft_putchar(' ');
	}
	else if (!ft_strchr(el->flags, '-') || (ft_strchr(el->flags, '0')))
		ft_lengthen_r(el, data, ft_nlen(ft_mod((*data).ji)));
	else
		ft_lengthen_l(el, data, ft_nlen(ft_mod((*data).ji)));
}

void	ft_get_type_int(t_elem *el, va_list *args)
{
	t_data data;

	data.lli = 0;
	if (el->length == '\0')
		data.lli = va_arg(*args, int);
	else if (el->length == 'H')
		data.lli = (char)va_arg(*args, int);
	else if (el->length == 'h')
		data.lli = (short)va_arg(*args, int);
	else if (el->length == 'l')
		data.lli = va_arg(*args, long int);
	else if (el->length == 'L')
		data.lli = va_arg(*args, long long int);
	else if (el->length == 'j')
		data.lli = va_arg(*args, signed long long);
	else if (el->length == 'z')
		data.lli = va_arg(*args, size_t);
	else if (el->length == 't')
		data.lli = va_arg(*args, ptrdiff_t);
	else
		return ;
	ft_prepare_int(el, &data);
}
