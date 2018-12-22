/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 02:21:18 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/11 02:21:22 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_getflags(char **s, t_elem **el)
{
	char i;

	i = 0;
	while (ft_is_flag(**s))
	{
		((*el)->flags)[(int)i++] = **s;
		(*s)++;
	}
}

void	ft_getwidth(char **s, t_elem **el, va_list *args)
{
	(*el)->width = ft_atoi(*s);
	if (ft_isdigit(**s))
		(*s) = (*s) + ft_nlen((*el)->width);
	else if (**s == '*')
	{
		(*el)->width = va_arg(*args, int);
		(*s)++;
	}
	while (ft_isdigit(**s))
		(*s)++;
}

void	ft_getprecision(char **s, t_elem **el, va_list *args)
{
	(*el)->precision = ft_atoi(*s);
	(*el)->flags[ft_strlen((*el)->flags)] = '.';
	if (ft_isdigit(**s))
		(*s) = (*s) + ft_nlen((*el)->precision);
	else if (**s == '*')
	{
		(*el)->precision = va_arg(*args, int);
		(*s)++;
	}
	while (ft_isdigit(**s))
		(*s)++;
}

void	ft_getlength(char **s, t_elem **el)
{
	if (*(*s + 1) != 'l' && *(*s + 1) != 'h')
		(*el)->length = **s;
	else
	{
		(*s)++;
		if (**s == 'l')
			(*el)->length = 'L';
		else
			(*el)->length = 'H';
	}
	(*s)++;
}

void	ft_gettype(char **s, t_elem *el)
{
	if (ft_isprint(**s))
	{
		el->type = **s;
		(*s)++;
	}
}
