/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 02:23:03 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/11 02:23:07 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_prepare_flags_int(t_elem *el, t_data *data)
{
	int n;

	n = ft_nlen((*data).ji);
	if (ft_strchr(el->flags, '+') && (*data).ji >= 0 &&
		(el->type != 'u') && ++g_printed != -7)
		ft_putchar('+');
	else if (ft_strchr(el->flags, ' ') && (*data).ji >= 0 &&
		(el->type != 'u') && ++g_printed != -7)
		ft_putchar(' ');
	else if ((*data).ji < 0 && (el->type != 'u') && ++g_printed != -7)
		ft_putchar('-');
}

long long	ft_mod(signed long long a)
{
	if (a == LLONG_MIN)
		return (a);
	return ((a > 0) ? a : -a);
}

void		ft_fix_old_style(t_elem *el)
{
	if (el->type == 'D' || el->type == 'O' || el->type == 'U'
		|| el->type == 'S' || el->type == 'C')
	{
		el->type = ft_tolower(el->type);
		el->length = 'l';
	}
	if ((ft_strchr(el->flags, '-') || el->precision) &&
		ft_strchr(el->flags, '0') && el->type != 'p' && el->type != '%'
		&& el->type != 'c' && el->type != 's' && el->type != '\0')
		*ft_strchr(el->flags, '0') = '.';
}

void		ft_try_print(t_elem *el, va_list *args)
{
	ft_fix_old_style(el);
	if (el->type == 'd' || el->type == 'i')
		ft_get_type_int(el, args);
	else if (el->type == 'u' || el->type == 'o' ||
		el->type == 'x' || el->type == 'X')
		ft_get_type_int_spec(el, args);
	else if (el->type == '%')
		ft_get_sign(el);
	else if (el->type == 'c')
		ft_get_type_chr(el, args);
	else if (el->type == 's')
		ft_get_type_str(el, args);
	else if (el->type == 'p')
		ft_get_type_ptr(el, args);
	else if (el->type != '\0')
		ft_get_undef_type(el);
}

void		ft_getcomnd(const char *format, t_elem *el, va_list *args)
{
	char	*s;
	char	*p;

	s = (char *)format;
	while (s && *s)
	{
		p = s;
		if (!(s = ft_putcstr(s, '%')))
			break ;
		s++;
		ft_init(&el);
		ft_getflags(&s, &el);
		ft_getwidth(&s, &el, args);
		if (*s == '.')
		{
			s++;
			ft_getprecision(&s, &el, args);
		}
		if (ft_is_length(*s))
			ft_getlength(&s, &el);
		ft_gettype(&s, el);
		ft_try_print(el, args);
		if (el)
			free(el);
	}
}
