/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 23:20:34 by akondaur          #+#    #+#             */
/*   Updated: 2018/11/21 23:21:57 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		gnl(int fd, char **line)
{
	char buf;

	*line = (char *)malloc(6);
	ft_bzero(*line, 6);
	while ((read(fd, &buf, 1)) > 0 && ft_strlen(*line) < 6)
		if (buf == '\n')
			break ;
		else
			(*line)[ft_strlen(*line)] = buf;
	if (*line && **line)
		return (1);
	else
		return (0);
}
