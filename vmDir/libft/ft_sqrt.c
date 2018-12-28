/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:48:46 by ariabyi           #+#    #+#             */
/*   Updated: 2017/12/04 12:02:27 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(unsigned int num)
{
	long i;

	i = 0;
	while (num > i * i)
		i++;
	if (num && num / i == i)
		return (i);
	return (-1);
}
