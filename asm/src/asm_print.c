/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 14:42:14 by akondaur          #+#    #+#             */
/*   Updated: 2018/12/22 14:42:16 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_print_int(int fd, int n)
{
	char	*res;

	res = (char *)ft_strnew(4);
	res[0] = (n >> 24) & 255;
	res[1] = (n >> 16) & 255;
	res[2] = (n >> 8) & 255;
	res[3] = n & 255;
	write(fd, res, 4);
	ft_free_line(&res);
}

void	ft_print_sequence(int fd, char *str, int size)
{
	if (str && *str)
		write(fd, str, ft_strlen(str));
	size = (str && *str) ? size - (int)ft_strlen(str) : size;
	while (size--)
		write(fd, "\0", 1);
}

void	ft_print_header(char *file, t_asm *glob)
{
	int		fd;
	char	*new_file;

	file[ft_strlen(file) - 2] = '\0';
	new_file = ft_strjoin(file, ".cor");
	if ((fd = open(new_file, O_WRONLY | O_CREAT, 0666)) != -1)
	{
		ft_print_int(fd, COREWAR_EXEC_MAGIC);
		ft_print_sequence(fd, glob->name, PROG_NAME_LENGTH);
		ft_print_sequence(fd, NULL, 4);
		ft_print_int(fd, glob->cur + 1);
		ft_print_sequence(fd, glob->comment, COMMENT_LENGTH);
		ft_print_sequence(fd, NULL, 4);
		write(fd, glob->commands, glob->cur + 1);
		ft_printf("Writing output program to %s.cor\n", file);
	}
	else
		ft_put_error(1, NULL);
	ft_free_line(&new_file);
	close(fd);
}
