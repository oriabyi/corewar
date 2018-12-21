/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:25:19 by akondaur          #+#    #+#             */
/*   Updated: 2018/10/24 15:02:32 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char *p;

	p = s1;
	while (*p)
		p++;
	ft_memcpy(p, s2, sizeof(char) * ft_strlen(s2));
	*(p + sizeof(char) * ft_strlen(s2)) = '\0';
	return (s1);
}
