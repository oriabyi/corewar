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

static char	*ft_contain_op(char *str)
{
	int i;
	char *name;

	i = -1;
	name = 0;
	while (g_op_tab[++i].name != 0)
		if (ft_strstr(str, g_op_tab[i].name) == str)
			name = (ft_strlen(name) > ft_strlen(g_op_tab[i].name)) ? name :
				g_op_tab[i].name;
	return (name);
}

char **ft_arrsplit(char **arr, char *std)
{
	char	*p;
	char	**new;

	if (!arr || ft_strlen(arr[0]) == ft_strlen(std))
		return (arr);
	new = (char **)malloc(sizeof(char *) * 2);
	new[0] = ft_strdup(std);
	new[1] = NULL;
	p = arr[0];
	arr[0] = ft_strsub(arr[0], ft_strlen(std),
		ft_strlen(arr[0]) - ft_strlen(std));
	ft_free_line(&p);
	arr = ft_arrjoin_del(new, arr);
	return (arr);
}

char	**ft_continue_split(char **arr)
{
	if (arr && arr[0] && ft_strcmp(arr[0], NAME_CMD_STRING)
	&& ft_strcmp(arr[0], COMMENT_CMD_STRING) && !ft_is_label(arr[0])
	&& ft_strcmp(arr[0], ft_contain_op(arr[0])))
	{
		if (ft_strstr(arr[0], NAME_CMD_STRING) == arr[0])
			arr = ft_arrsplit(arr, NAME_CMD_STRING);
		else if (ft_strstr(arr[0], COMMENT_CMD_STRING) == arr[0])
			arr = ft_arrsplit(arr, COMMENT_CMD_STRING);
		else if (ft_contain_op(arr[0]))
			arr = ft_arrsplit(arr, ft_contain_op(arr[0]));
	}
	return (arr);
}