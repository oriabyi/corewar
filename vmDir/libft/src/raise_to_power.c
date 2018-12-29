/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raise_to_power.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 10:12:15 by ariabyi           #+#    #+#             */
/*   Updated: 2018/11/23 10:12:45 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int					raise_to_power(int num, int power)
{
	int				result;

	if (power <= 0)
		return (1);
	else if (num == 0)
		return (0);
	result = num;
	while (--power)
		result *= num;
	return (result);
}
