/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 02:22:48 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/11 02:22:53 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_correct_bywchar(t_elem *el, t_data *data)
{
	if (*data->ws < 2048)
	{
		el->precision -= (*data->ws < 128) ? 1 : 2;
		el->width -= (*data->ws < 128) ? 1 : 2;
		g_printed += (*data->ws < 128) ? 1 : 2;
	}
	else
	{
		el->precision -= (*data->ws < 65535) ? 3 : 4;
		el->width -= (*data->ws < 65535) ? 3 : 4;
		g_printed += (*data->ws < 65535) ? 3 : 4;
	}
	ft_putchar_utf8(*(data->ws++));
}

void	ft_print_str(t_elem *el, t_data *data)
{
	while (ft_strchr(el->flags, '0') && !(ft_strchr(el->flags, '-')) &&
		el->width > el->precision && el->width-- > 0 && ++g_printed)
		ft_putchar('0');
	while (!(ft_strchr(el->flags, '-')) && (el->width > el->precision)
		&& el->width-- > 0 && ++g_printed)
		ft_putchar(' ');
	while (el->length != 'l' && *(data->s) && 0 < el->precision--
		&& ++g_printed)
	{
		el->width--;
		ft_putchar(*(data->s++));
	}
	while (el->length == 'l' && 0 < el->precision && *(data->ws) > 0)
		ft_correct_bywchar(el, data);
	while (ft_strchr(el->flags, '0') && el->width-- > 0 && ++g_printed)
		ft_putchar('0');
	while (el->width-- > 0 && ++g_printed)
		ft_putchar(' ');
}

void	ft_correct_prec(t_elem *el, t_data *data)
{
	if (el->length == 'l')
		el->precision = (el->precision < (int)ft_strllen(data->ws) &&
			ft_strchr(el->flags, '.')) ? el->precision :
	(int)ft_strllen(data->ws);
	else
		el->precision = (el->precision < (int)ft_strlen(data->s) &&
			ft_strchr(el->flags, '.')) ? el->precision :
	(int)ft_strlen(data->s);
}

void	ft_get_type_str(t_elem *el, va_list *args)
{
	t_data	data;
	char	flag;
	char	*p;

	data.llu = 0;
	flag = 0;
	if (el->length == '\0')
		data.s = va_arg(*args, char *);
	else if (el->length == 'l')
		data.ws = va_arg(*args, wchar_t *);
	else
		return ;
	if ((!data.s) && (flag = 1))
	{
		el->length = '\0';
		data.s = ft_strdup("(null)");
	}
	p = data.s;
	ft_correct_prec(el, &data);
	ft_print_str(el, &data);
	if (flag)
		free(p);
}
