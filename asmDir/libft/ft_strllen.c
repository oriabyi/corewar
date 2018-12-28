/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strllen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 02:21:33 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/11 02:21:38 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strllen(const wchar_t *str)
{
	int		i;
	wchar_t	*c;

	i = 0;
	c = (wchar_t *)str;
	while (*c)
	{
		if (*c < 128)
			i++;
		else if (*c < 2048)
			i += 2;
		else if (*c < 65535)
			i += 3;
		else
			i += 4;
		c++;
	}
	return (i);
}
