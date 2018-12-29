/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_char_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 19:26:38 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/28 19:26:39 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char			**int_to_char_hex(size_t num, size_t len)
{
	char		**split;
	char		*byte;
	unsigned	i;

	i = 0;
	if (!(split = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	byte = get_hex_by_int_byte(num, (len * 2));
	while (i < len)
	{
		split[i] = ft_strsub(byte, i * 2, 2);
		i++;
	}
	split[i] = NULL;
	free(byte);
	return (split);
}
