/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:44:06 by ariabyi           #+#    #+#             */
/*   Updated: 2017/11/24 18:16:14 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*dest;
	unsigned long	counter;

	if (!s || !f)
		return (NULL);
	if (!(dest = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	counter = -1;
	while (s[++counter] != '\0')
		dest[counter] = f(s[counter]);
	dest[counter] = '\0';
	return (dest);
}
