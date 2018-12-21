/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 16:12:46 by akondaur          #+#    #+#             */
/*   Updated: 2018/10/24 16:12:49 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c < -1)
		return (c);
	if (c > 255)
		return (c);
	if ((unsigned char)c >= 'a' && (unsigned char)c <= 'z')
		return (c - 'a' + 'A');
	return (c);
}
