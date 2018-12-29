/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_char_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 19:24:16 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/28 19:24:17 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void				free_char_matrix(char **str)
{
	int				counter;

	counter = 0;
	if (!str)
		return ;
	while (str[counter])
		free(str[counter++]);
	free(str);
}
