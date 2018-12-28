/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:10:30 by ariabyi           #+#    #+#             */
/*   Updated: 2017/11/27 13:51:33 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printbits(unsigned long long num)
{
	if (num < 2)
		ft_putchar(num == 0 ? '0' : '1');
	else
	{
		ft_printbits(num / 2);
		ft_printbits(num % 2);
	}
}
