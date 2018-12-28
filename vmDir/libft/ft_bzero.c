/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:02:23 by ariabyi           #+#    #+#             */
/*   Updated: 2018/02/08 18:05:54 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_bzero(void *memptr, size_t num)
{
	char	*temp;
	int		i;

	i = 0;
	if (num == 0)
		return ;
	temp = (char *)memptr;
	while (num-- != 0)
		temp[i++] = '\0';
}
