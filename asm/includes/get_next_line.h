/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:25:51 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/03 16:25:55 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

# define IF_C(x) {if (x) {return (-1);}}

# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/syslimits.h>

int		get_next_line(const int fd, char **line);

#endif
