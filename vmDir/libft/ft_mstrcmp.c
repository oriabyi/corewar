/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mstrcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <ariabyi@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 12:33:00 by ariabyi           #+#    #+#             */
/*   Updated: 2018/03/10 18:12:11 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int				ft_mstrcmp(int field, ...)
{
	int			r;
	char		*m;
	va_list		app;

	r = 0;
	va_start(app, field);
	m = va_arg(app, char *);
	while (--field)
	{
		r += ft_strcmp(m, va_arg(app, char *));
		if (r)
			r = 0;
		else
			return (0);
	}
	va_end(app);
	return (1);
}
