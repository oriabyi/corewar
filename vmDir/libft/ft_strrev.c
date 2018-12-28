/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 13:38:19 by ariabyi           #+#    #+#             */
/*   Updated: 2017/11/27 15:51:34 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char const *str)
{
	char	*dst;
	int		length;
	int		i;

	i = 0;
	length = ft_strlen(str) + 1;
	if (!str)
		return (0);
	if (!(dst = (char*)malloc(sizeof(char) * (length))))
		return (0);
	length -= 1;
	while (--length >= 0)
		dst[i++] = str[length];
	dst[i] = '\0';
	return (dst);
}
