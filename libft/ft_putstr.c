/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:46:16 by ariabyi           #+#    #+#             */
/*   Updated: 2018/02/08 18:07:29 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_putstr(char const *s)
{
	size_t	counter;

	counter = ft_strlen(s);
	if (s && *s)
		write(1, s, ft_strlen(s));
	return (counter);
}
