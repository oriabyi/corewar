/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num_in_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:39:13 by ariabyi           #+#    #+#             */
/*   Updated: 2018/11/27 14:39:17 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	get_num_in_hex(int num)
{
	if (num < 9 || num > 15)
		return ('\0');
	if (num == 10)
		return ('a');
	else if (num == 11)
		return ('b');
	else if (num == 12)
		return ('c');
	else if (num == 13)
		return ('d');
	else if (num == 14)
		return ('e');
	else if (num == 15)
		return ('f');
	return ('\0');
}
