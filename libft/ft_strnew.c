/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:39:27 by ariabyi           #+#    #+#             */
/*   Updated: 2018/03/24 15:22:52 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*r;

	if (!(r = (char *)malloc(sizeof(*r) * (size + 1))))
		return (NULL);
	return (ft_memset(r, 0, size + 1));
}
