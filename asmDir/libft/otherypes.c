/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otherypes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 02:22:15 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/11 02:22:23 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_prepare_chr(t_elem *el, t_data *data)
{
	while (ft_strchr(el->flags, '0') && --el->width > 0 && ++g_printed)
		ft_putchar('0');
	while (!ft_strchr(el->flags, '-') && --el->width > 0 && ++g_printed)
		ft_putchar(' ');
	if (el->length != 'l')
		g_printed += 1;
	else if (data->wc < 2048)
	{
		el->precision -= (data->wc < 128) ? 1 : 2;
		el->width -= (data->wc < 128) ? 1 : 2;
		g_printed += (data->wc < 128) ? 1 : 2;
	}
	else
	{
		el->precision -= (data->wc < 65535) ? 3 : 4;
		el->width -= (data->wc < 65535) ? 3 : 4;
		g_printed += (data->wc < 65535) ? 3 : 4;
	}
	if (el->length == 'l')
		ft_putchar_utf8(data->wc);
	else
		ft_putchar(data->c);
	while (--el->width > 0 && ++g_printed)
		ft_putchar(' ');
}

void	ft_get_type_chr(t_elem *el, va_list *args)
{
	t_data data;

	data.llu = 0;
	if (MB_CUR_MAX == 1)
		el->length = '\0';
	if (el->length == '\0')
		data.c = (char)va_arg(*args, int);
	else if (el->length == 'l')
		data.wc = (wchar_t)va_arg(*args, int);
	else
		return ;
	ft_prepare_chr(el, &data);
}

void	ft_get_sign(t_elem *el)
{
	t_data data;

	data.llu = 0;
	data.c = '%';
	ft_prepare_chr(el, &data);
}

void	ft_get_undef_type(t_elem *el)
{
	t_data data;

	data.llu = 0;
	data.c = el->type;
	ft_prepare_chr(el, &data);
}

void	ft_get_type_ptr(t_elem *el, va_list *args)
{
	el->length = 'L';
	if (!ft_strchr(el->flags, '#'))
		el->flags[ft_strlen(el->flags)] = '#';
	ft_get_type_int_spec(el, args);
}
