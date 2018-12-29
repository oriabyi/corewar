/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_got_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 13:26:33 by ariabyi           #+#    #+#             */
/*   Updated: 2018/12/23 13:29:20 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		check_got_num(char *string, ssize_t num, int precision)
{
	if (precision == 1)
	{
		if (ft_pwrbase(num, 10) != (short)(ft_strlen(string)
			- count_chars(string, '0', 1, 0)))
			return (1);
	}
	else
	{
		if (ft_pwrbase(num, 10) != (short)ft_strlen(string))
			return (1);
	}
	return (0);
}
