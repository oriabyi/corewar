/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswsps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 15:33:17 by ariabyi           #+#    #+#             */
/*   Updated: 2018/05/02 15:33:18 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_iswsps(const char *str)
{
	size_t x;

	x = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str != ' ' && *str != '\t')
			x++;
		str++;
	}
	return (x == ft_strlen(str));
}
