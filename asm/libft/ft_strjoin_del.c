/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_del.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 14:49:05 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/22 14:49:09 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_del(char *s1, char *s2)
{
	char *str;

	str = ft_strjoin(s1, s2);
	ft_free_line(&s1);
	ft_free_line(&s2);
	return (str);
}
