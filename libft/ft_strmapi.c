/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:44:06 by ariabyi           #+#    #+#             */
/*   Updated: 2017/11/24 16:22:38 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dest;
	unsigned long	counter;

	if (!s || !f)
		return (NULL);
	dest = ft_strnew(ft_strlen(s));
	if (!dest)
		return (NULL);
	counter = -1;
	while (s[++counter] != '\0')
		dest[counter] = f(counter, s[counter]);
	return (dest);
}
