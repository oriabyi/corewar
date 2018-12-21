/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 09:14:07 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/11 02:19:01 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_elem	el;

	va_start(args, format);
	g_printed = 0;
	ft_getcomnd(format, &el, &args);
	va_end(args);
	return (g_printed);
}
