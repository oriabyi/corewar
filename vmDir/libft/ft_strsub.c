/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:32:34 by ariabyi           #+#    #+#             */
/*   Updated: 2018/03/10 18:08:24 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	j;

	j = 0;
	if (!s)
		return (NULL);
	dest = ft_strnew(len);
	while (s[start] && j < len)
		dest[j++] = s[start++];
	dest[j] = '\0';
	return (dest);
}
