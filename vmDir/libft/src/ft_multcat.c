/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:34:27 by ariabyi           #+#    #+#             */
/*   Updated: 2018/12/14 14:34:28 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char			*ft_multcat(int field, char *dest, ...)
{
	char		*temp;
	unsigned	i;
	va_list		ap;

	i = 0;
	va_start(ap, dest);
	while (dest[i] != '\0')
		i++;
	while (field--)
	{
		temp = va_arg(ap, char *);
		while (*temp)
		{
			dest[i++] = *temp;
			temp++;
		}
	}
	return (dest);
}
