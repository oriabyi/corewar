/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:30:11 by ariabyi           #+#    #+#             */
/*   Updated: 2018/02/22 15:46:00 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

short int			ft_pwrbase(ssize_t num, int base)
{
	short int		counter;

	base = (!base) ? 10 : base;
	counter = 1;
	if (num < 0 || base < 0)
		counter++;
	if (num == base && base < 10)
		return (counter);
	while ((num /= base))
		counter++;
	return (counter);
}
