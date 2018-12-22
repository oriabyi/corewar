/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intspec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 02:22:02 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/11 02:22:06 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_zero_line(void)
{
	char *line;

	line = (char *)malloc(2);
	line[0] = '0';
	line[1] = '\0';
	return (line);
}

int		ft_fix_zero(t_elem *el)
{
	if (el->type == 'p')
		el->width = (el->width > 2) ? el->width - 2 : 0;
	g_printed += el->width;
	while (--el->width + 1 > 0 && !ft_strchr(el->flags, '-'))
		ft_putchar(' ');
	if (el->type == 'p' && (g_printed = g_printed + 2))
		ft_putstr("0x");
	while (--el->width + 1 > 0)
		ft_putchar(' ');
	return (1);
}

int		ft_prepare_int_spec2(t_elem *el, t_data *data, int n, int size)
{
	if (ft_strchr(el->flags, '#') && (ft_tolower(el->type == 'x')
		|| el->type == 'p'))
		size = (size > 2) ? size - 2 : 0;
	if (ft_strchr(el->flags, '#') && el->type == 'o')
		if ((el->precision = el->precision - 1 > 0 ? el->precision - 1 : 0) < n)
			size = (size > 1) ? size - 1 : 0;
	while (!ft_strchr(el->flags, '-') && !ft_strchr(el->flags, '0')
		&& size-- > 0 && ++g_printed)
		ft_putchar(' ');
	if (((ft_strchr(el->flags, '#') && data->ju) || (el->type == 'p'
		&& !data->ju)) && ++g_printed)
	{
		ft_putchar('0');
		if ((ft_tolower(el->type) == 'x' || el->type == 'p') && ++g_printed)
			ft_putchar((el->type == 'p') ? 'x' : el->type);
	}
	while (!ft_strchr(el->flags, '-') && ft_strchr(el->flags, '0')
		&& size-- > 0 && ++g_printed)
		ft_putchar('0');
	while (el->precision-- - n > 0 && ++g_printed)
		ft_putchar('0');
	return (size);
}

void	ft_prepare_int_spec(t_elem *el, t_data *data)
{
	int		n;
	int		size;
	char	*conv;

	if (ft_strchr(el->flags, '.') && !el->precision && !data->ju &&
		!(el->type == 'o' && ft_strchr(el->flags, '#')) && ft_fix_zero(el))
		return ;
	conv = (el->type == 'o') ? ft_itoa_base(data->ju, 8) :
	ft_itoa_base(data->llu, 16);
	n = ft_strlen(conv);
	while (el->type == 'X' && n--)
		conv[n] = ft_toupper(conv[n]);
	n = ft_strlen(conv);
	size = (n > el->precision) ? el->width - n : el->width - el->precision;
	size = ft_prepare_int_spec2(el, data, n, size);
	g_printed += ft_putstr(conv);
	while (size-- > 0 && ++g_printed)
		ft_putchar(' ');
	free(conv);
}

void	ft_get_type_int_spec(t_elem *el, va_list *args)
{
	t_data data;

	data.llu = 0;
	if (el->length == '\0')
		data.llu = (unsigned int)va_arg(*args, unsigned int);
	else if (el->length == 'H')
		data.llu = (unsigned char)va_arg(*args, unsigned int);
	else if (el->length == 'h')
		data.llu = (unsigned short)va_arg(*args, unsigned int);
	else if (el->length == 'l')
		data.llu = (unsigned long)va_arg(*args, unsigned long int);
	else if (el->length == 'L')
		data.llu = (unsigned long long)va_arg(*args, unsigned long long int);
	else if (el->length == 'j')
		data.llu = (uintmax_t)va_arg(*args, uintmax_t);
	else if (el->length == 'z')
		data.llu = (size_t)va_arg(*args, size_t);
	else if (el->length == 't')
		data.llu = (ptrdiff_t)va_arg(*args, ptrdiff_t);
	else
		return ;
	if (el->type == 'u')
		ft_prepare_uint(el, &data);
	else
		ft_prepare_int_spec(el, &data);
}
