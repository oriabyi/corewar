/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 16:12:37 by akondaur          #+#    #+#             */
/*   Updated: 2018/10/24 16:12:39 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c < -1)
		return (c);
	if (c > 255)
		return (c);
	if ((unsigned char)c >= 'A' && (unsigned char)c <= 'Z')
		return (c - 'A' + 'a');
	return (c);
}
