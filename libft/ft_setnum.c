/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:48:51 by ariabyi           #+#    #+#             */
/*   Updated: 2018/06/02 13:49:00 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_setnum(void **arr, int len, int num)
{
	int		counter;
	int		*temp;

	temp = (int *)(*arr);
	counter = 0;
	while (len--)
		temp[counter++] = num;
}
