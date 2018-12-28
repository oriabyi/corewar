/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mstrfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <ariabyi@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 20:05:00 by ariabyi           #+#    #+#             */
/*   Updated: 2018/03/06 20:05:00 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_multjoin(int field, ...)
{
	va_list		ap;
	char		*dest;
	char		*fin;
	char		*ret;

	va_start(ap, field);
	fin = NULL;
	dest = NULL;
	while (field--)
	{
		dest = ft_strjoin(fin, va_arg(ap, char *));
		free(fin);
		fin = ft_strdup(dest);
		free(dest);
		dest = NULL;
	}
	va_end(ap);
	ret = ft_strdup(fin);
	free(fin);
	free(dest);
	return (ret);
}
