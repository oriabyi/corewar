/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 13:18:51 by ariabyi           #+#    #+#             */
/*   Updated: 2018/12/23 13:19:22 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			count_chars(const char *string, char letter,
								int in_row, int position)
{
	int		count_letters;

	count_letters = 0;
	if (string == NULL || *string == '\0')
		return (0);
	while (string[position])
	{
		if (string[position] == letter)
			count_letters++;
		else if (in_row == 1)
			break ;
		position++;
	}
	return (count_letters);
}
