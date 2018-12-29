/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:40:31 by ariabyi           #+#    #+#             */
/*   Updated: 2018/12/13 15:40:42 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char			*append_char(char **s, char c)
{
	char			*temp;
	size_t			len;

	if (!*s)
	{
		temp = ft_memalloc(2);
		temp[0] = c;
		temp[1] = '\0';
		return (temp);
	}
	len = ft_strlen(*s);
	temp = ft_memalloc(len + 2);
	ft_strcpy(temp, *s);
	temp[len] = c;
	temp[len + 1] = '\0';
	free(*s);
	*s = NULL;
	return (temp);
}
