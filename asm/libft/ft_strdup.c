/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:57:05 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/03 16:18:08 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*str;

	i = 0;
	while (src && src[i])
		i++;
	if (!(str = (char *)malloc(sizeof(char) * ++i)))
		return (NULL);
	i--;
	str[i] = '\0';
	while (--i >= 0)
		str[i] = src[i];
	return (str);
}
