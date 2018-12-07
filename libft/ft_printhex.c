/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:00:42 by ariabyi           #+#    #+#             */
/*   Updated: 2018/02/08 18:11:51 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_printhex(size_t num, int base, int counter, char x)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (x == 'X')
		hex = "0123456789ABCDEF";
	if (num >= (size_t)base)
		counter += ft_printhex(num / base, base, counter, x);
	counter += ft_putchar(hex[num % base]);
	return (counter);
}
