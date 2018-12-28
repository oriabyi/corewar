/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multjoinfr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 16:30:54 by ariabyi           #+#    #+#             */
/*   Updated: 2018/11/01 16:31:02 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_multjoinfr(int field, ...)
{
	va_list		ap;
	char		*dest;
	char		*fin;
	char		*temp;
	int			i;

	i = 0;
	va_start(ap, field);
	fin = NULL;
	while (field--)
	{
		temp = va_arg(ap, char *);
		if (!i && (i = temp ? 0 : 1) == 1)
			continue ;
		dest = ft_strjoin(fin, temp);
		free(fin);
		fin = ft_strdup(dest);
		ft_strdel(&dest);
		i ? free(temp) : 0;
		i = 0;
	}
	va_end(ap);
	dest = ft_strdup(fin);
	free(fin);
	return (dest);
}
